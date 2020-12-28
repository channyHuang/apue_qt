#include <unistd.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

int main(void)
{
    char buf1[] = "abcdefghij";
    char buf2[] = "ABCDEFGHIJ";

    int fd;
    if ((fd = creat("file.hole", (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH))) < 0) {
        cout << "create error" << endl;
        return 0;
    }
    if (write(fd, buf1, 10) != 10) {
        cout << "write error" << endl;
        return 0;
    }
    if (lseek(fd, 16384, SEEK_SET) == -1) {
        cout << "can't seek" << endl;
        return 0;
    }
    if (write(fd, buf2, 10) != 10) {
        cout << "write error" << endl;
    }

    return 0;
}
