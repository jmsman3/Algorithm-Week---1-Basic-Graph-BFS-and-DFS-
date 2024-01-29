#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> V[N];
bool vis[N];

// bool direct_path(int curr, int target)
// {
//     if (curr == target)
//     {
//         return true;
//     }
//     vis[curr] = true;
//     for (int child : V[curr])
//     {
//         if (vis[child] == false && direct_path(child, target))
//         {
//             return true;
//         }
//     }
//     return false;
// }

int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n + 2][n + 2];
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        mat[a][b] = 1;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int A, B;
        cin >> A >> B;

        if (mat[A][B] == 1 || A == B)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
