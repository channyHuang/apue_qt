#include <iostream>
#include <unistd.h>
using namespace std;

int main(void) {
    cout << "hello world from process ID " << getpid() << endl;
    cout << "uid = " << getuid() << ", gid = " << getgid() << endl;
    return 0;
}
