#include <bits/stdc++.h>

#define ll long long
using namespace std;

double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}
double dp[40];
int main()
{
    int n;
    double r1, r2, r3, r5;
    cin >> n >> r1 >> r2 >> r3 >> r5;
    r1 = pow(1 + r1, 1);
    r2 = pow(1 + r2, 2);
    r3 = pow(1 + r3, 3);
    r5 = pow(1 + r5, 5);
    dp[0] = 1;
    //dp打表yyds
    for (int i = 1; i <= 20; ++i)
    {
        if (i >= 1)
            dp[i] = max(dp[i - 1] * r1, dp[i]);
        if (i >= 2)
            dp[i] = max(dp[i - 2] * r2, dp[i]);
        if (i >= 3)
            dp[i] = max(dp[i - 3] * r3, dp[i]);
        if (i >= 5)
            dp[i] = max(dp[i - 5] * r5, dp[i]);
    }
    cout << dp[n] << endl;
    system("pause");
    return 0;
}
