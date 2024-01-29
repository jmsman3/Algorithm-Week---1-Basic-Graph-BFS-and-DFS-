#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> V[N];
bool vis[N];
int level[N];

void bfs(int src, int &number_of_nodes)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    number_of_nodes = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        number_of_nodes++;
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

    vector<int> component_nodes_number;
    int component = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            int number_of_nodes;
            bfs(i, number_of_nodes);
            component_nodes_number.push_back(number_of_nodes);
            component++;
        }
    }

    sort(component_nodes_number.begin(), component_nodes_number.end());

    for (int result : component_nodes_number)
    {
        cout << result << " ";
    }

    return 0;
}
