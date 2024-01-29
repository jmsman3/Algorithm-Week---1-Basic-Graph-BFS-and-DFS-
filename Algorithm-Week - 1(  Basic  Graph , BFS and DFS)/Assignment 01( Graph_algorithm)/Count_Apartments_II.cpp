#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

int n, m;
int maze[N][N];
int visited[N][N];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validate(int x, int y)
{
    return !visited[x][y] && maze[x][y] != -1 && x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y, int &room_cnt)
{
    visited[x][y] = true;
    room_cnt++;

    for (int i = 0; i < 4; i++)
    {
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if (validate(new_x, new_y))
        {
            dfs(new_x, new_y, room_cnt);
        }
    }
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

    vector<int> apartment_rooom_numbers;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && maze[i][j] == 0)
            {
                int roomCount = 0;
                dfs(i, j, roomCount);
                apartment_rooom_numbers.push_back(roomCount);
                roomCount++;
            }
        }
    }

    sort(apartment_rooom_numbers.begin(), apartment_rooom_numbers.end());

    if (apartment_rooom_numbers.empty())
    {
        cout << 0 << endl;
    }
    else
    {
        for (int Room_Sonkha : apartment_rooom_numbers)
        {
            cout << Room_Sonkha << " ";
        }
    }

    return 0;
}
