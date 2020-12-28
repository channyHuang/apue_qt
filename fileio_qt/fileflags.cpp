#include <iostream>
using namespace std;
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "usage: a.out <descriptor#>" << endl;
        return 0;
    }
    QTextStream stream;

    QFile file(argv[1]);

    QFileInfo fileInfo(file);
    if (fileInfo.isReadable()) {
        cout << "readable" << endl;
    }
    if (fileInfo.isWritable()) {
        cout << "writable" << endl;
    }
    if (fileInfo.isExecutable()) {
        cout << "runnable" << endl;
    }

    return 0;
}
