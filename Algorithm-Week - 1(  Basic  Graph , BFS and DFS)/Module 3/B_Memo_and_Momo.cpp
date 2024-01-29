#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int a, b, k;
    cin >> a >> b >> k;
    // first condition
    if (a % k == 0 && b % k == 0)
    {
        cout << "Both";
    }
    // second condition
    else if (a % k == 0 && b % k != 0)
    {
        cout << "Memo";
    }
    // third condition
    else if (a % k != 0 && b % k == 0)
    {
        cout << "Momo";
    }
    // 4th condition
    else
    {
        cout << " NO One";
    }
    return 0;
}