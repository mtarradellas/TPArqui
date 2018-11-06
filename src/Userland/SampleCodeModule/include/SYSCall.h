#ifndef systemCall_h
#define systemCall_h

#define READ 0
#define WRITE 1

#define KEY 0
#define TIME 1

#define CHARACTER 0
#define STRING 1
#define CLEAR 2
#define PAINT 3

#define HOUR 0
#define MINUTE 1
#define SECOND 2

#define BUFFER_SIZE 256

unsigned int systemCall(uint64_t syscall, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5);

#endif
