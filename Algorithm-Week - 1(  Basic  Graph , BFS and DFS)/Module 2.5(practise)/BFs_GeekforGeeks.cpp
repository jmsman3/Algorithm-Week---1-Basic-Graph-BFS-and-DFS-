vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> result;
    vector<boo> Visited(V, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        result.push_back(par);
        for (int child : adj[par])
        {
            if (Visited[child] == false)
            {
                q.push(child);
                Visited[child] = true;
            }
        }
    }
}
return result;


//src_to_destination with out pair;-below(practise problem 1)
#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
bool vis[1005];
int level[1005];
// int parent[1005];

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
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
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
        memset(level, -1, sizeof(level));
        // memset(parent, -1, sizeof(parent));

        bfs(src);

        if (level[des] == -1)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << level[des] << endl;
        }
    }

    return 0;
}



//node_at_level-Decending order print kore-

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> V[N];
int level[N];
bool vis[N];

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
            if (!vis[child])
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
    memset(level, -1, sizeof(vis));

    bfs(0); // Start BFS from source node  - according question.

    vector<int> nodesAtLevelL;
    for (int i = 0; i < n; ++i)
    {
        if (level[i] == L)
        {
            nodesAtLevelL.push_back(i);
        }
    }

    sort(nodesAtLevelL.begin(), nodesAtLevelL.end(), greater<int>());
    // Sort in descending order

    for (int node : nodesAtLevelL)
    {
        cout << node << " ";
    }

    return 0;
}

