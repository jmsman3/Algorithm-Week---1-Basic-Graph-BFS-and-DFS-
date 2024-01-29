#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> V[N];
bool vis[N];
int level[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : V[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            bfs(i);
            cnt++;
        }
    }
    cout << cnt << " ";

    return 0;
}