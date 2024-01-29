#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m;
int maze[N][N];
int visited[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool valid(int x, int y)
{
    return !visited[x][y] && maze[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y)
{
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (valid(new_x, new_y))
        {
            dfs(new_x, new_y);
        }
    }
}

int Cnt_apatment()
{
    int Cnt_apatment = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && maze[i][j] == 0)
            {
                dfs(i, j);
                Cnt_apatment++;
            }
        }
    }

    return Cnt_apatment;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char house;
            cin >> house;
            if (house == '.')
            {
                maze[i][j] = 0; // room_sonkha
            }
            else
            {
                maze[i][j] = -1; // #_gula boundary
            }
        }
    }

    int apartments = Cnt_apatment();

    cout << apartments << endl;

    return 0;
}
