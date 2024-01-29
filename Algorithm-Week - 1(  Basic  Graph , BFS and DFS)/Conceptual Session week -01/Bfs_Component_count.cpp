#include <bits/stdc++.h>
using namespace std;

const int N = 101;
vector<int> adj[N];
bool visited[N];

int  bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    int count = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        count++;
        for (int child : adj[parent])
        {
            if (visited[child] == false)
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
    return count;
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
            int sz = bfs(i);
            if (sz > 1)
                count++;
        }
    }
    cout << "Component Here:-" << count << endl;
    return 0;
}