#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> V[N];

int main()
{
    int n, e;
    cin >> n >> e;


    while(e--)
    {
        int a, b;
        cin >> a >> b;
        V[a].push_back(b);
        V[b].push_back(a);
    }

    int q;
    cin >> q;

    while (q--)
    {
        int x;
        cin >> x;

        vector<int> connected_nodes;

        for (int node : V[x])
        {
            connected_nodes.push_back(node);
        }

        sort(connected_nodes.begin(), connected_nodes.end(), greater<int>());

        if (connected_nodes.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            for (int final_sob_node : connected_nodes)
            {
                cout << final_sob_node << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
