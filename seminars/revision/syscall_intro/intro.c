#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>

int main() {
	printf("Hello world!\n");

	// We can call syscalls with wrapper functions in stdlib directly:
	// write(1, "Hello world!\n", 14) -- wrapper function

	syscall(SYS_write, 1, "Hello world!\n", 14);

	// Not all system functions have wrapper in stdlib:
	
	unsigned long long cpu, node;

	syscall(SYS_getcpu, &cpu, &node, NULL);

	printf("This program is running on CPU core %llu and NUMA node %llu\n", cpu, node);
}
