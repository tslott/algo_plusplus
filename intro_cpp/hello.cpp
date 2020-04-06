#include <iostream>

using namespace std;

int main()
{
    cout << "Hello... world... Seriously?" << endl;

    int x = 10, y = 20;
    int *px;

    px = &x;

    cout << x << endl;
    cout << &x << endl;
    cout << px << endl;
    cout << *px << endl;

    cout << ++px << endl;

    return 0;
}
