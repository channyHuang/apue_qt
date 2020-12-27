#include <iostream>
using namespace std;

#include <QProcess>

#define MAXLINE 4096

int main(void) {
    char buf[MAXLINE];

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
