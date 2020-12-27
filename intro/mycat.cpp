#define BUFFSIZE 4096

#include <unistd.h>
#include <iostream>
using namespace std;

int main(void) {
    int n;
    char buf[BUFFSIZE];

    while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n) {
            cout << "write error" << endl;
            return 0;
        }
    }

    if (n < 0) {
        cout << "read error" << endl;
    }

    return 0;
}

//./intro < infile > outfile
