
#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];

int bfs(int src, int des)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;
    // bool paisi = false;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int par = p.first;
        int level = p.second;
        if (par == des)
        {
            return level;
        }
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;

        memset(vis, false, sizeof(vis));

        int result = bfs(src, des);

        cout << result << endl;
    }

    return 0;
}
