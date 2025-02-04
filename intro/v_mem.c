#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


int main(int argc, char *argv[]){
	int *p = malloc(sizeof(int));
	assert(p != NULL); // Macro for sanity check, terminates program if false.
	printf("(%d) addrof p: %08x\n", getpid(), (unsigned) p);
	*p = 0;
	while (1){
		sleep(2);
		*p = *p + 1;
		// process identifier (the PID) of the running program.
		// This PID is unique per running process.
		printf("(%d) p: %d\n",getpid(), *p);
	}
	return 0;
}
/*
 * Run the following command for demo of address space creation by the OS
 * 1. Create executable file: gcc v_mem.c -o mem
 * 2. test out mem
 * 3. run multiple mem to see virtualisation in action!
 * */

// NOTE: ASLR radomises the addr space so turn it off to test it.\
// Disable: echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
// Enable : echo 2 | sudo tee /proc/sys/kernel/randomize_va_space 
