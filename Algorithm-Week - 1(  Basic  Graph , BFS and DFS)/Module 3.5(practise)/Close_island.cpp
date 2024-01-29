class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int close_island = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 0)
                {
                    if (dfs(grid, i, j, row, col))
                    {
                        close_island++;
                    }
                }
            }
        }
        return close_island;
    }

    bool dfs(vector<vector<int>> &grid, int i, int j, int row, int col)
    {
        if (i < 0 || i >= row || j < 0 || j >= col)
        {
            return false;
        }

        if (grid[i][j] == 0)
        {
            grid[i][j] = 1;

            bool top = dfs(grid, i - 1, j, row, col);
            bool bottom = dfs(grid, i + 1, j, row, col);
            bool left = dfs(grid, i, j - 1, row, col);
            bool right = dfs(grid, i, j + 1, row, col);

            return top && bottom && left && right;
        }
        return true;
    }
};