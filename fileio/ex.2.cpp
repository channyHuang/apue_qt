#include <unistd.h>
#include <iostream>
using namespace std;

//如果fd==fd2, 直接返回fd2
//dup(fd)直到返回值>=fd2，并记录此中所有的返回值
//close掉fd2，dup(fd)，此时返回的应该是最小可用fd即fd2
//close掉前面dup的

int mydup2(int fd, int fd2) {
    int dups[256];
    if (fd2 < 0 || fd2 > OPEN_MAX) {
        cout << "handle error " << fd2 << endl;
        return -1;
    }
    if (fd == fd2) {
        return fd2;
    }
    int i = 0, t = 0;
    while ((t = dup(fd)) < fd2) {
        if (t < 0) {
            cout << "dup error" << endl;
            return -1;
        }
        dups[i++] = t;
    }

    if (close(fd2) != 0) {
        cout << "close fd2 error" << endl;
        return -1;
    }

    t = dup(fd);
    if (t < 0) {
        cout << "dup error" << endl;
        return -1;
    }

    while (i) {
        close(dups[i--]);
    }

    return t;
}

int main(int argc, char* argv[]) {
    return 0;
}
