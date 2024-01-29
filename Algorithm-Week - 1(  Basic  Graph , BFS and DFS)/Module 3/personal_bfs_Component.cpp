#include <bits/stdc++.h>
using namespace std;

const int N =101;
vector<int> adj[N];
bool visited[N];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : adj[parent])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}
int main()
{
    int node, edge;
    cin >> node >> edge;
    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 0; i <= node; i++)
    {
        if (visited[i] == false)
        {
            bfs(i);
            cnt++;
        }
    }
    cout << "Component Here:-" << cnt << endl;
    return 0;
}