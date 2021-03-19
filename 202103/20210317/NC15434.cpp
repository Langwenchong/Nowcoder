#include <bits/stdc++.h>
using namespace std;

char _map[505][505];
int vis[505][505];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int m, n;
bool ok;

void dfs(int i, int j)
{
    if (i > m || i < 1 || j > n || j < 1)
    {
        return;
    }
    if (_map[i][j] == 'x')
    {
        return;
    }
    if (_map[i][j] == 't')
    {
        ok = true;
        return;
    }
    if (vis[i][j] == 1)
        return;
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        dfs(i + dir[k][0], j + dir[k][1]);
    }
    return;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        int x, y;
        ok = false;
        memset(_map, 0, sizeof(_map));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> _map[i][j];
                if (_map[i][j] == 's')
                {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(x, y);
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}