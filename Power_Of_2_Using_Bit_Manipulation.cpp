#include <iostream>

using namespace std;

bool isPowerOf2(int n)
{
    return (n && !(n & n - 1));
}

int main()
{
    int x;
    cin >> x;
    cout << isPowerOf2(x) << endl;
    return 0;
}