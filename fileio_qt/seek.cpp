#include <QTextStream>
#include <QFile>
#include <iostream>
using namespace std;

int main(void)
{
    QTextStream stream(stdin);
    int pos = stream.pos();
    bool bRes = stream.seek(0);

    if (!bRes) {
        cout << "can't seek" << endl;
    } else {
        cout << "seek success" << endl;
    }

    return 0;
}
