#include <bits/stdc++.h>
using namespace std;
int dp[10005], n, m, _time[10005], _x[10005], _y[10005], ans; //dp[i]表示到第i只时能打多少只
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> _time[i] >> _x[i] >> _y[i];
    }
    for (int i = 1; i <= m; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j < i; j++)
        {
            //如果曼哈顿距离小于时间差
            if (abs(_x[i] - _x[j]) + abs(_y[i] - _y[j]) <= abs(_time[i] - _time[j]))
            {
                //那么可以抓到这只小鼠，比较dp[i]和通过dp[j]+1得到的哪个方法更好
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}
