#include <bits/stdc++.h>
using namespace std;

int t, n, dp[50];

void init()
{
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i < 50; i++)
        dp[i] += dp[i - 1] + dp[i - 2];
}

int main(void)
{
    init();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dp[n + 1] << endl;
    }
    system("pause");
    return 0;
}