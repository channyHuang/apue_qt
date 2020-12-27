#include <iostream>
#include <unistd.h>
using namespace std;

#define MAXLINE 4096
static void sig_int(int) {
    cout << "interrupt" << endl << "%% ";
    cout.flush();
}

int main(void) {
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        cout << "signal error" << endl;
    }

    cout << "%% ";
    while (fgets(buf, MAXLINE, stdin) != nullptr) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        if ((pid = fork()) < 0) {
            cout << "fork error" << endl;
            return 0;
        } else if (pid == 0) {
            execlp(buf, buf, (char*)0);
            cout << "couldn't execute: " << buf << endl;
            return 127;
        }

        if ((pid = waitpid(pid, &status, 0)) < 0) {
            cout << "waitpid error" << endl;
        }

        cout << "%% ";
    }
    return 0;
}
