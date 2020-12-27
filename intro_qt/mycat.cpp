#define BUFFSIZE 4096

#include <QTextStream>
#include <QString>

int mycat() {
    QTextStream in(stdin);
    QTextStream out(stdout);
    QString data;
    while ((data = in.read(BUFFSIZE)) != QString()) {
        out << data;
        out.flush();
    }
    return 0;
}

int main(void) {
    mycat();
    return 0;
}
