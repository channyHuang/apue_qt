#include <iostream>
using namespace std;

#include <QCoreApplication>
#include <QProcess>

int main() {
    //not work
    QProcess proc;
    cout << "hello world from process ID " << proc.processId() << endl;

    return 0;
}
