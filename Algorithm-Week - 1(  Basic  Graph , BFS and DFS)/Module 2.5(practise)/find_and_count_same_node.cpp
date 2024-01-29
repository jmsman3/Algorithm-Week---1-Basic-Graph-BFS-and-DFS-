#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> V[N];
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

    int nd;
    cin >> nd;
    int cnt = 0;
    vector<int> all_val;

    for (int child : V[nd])
    {
        all_val.push_back(child);
        cnt++;
    }

    cout << cnt << " ";
    return 0;
}

void dfs(int src, vector<int> adj[])

{
    vis[src] = true;
    result.push_back(src);
    for (int child : adj[src])
    {
        if (vis[child] == false)
        {
            dfs(child, adj);
        }
    }
}
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here

    memset(vis, false, sizeof(vis));
    result.clear();
    dfs(0, adj);
    return result;
}