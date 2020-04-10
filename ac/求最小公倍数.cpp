#include <iostream>

using namespace std;

int main()
{
    int m, n, i;
    cin >> m >> n;
    for (i = m;; i++)
    {
        if (i%m == 0 && i%n == 0)
            break;
    }
    cout << i;
}