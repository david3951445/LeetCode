#include <iostream>
using namespace std;

union data{
    int a[2];
    char c[8];
};

int main(int argc, char const *argv[])
{
    union data d;

    d.a[0] = 3406;
	d.a[1] = 3404;

    cout << d.c[0] << endl;
    cout << d.c[1] << endl;
    cout << d.c[2] << endl;

    return 0;
}
