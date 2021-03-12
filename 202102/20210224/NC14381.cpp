#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char Map[505][505];
int n, m;

bool flag(int x, int y)
{
    //检验是否越界的函数
    if (x >= 0 && x < n && y >= 0 && y < m)
        return 1;
    else
        return 0;
}

int main()
{

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> Map[i][j];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //因为是四个方向检查，所以需要四个方向临时点
            int x1, y1, x2, y2, x3, y3, x4, y4;
            //寻找中心点
            if (Map[i][j] != 'X')
                continue;
            ans = max(ans, 1);
            for (int len = 1; len <= min(n, m) / 2; len++)
            {
                int valid = 1;
                //算出四个方向的从中心点移动后的顶点位置
                x1 = i - len;
                y1 = j - len;
                x2 = i + len;
                y2 = j - len;
                x3 = i - len;
                y3 = j + len;
                x4 = i + len;
                y4 = j + len;
                //检验是否越界
                if (flag(x1, y1) && flag(x2, y2) && flag(x3, y3) && flag(x4, y4))
                {
                    //如果都不越界，那么检验顶点值是否满足题意
                    if (Map[x1][y1] == 'X' && Map[x2][y2] == 'X' && Map[x3][y3] == 'O' && Map[x4][y4] == 'O')
                    {
                        //满足以后分别检验顶点中间的值是否满足题意
                        for (int l = x1; l <= x2; l++)
                        {
                            if (Map[l][y1] != 'X')
                            {
                                valid = 0;
                                break;
                            }
                        }
                        for (int l = x3; l <= x4; l++)
                        {
                            if (Map[l][y3] != 'O')
                            {
                                valid = 0;
                                break;
                            }
                        }
                        //满足题意就为斜边长的2倍再+1（因为有一个中心点)
                        if (valid)
                            ans = max(ans, len * 2 + 1);
                    }
                    else
                        break;
                }
                else
                    break;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
