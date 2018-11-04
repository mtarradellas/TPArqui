/*  
	********* VIDEO CONTROL *********
*/

#include "videoDriver.h"
#include "font.h"
#include "naiveConsole.h"

#define CHAR_WIDTH 6
#define CHAR_HEIGHT 8
#define LINE_SPACE 2// SPACE BETWEEN LINES
#define CHAR_SPACE 1// SPACE BETWEEN CHARACTERS

/*
	common colors
*/
Color black = {0, 0, 0};
Color white = {255, 255, 255};
Color blue = {0, 0, 255};
Color green = {0, 255, 0};
Color red = {255, 0, 0};

static vesaModeStruct * videoStruct = (vesaModeStruct*)0x5C00; 	//get the contents for the struct FROM?

//cursor position(coordinates within the screen). Initialized in order to leave a small margin
static int cursor_x = CHAR_SPACE;
static int cursor_y = LINE_SPACE;

//transforms intRGB values to individual R, G and B values and returns a color struct
Color getColor(int intRGB){
	Color color;
	color.blue = intRGB & 255;
	color.green = (intRGB >> 8) & 255;
	color.red = (intRGB >> 16) & 255;
	return color;
}
/*
	plots pixel in the desired coordinates (x, y) and with the color provided

	PORQUE DIVIDE POR 8??????/ SI ES POR LOS CARACTERES, CAMBIAR A 6?? / puse char width, pero ni idea
*/
void plotPixel(int x, int y, Color color){

    unsigned int where = y * videoStruct->pitch + x * (videoStruct->bpp/CHAR_WIDTH);
    unsigned char* screen = ( unsigned char* ) (videoStruct->framebuffer);
    screen[where] = color.blue;
    screen[where + 1] = color.green;  
    screen[where + 2] = color.red;

}


// draws char by pixel acording to  font array located in font.h
void drawChar(char c, int x, int y, Color color) {
    int i,j;

    // Convert the character to an index
    c = c & 0x7F;
    if (c < ' ') {
        c = 0;
    } else {
        c -= ' ';
    }

    // 'font' is a multidimensional array of [96][char_width]
    // which is really just a 1D array of size 96*char_width.
    const unsigned char* chr = font[c*CHAR_WIDTH];	//cambie unit8 por unsignes char

    // Draw pixels
    for (j=0; j<CHAR_WIDTH; j++) {
        for (i=0; i<CHAR_HEIGHT; i++) {

            if (chr[j] & (1<<i)) {
                plotPixel(x+j, y+i, color);	//NECESITO PONER LOS ESPACIOS ENTRE PIXELES?
            }/*
            else{
            	plotPixel(x+j, y+i, black);		necesito depende de la pantalla?
            }*/
        }
    }
}

void printChar(char c, Color color) {
    reAccomodateScreen();	//sets cursor in a valid position in order to print on screen
    if (c == '\n') {
       newLine();
        //cursor_x2 = cursor_x;
        //cursor_y2 = cursor_y;		??????????????
        return;
    } else if (c == '\b') {
        delChar();
        return;
    }
    drawChar(c, cursor_x, cursor_y, color);
    cursor_x += CHAR_WIDTH + CHAR_SPACE;
    reAccomodateScreen();
}
/*
	erases char in current line, if there is none it goes to the previous line
*/
void delChar() {

    cursor_x -= (CHAR_WIDTH + CHAR_SPACE);
    /*if (cursor_x2 > cursor_x) {
        if (cursor_y2 < cursor_y) {
            cursor_x += (CHAR_WIDTH + CHAR_SPACE);	????????//
            return;
        }
    }*/
    reAccomodateScreen(); //corrects cursor if it ended in an invalid position after erasing character
    printChar(' ', black);
    // ?????????????
}

void newLine() {
    cursor_y += CHAR_HEIGHT + LINE_SPACE;
    cursor_x = CHAR_SPACE;
    reAccomodateScreen();
}

/*
	checks if the cursor is out of boundaries and acts accordingly

	scrolls screen up if it has run out of space
*/
void reAccomodateScreen() {
	// checks if the cursor is beyond the width of the screen of if it is where the next character would end up outside
    if ((videoStruct->width - CHAR_SPACE) <= cursor_x || ((videoStruct->width - cursor_x) < (CHAR_WIDTH))) {
        newLine();
    }
    // checks if the cursor is beyond the height of the screen and scrolls
    else if ((videoStruct->height - LINE_SPACE - CHAR_HEIGHT) <= cursor_y) {
        cursor_y -= (CHAR_HEIGHT + LINE_SPACE);
       // moveScreenUp();
    } 
    //minimum height for cursor is the margin (considering height increses downward)
    else if (cursor_y < LINE_SPACE) {
        cursor_y = LINE_SPACE;
    } 
    //if cursor is located further to the left than minumun margin it is re positioned in the previous line
    else if (cursor_x < CHAR_SPACE) {
        if (cursor_y > (LINE_SPACE + CHAR_HEIGHT)) { //cursor is not in the first line
            cursor_y -= (LINE_SPACE + CHAR_HEIGHT);
            cursor_x = (CHAR_SPACE + CHAR_WIDTH)* (videoStruct->width / (CHAR_SPACE + CHAR_WIDTH)) + CHAR_SPACE; //locates the cursor at the end of the line
        } 
        else { //cursor is set at the begining
            cursor_x = CHAR_SPACE; 
        }
    }
}
/*
//corre las lineas hacia arriba excluyendo la ultima
void moveScreenUp() {
    unsigned whereOnScreen = (CHAR_HEIGHT+(2*Y_SPACE))*(video->pitch) + X_SPACE*(video->BitsPerPixel/8);
    char * source = (char *) (video->PhysBasePtr + whereOnScreen);
    unsigned whereOnScreen2 = (Y_SPACE)*(video->pitch) + X_SPACE*(video->BitsPerPixel/8);
    char * dest = (char *) (video->PhysBasePtr + whereOnScreen2);
    int size = (video->YResolution)*(video->XResolution)*3;
    memCpy(dest, source, size);
    for (int y = YPOSITION ; y < video->YResolution; y ++) { //Y_SPACE
        for (int x = X_SPACE; x < video->XResolution-X_SPACE; x++) {
            putPixel(x, y , black);
        }
    }

}*/


