#include <iostream>
using namespace std;
#include <QFile>

int main(void)
{
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    QFile file("file.hole");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Truncate) ) {
        cout << "create error" << endl;
        return 0;
    }
    if (file.write(buf1, 10) != 10) {
        cout << "write error" << endl;
        return 0;
    }
    if (file.seek(16384) == -1) {
        cout << "can't seek" << endl;
        return 0;
    }
    if (file.write(buf2, 10) != 10) {
        cout << "write error" << endl;
    }
    file.close();

    return 0;
}
