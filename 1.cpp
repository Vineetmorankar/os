#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main()
{
    pid_t child_pid;
    int status;

    // Fork to create a child process
    child_pid = fork();

    if (child_pid == -1)
    {
        // Error handling if fork fails
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        // Child process
        // Execute cp command
        cout << "Child process (cp) PID: " << getpid() << endl;
        execlp("cp", "cp", "source", "dest", nullptr);

        // If exec fails
        perror("exec");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        // Wait for the child process to finish
        wait(&status);
        cout << "Parent process PID: " << getpid() << endl;
        cout << "cp command executed successfully" << endl;
    }

    // Fork again to create another child process
    child_pid = fork();

    if (child_pid == -1)
    {
        // Error handling if fork fails
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (child_pid == 0)
    {
        // Child process
        // Execute grep command
        cout << "Child process (grep) PID: " << getpid() << endl;
        execlp("grep", "grep", "keyword", "dest", nullptr);

        // If exec fails
        perror("exec");
        exit(EXIT_FAILURE);
    }
    else
    {
        // Parent process
        // Wait for the child process to finish
        wait(&status);
        cout << "Parent process PID: " << getpid() << endl;
        cout << "grep command executed successfully" << endl;
    }

    return 0;
}
