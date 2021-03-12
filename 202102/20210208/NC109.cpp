class Solution
{
public:
    /**
     * 判断岛屿数量
     * @param grid char字符型vector<vector<>> 
     * @return int整型
     */
    int m, n;
    int Map[205][205];
    int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(int x, int y)
    {
        if (x < 0 || x >= m || y < 0 || y >= n || Map[x][y] == 0)
        {
            return;
        }
        if (Map[x][y] == 1)
            Map[x][y] = 0;
        for (int i = 0; i < 4; i++)
        {
            dfs(x + dir[i][0], y + dir[i][1]);
        }
    }
    int solve(vector<vector<char>> &grid)
    {
        m=grid.size();
        n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                Map[i][j] = grid[i][j]-'0';
            }
        }
//         for(int i=0;i<m;++i){
//             for(int j=0;j<n;++j)
//                cout<<Map[i][j];
//             cout<<endl;
// }
          
        int num=0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (Map[i][j] == 1)
                {
                    dfs(i, j);
                    num++;
                }
            }
        }
        return num;
    }
};