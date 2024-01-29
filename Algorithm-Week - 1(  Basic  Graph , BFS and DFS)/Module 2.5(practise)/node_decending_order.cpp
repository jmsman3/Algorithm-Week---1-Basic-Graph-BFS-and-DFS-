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

    int L;
    cin >> L;

    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    
    bfs(0); // according question;

    vector<int> node_at_level;
    for (int i = 0; i < n; i++)
    {
        if (level[i] == L)
        {
            node_at_level.push_back(i);
        }
    }

    sort(node_at_level.begin(), node_at_level.end(), greater<int>());

    for (int node : node_at_level)
    {
        cout << node << " ";
    }

    return 0;
}