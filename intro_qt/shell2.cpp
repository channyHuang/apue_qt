#include <iostream>
#ifdef Q_OS_WIN
#include <signal.h>
#else
#include <unistd.h>
#endif
using namespace std;

#include <QProcess>

#define MAXLINE 4096
static void sig_int(int) {
    cout << "interrupt" << endl << "%% ";
    cout.flush();
}

int main(void) {
    char buf[MAXLINE];

    if (signal(SIGINT, sig_int) == SIG_ERR) {
        cout << "signal error" << endl;
    }

    cout << "%% ";
    while (fgets(buf, MAXLINE, stdin) != nullptr) {
        if (buf[strlen(buf) - 1] == '\n') {
            buf[strlen(buf) - 1] = 0;
        }

        QProcess *proc = new QProcess();
        int res = proc->execute(QString(buf), QStringList());
        proc->waitForFinished();

        if (res != 0) {
            cout << "can't exec " << buf << endl;
        }

        cout << "%% ";
    }

    return 0;
}
