#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;

int main(void) {
    umask(0);
    if (creat("foo", (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0) {
        cout << "creat error for foo" << endl;
        return 0;
    }
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)) < 0) {
        cout << "creat error for bar" << endl;
        return 0;
    }

    return 0;
}
