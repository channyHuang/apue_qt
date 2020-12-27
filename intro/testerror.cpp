#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << stderr << "EACCES: " << strerror(EACCES) << endl;
    errno = ENOENT;
    perror(argv[0]);
    return 0;
}
