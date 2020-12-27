#include <iostream>
using namespace std;

#include <dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        cout << "usage: ls directory_name" << endl;
        return 0;
    }
    if ((dp = opendir(argv[1])) == nullptr) {
        cout << "can't open " << argv[1] << endl;
        return 0;
    }
    while ((dirp = readdir(dp)) != nullptr) {
        cout << dirp->d_name << endl;
    }
    closedir(dp);

    return 0;
}
