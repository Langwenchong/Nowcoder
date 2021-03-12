#include <bits/stdc++.h>
using namespace std;

#define close_stdin ios::sync_with_stdio(false)
const int N = 1e2;
int dp[N + 5][N + 5][N + 5], w[N + 5], v[N + 5];
int main()
{
    close_stdin;
    int ans = 0;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i] >> v[i];
    }
    //初始化为-1
    memset(dp, 255, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        //将i=0的情况全部设定为0，因为无法选物品当然就是0了
        dp[0][0][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                //此时要三层嵌套，枚举k
                //当为-1时，表示上一个表格未满足条件不能赋值，所以跳过以防影响后面的打表
                if (!~dp[i][j][k])
                    continue;
                //满足条件时先将这个格的下一个格赋值为当前格的值，表示不放入物品i+1的收益情况就是此时i的情况
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                //当满足w[i]<K时我们利用递归式求解放入和不放入的情况哪个收益更好
                if (w[i + 1] <= k && j + w[i] <= n)
                {
                    dp[i + 1][j + w[i + 1]][w[i + 1]] = max(dp[i + 1][j + w[i + 1]][w[i + 1]], dp[i][j][k] + v[i + 1]);
                }
            }
        }
    }
    for (int j = 0; j <= n; j++)
    {
        for (int k = 0; k <= n; k++)
        {
            //选取最好收益情况，此时j未必等于N且k也未必是w[n]
            ans = max(ans, dp[m][j][k]);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// const int maxn = 110;

// int v[maxn], w[maxn], dp[maxn][maxn]; //记录上一个物品的重量

// signed main()
// {
//     ios::sync_with_stdio(false), cin.tie(0);
//     int n, m;
//     while (cin >> n >> m)
//     { //n容量m物品
//         memset(dp, 0, sizeof dp);
//         for (int i = 0; i < m; ++i)
//             cin >> w[i] >> v[i];
//         int ans = 0; //记录答案
//         for (int i = 0; i < m; ++i)
//         { //到第i件物品
//             for (int j = n; j >= w[i]; --j)
//             { //优化降维,逆序由上一轮到本轮,总共选了j重量
//                 for (int k = w[i]; k <= j; ++k)
//                 {                                                           //最后一个物品重量为k,保证递减
//                     dp[j][w[i]] = max(dp[j][w[i]], dp[j - w[i]][k] + v[i]); //
//                 }
//                 ans = max(ans, dp[j][w[i]]);
//             }
//         }
//         cout << ans << endl;
//     }
//     //system("pause");
//     return 0;
// }