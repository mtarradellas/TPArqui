#ifndef SYSCDispatcher_H_
#define SYSCDispatcher_H_

#define READ 0
#define WRITE 1

#define KEY 0
#define TIME 1

#define CHARACTER 0
#define DRAWCHR 1
#define CLEAR 2
#define PAINT 3

#define HOUR 0
#define MINUTE 1
#define SECOND 2

void syscallDispatcher(uint64_t syscall, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5);
void read(uint64_t mode, uint64_t dest, uint64_t time);
void write(uint64_t mode, char * c, Color * color, uint64_t p3, uint64_t p4);
void getTime(unsigned int * dest, uint64_t time);

#endif
