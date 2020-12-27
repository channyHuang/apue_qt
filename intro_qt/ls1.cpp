#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

#include <iostream>
using namespace std;

int ls1(char *dirpath) {
    QDir dir(dirpath);
    if (!dir.exists()) {
        cout << "can't open " << dirpath << endl;
        return 0;
    }
    QFileInfoList fileInfoList = dir.entryInfoList(QStringList());
    foreach (QFileInfo info, fileInfoList) {
        //relative path
        cout << info.fileName().toStdString() << endl;
        //absulote path
        //cout << info.filePath().toStdString() << endl;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage: ls directory_name" << endl;
        return 0;
    }
    ls1(argv[1]);
    return 0;
}
