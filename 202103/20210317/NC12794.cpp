#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
//f是最高价值
//p是每一个节点的收益值
//w每一个节点的成本值
//g记录组号
int f[N], p[N], w[N], g[N];

int main()
{
    int t;
    cin >> t;
    int num = 0;
    while (t--)
    {
        num++;
        //多组测试需要初始化
        memset(w, 0, sizeof(w));
        memset(p, 0, sizeof(p));
        memset(g, 0, sizeof(g));
        memset(f, 0, sizeof(f));
        //d种疾病，总资金c
        int d, c;
        cin >> d >> c;
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                //存入成本，收益
                cin >> w[(i - 1) * 4 + j];
                cin >> p[(i - 1) * 4 + j];
                //用时进行分组
                g[(i - 1) * 4 + j] = i;
            }
        }
        //分组背包
        //此时每次遍历i就是打印一行
        //枚举组->枚举容量->枚举某一组中的所有节点
        //逆序容量dp降维
        for (int i = 1; i <= d; i++)
        {
            //注意，此时y还是从大到小
            for (int y = c; y >= 0; y--)
            {
                for (int k = 1; k <= 4 * d; k++)
                {
                    if (y >= w[k] && g[k] == i)
                    {
                        f[y] = max(f[y], f[y - w[k]] + p[k]);
                    }
                }
            }
        }
        printf("Budget #%d: Maximum of %d lives saved.\n\n",num,f[c]);
        // cout << "Budget #" << num << ": Maximum of " << f[c] << " lives saved." << endl;
    }
    system("pause");
    return 0;
}
