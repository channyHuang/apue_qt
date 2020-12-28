#include <sys/stat.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for (i = 1; i < argc; i++) {
        cout << argv[i] << endl;
        if (lstat(argv[i], &buf) < 0) {
            cout << "lstat error " << errno << endl;
            return 0;
        }
        if (S_ISREG(buf.st_mode)) {
            ptr = "regular";
        } else if (S_ISDIR(buf.st_mode)) {
            ptr = "directory";
        } else if (S_ISCHR(buf.st_mode)) {
            ptr = "character special";
        } else if (S_ISBLK(buf.st_mode)) {
            ptr = "block special";
        } else if (S_ISFIFO(buf.st_mode)) {
            ptr = "fifo";
        } else if (S_ISSOCK(buf.st_mode)) {
            ptr = "socket";
        } else {
            ptr = "unknown mode";
        }
        cout << ptr << endl;
    }

    return 0;
}
