#include <iostream>
#include <fcntl.h>
using namespace std;

void set_fl(int fd, int flags) {
    int val;
    if ((val = fcntl(fd, F_GETFL, 0)) < 0) {
        cout << "fcntl error for fd " << fd << endl;
        return;
    }
    val |= flags;
    if (fcntl(fd, F_GETFL, 0) < 0 ) {
        cout << "fcntl F_GETFL error" << endl;
    }
    return;
}

int main(void) {
    return 0;
}
