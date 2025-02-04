// For is used to CREATE new process
// Unlike Threads created by process this will have seperate addr space
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("hello world (pid:%d)\n", (int) getpid());
	// New process is created with instruction copy after fork() with only one difference 
	// rc will be 0 in child and will be PID for parent aka origianl. 
	int rc = fork();
	if (rc < 0) { // Fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // new process created.
		printf("hello new process! (pid:%d)\n", (int) getpid());
	} else { // Original process goes here
		printf("hello this is parent process of %d. (pid:%d)\n", rc, (int) getpid());
	}
	return 0;
}
