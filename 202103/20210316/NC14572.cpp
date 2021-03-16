#include <bits/stdc++.h>
using namespace std;

//方向向量
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//地图
char _map[505][505];
int vis[505][505];
bool ok = false;
int m, n;

void dfs(int i, int j)
{
    //越界就停
    if (i > m || j > n || i < 1 || j < 1)
        return;
    //不能走就停
    if (_map[i][j] == '#')
        return;
    if (vis[i][j] == 1)
        return;
    //找到终点，ok=true
    if (_map[i][j] == 'E')
    {
        ok = true;
        return;
    }
    vis[i][j] = 1;
    dfs(i + dir[0][0], j + dir[0][1]);
    dfs(i + dir[1][0], j + dir[1][1]);
    dfs(i + dir[2][0], j + dir[2][1]);
    dfs(i + dir[3][0], j + dir[3][1]);
}

int main()
{
    //m行n列
    while (cin >> m >> n)
    {
        ok = false;
        memset(_map, 0, sizeof(_map));
        memset(vis, 0, sizeof(vis));
        int x, y;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> _map[i][j];
                //找到起点位置
                if (_map[i][j] == 'S')
                {
                    x = i;
                    y = j;
                }
            }
        }
        //出发
        dfs(x, y);
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    system("pause");
    return 0;
}