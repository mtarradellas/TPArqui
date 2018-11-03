#include <stdint.h>

#define READ 0
#define WRITE 1

/*	funcion a la que llama la interrupcion 80h de la tabla,
	le mandan como parametro que syscall le pidieron,
	falta definirlas y faltan mas parametros que usarian 
	las sys calls
*/
void syscallDispatcher(uint64_t syscall) {
	switch(syscall) {
		case READ:
			read();
			break;
		case WRITE:
			write();
			break;
	}
}

void read() {
	
}

void write() {

}

