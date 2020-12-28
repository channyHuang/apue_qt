#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
using namespace std;

int main(void) {
    struct stat statbuf;
    if (stat("foo", &statbuf) < 0) {
        cout << "stat error " << errno << endl;
        return 0;
    }
    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0) {
        cout << "chmod error for foo" << errno << endl;
        return 0;
    }
    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) < 0) {
        cout << "chmod error for bar" << errno << endl;
    }
    return 0;
}
