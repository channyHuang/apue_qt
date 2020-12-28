#include <fcntl.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int val;
    if (argc != 2) {
        cout << "usage: a.out <descriptor#>" << endl;
        return 0;
    }
    if ((val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0) {
        cout << "fcntl error for fd " << atoi(argv[1]) << endl;
        return 0;
    }
    switch (val & O_ACCMODE) {
    case O_RDONLY:
        cout << "read only" << endl;
        break;
    case O_WRONLY:
        cout << "write only" << endl;
        break;
    case O_RDWR:
        cout << "read write" << endl;
        break;
    default:
        cout << "unknow access mode" << endl;
    }

    if (val & O_APPEND) {
        cout << "append" << endl;
    }
    if (val & O_NONBLOCK) {
        cout << "nonblocking" << endl;
    }
    if (val & O_SYNC) {
        cout << "synchronous writes" << endl;
    }
    //macOS Catalina, O_FSYNC == O_SYNC
#if !defined (_POSIX_C_SOURCE) && defined (O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC) {
        cout << "synchronous writes" << endl;
    }
#endif
    return 0;
}
