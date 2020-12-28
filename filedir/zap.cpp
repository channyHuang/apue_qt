#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]) {
    int fd;
    struct stat statbuf;
    struct timespec times[2];

    for (int i = 1; i < argc; i++) {
        if (stat(argv[i], &statbuf) < 0) {
            cout << "stat error " << argv[i] << endl;
            continue;
        }
        if ((fd = open(argv[1], O_RDWR | O_TRUNC)) < 0) {
            cout << "open error " << argv[i] << endl;
            continue;
        }

        //st_atim, st_mtim
        times[0] = statbuf.st_atimespec;
        times[1] = statbuf.st_mtimespec;

        if (futimens(fd, times) < 0) {
            cout << "futimens error " << argv[i] << endl;
        }
        close(fd);
    }
    return 0;
}
