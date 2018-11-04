#ifndef SYSCDispatcher_H_
#define SYSCDispatcher_H_

void syscallDispatcher(uint64_t syscall, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4, uint64_t p5);
void read(uint64_t mode, uint64_t dest);
void write(uint64_t mode, uint64_t p1, uint64_t p2, uint64_t p3, uint64_t p4);
//void getTime(uint64_t dest);
	

#endif
