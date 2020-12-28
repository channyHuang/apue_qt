#include <unistd.h>
#include <iostream>
using namespace std;

int main(void)
{
    if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
        cout << "can't seek" << endl;
    } else {
        cout << "seek success" << endl;
    }

    return 0;
}
