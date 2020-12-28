#include <fcntl.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "usage: a.out <pathname>" << endl;
        return 0;
    }
    int fd;
    if (access(argv[1], R_OK) < 0) {
        cout << "access error " << errno << endl;
        return 0;
    } else {
        cout << "read access OK" << endl;
    }

    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        cout << "open error " << errno << endl;
        return 0;
    } else {
        cout << "open for reading OK" << endl;
        close(fd);
    }

    return 0;
}
