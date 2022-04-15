#include <iostream>

using namespace std;

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << catalan(n);
    return 0;
}