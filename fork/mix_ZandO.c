#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    pid_t child_pid = fork();

    if (child_pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (child_pid == 0) {
        // This is the child process
        printf("Child process (PID %d) is running.\n", getpid());
        // Simulate some work in the child process
        sleep(2);
        printf("Child process (PID %d) completed.\n", getpid());
    } else {
        // This is the parent process
        printf("Parent process (PID %d) is running.\n", getpid());
        printf("Parent process (PID %d) created a child (PID %d).\n", getpid(), child_pid);
        // Sleep for a while to let the child process become a zombie
        sleep(5);
        printf("Parent process (PID %d) exiting without waiting for child.\n", getpid());
    }

    return 0;
}
