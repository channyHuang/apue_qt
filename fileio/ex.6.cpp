#include <unistd.h>
#include <iostream>
#include <fcntl.h>
using namespace std;

int main(void)
{
    char buf1[] = "abcdefghijk";
    char buf2[] = "ABCDEFGHIJK";
    char buf3[256];

    int fd;
    if ((fd = open("file.hole", O_CREAT | O_RDWR | O_APPEND) < 0)) {
        cout << "open error " << errno << endl;
        return 0;
    }

    //mac catalina, fd return 0 ???
    cout << "fd = " << fd << endl;

    if (write(fd, buf1, 10) != 10) {
        cout << "write error " << errno << endl;
        return 0;
    }

    if (lseek(fd, 5, SEEK_SET) == -1) {
        cout << "can't seek" << endl;
        return 0;
    }
    if (read(fd, buf3, 10) != 10) {
        cout << "read error " << errno << endl;
        return 0;
    } else {
        cout << buf3 << endl;
    }
    if (write(fd, buf2, 10) != 10) {
        cout << "write error" << endl;
    }
    close(fd);

    return 0;
}
