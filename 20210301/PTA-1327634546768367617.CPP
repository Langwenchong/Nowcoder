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
        dp[0][0][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                if (!~dp[i][j][k])
                    continue;
                dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
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
            ans = max(ans, dp[m][j][k]);
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}