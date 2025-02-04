// For is used to CREATE new process
// Unlike Threads created by process this will have seperate addr space
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[]) {
	printf("hello world (pid:%d)\n", (int) getpid());
	// New process is created with instruction copy after fork() with only one difference 
	// rc will be 0 in child and will be PID for parent aka origianl. 
	int rc = fork();
	if (rc < 0) { // Fork failed
		fprintf(stderr, "fork failed\n");
		exit(1);
	} else if (rc == 0) { // new process created.
		printf("hello I'm the new process! (pid:%d)\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc"); // program: "wc"
		myargs[1] = strdup("p3.c"); // program: "wc"
		myargs[2] = NULL; // program: "wc"
		execvp(myargs[0], myargs); 
	} else { // Original process goes here
		int wc = wait(NULL); // Creates deterministic result.
		// with wait(), the parent process will wait until the child process ends!
		printf("hello this is parent process of %d. (pid:%d) (wc:%d)\n", wc, rc, (int) getpid());
	}
	return 0;
}
