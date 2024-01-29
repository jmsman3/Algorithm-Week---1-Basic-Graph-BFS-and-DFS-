//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <bits/stdc++.h>
class Solution {
  public:
  vector<int> result;
        bool vis[10001];
  
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
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends