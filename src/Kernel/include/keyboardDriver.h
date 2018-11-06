#define BUFFER_SIZE 256

#define LEFT_SHIFT_SC 42
#define RIGHT_SHIFT_SC 54
#define CAPSLOCK_SC 58
#define LEFT_SHIFT_RELEASE 170
#define RIGHT_SHIFT_RELEASE 182

#define CTRL 0
#define ALT 0
#define UP 0
#define RIGHT 0
#define LEFT 0
#define DOWN 0
#define ESC 0
#define BACKSPACE '\b'
#define TAB '\t'
#define ENTER '\n'
#define LEFT_SHIFT 0
#define RIGHT_SHIFT 0
#define LEFT_ALT 0
#define SPACE ' '
#define CAPSLOCK 0
#define F1 0
#define F2 0
#define F3 0
#define F4 0
#define F5 0
#define F6 0
#define F7 0
#define F8 0
#define F9 0
#define F10 0
#define F11 0
#define F12 0
#define NUM_LOCK 0
#define SCROLL_LOCK 0
#define INSERT 0
#define SUPR 0
#define HOME 0
#define END 0
#define REPAG 0
#define AVPAG 0

unsigned int _getKeyPress();
void keyboardHandler();
void addToBuffer(unsigned char c);
int isNotPressed(unsigned char c);
unsigned char getKey();