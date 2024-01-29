class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        if (image[sr][sc] == color) // Check if the starting pixel already has the target color
        {
            return image; // No changes needed
        }
        dfs(image, sr, sc, image[sr][sc], color); // Perform the flood fill

        return image;
    }

    void dfs(vector<vector<int>> &image, int i, int j, int oldColor, int newColor)
    {
        // Check boundary conditions and if the pixel has the old color
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != oldColor)
        {
            return;
        }

        // Change the color of the current pixel
        image[i][j] = newColor;

        // Recursively fill the neighboring pixels
        dfs(image, i, j + 1, oldColor, newColor); // Right
        dfs(image, i, j - 1, oldColor, newColor); // Left
        dfs(image, i - 1, j, oldColor, newColor); // Up
        dfs(image, i + 1, j, oldColor, newColor); // Down
    }
};
//-------------------Using BFS to solve this Problem ----------------------------------

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int rows = image.size();
        int cols = image[0].size();

        if (image[sr][sc] == color)
        {
            return image;
        }

        int oldColor = image[sr][sc];

        // Create a queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});

        // Perform BFS
        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            // Check boundary conditions and if the pixel has the old color
            if (i >= 0 && i < rows && j >= 0 && j < cols && image[i][j] == oldColor)
            {
                // Change the color of the current pixel
                image[i][j] = color;

                // Enqueue neighboring pixels
                q.push({i, j + 1}); // Right
                q.push({i, j - 1}); // Left
                q.push({i - 1, j}); // Up
                q.push({i + 1, j}); // Down
            }
        }

        return image;
    }
};

//---------------count each component nodes number in acending order-------------

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> V[N];
bool vis[N];
int level[N];

void bfs(int src, int &number_of_component)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    number_of_component = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        number_of_component++;

        for (int neighbor : V[current])
        {
            if (!vis[neighbor])
            {
                q.push(neighbor);
                vis[neighbor] = true;
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

    vector<int> number_of_components_nodes;

    int componentCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            int number_of_component;
            bfs(i, number_of_component);
            number_of_components_nodes.push_back(number_of_component);
            componentCount++;
        }
    }

    sort(number_of_components_nodes.begin(), number_of_components_nodes.end());

    for (int size : number_of_components_nodes)
    {
        cout << size << " ";
    }

    return 0;
}
