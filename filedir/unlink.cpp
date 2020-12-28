#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
using namespace std;

#include <QFile>

int main(void) {
    if (open("tempfile", O_RDWR) < 0) {
        cout << "open error " << errno << endl;
        return 0;
    }
    if (unlink("tempfile") < 0) {
        cout << "unlink error " << errno << endl;
        return 0;
    }
    cout << "file unlink" << endl;
    sleep(15);
    cout << "done" << endl;

    QFile file("tempfile");

    return 0;
}
