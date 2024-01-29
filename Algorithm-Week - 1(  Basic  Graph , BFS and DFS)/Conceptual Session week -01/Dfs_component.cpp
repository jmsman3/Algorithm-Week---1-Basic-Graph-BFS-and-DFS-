#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> adj[N];
bool visited[N];

int cnt = 0;
void dfs(int src)
{
    cnt++;
    visited[src] = true;
    for (int child : adj[src])
    {
        if (visited[child] == false)
        {
            dfs(child);
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

    int count = 0;
    for (int i = 1; i <= node; i++)
    {
        if (visited[i] == false)
        {
            cnt = 0;
            dfs(i);
            if (cnt > 1)
                count++;
        }
    }
    cout << "Component Here:-" << count << endl;
    return 0;
}