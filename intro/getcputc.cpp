#include <iostream>
using namespace std;

int main(void) {
    int c;
    while ((c = getc(stdin)) != EOF) {
        if (putc(c, stdout) == EOF) {
            cout << "output error" << endl;
            return 0;
        }
    }

    if (ferror(stdin)) {
        cout << "input error" << endl;
    }

    return 0;
}
