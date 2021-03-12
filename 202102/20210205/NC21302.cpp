#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int dp[55][3];

int main()
{
    string s;
    cin >> s;
    int len = s.length();
    //初始化
    memset(dp, 0, sizeof(dp));
    //初始化个数
    int tmp = 0;
    //检验第一个数的余数，在相应的位置+1
    dp[0][(s[0] - '0') % 3] = 1;
    //检验后面的s-1个数，逐一加上
    for (int i = 1; i < len; i++)
    {
        //存储第i+1个数%3的结果
        tmp = (s[i] - '0') % 3;
        //只检验第i+1%3的余数并在相应的位置+1
        dp[i][tmp] = (dp[i][tmp] + 1) % mod;
        for (int j = 0; j < 3; j++)
        {
            //包含了前i个数组成序列的情况，以及第1+1的余数和前i个数组成序列的和数取余为j的情况个数
            dp[i][j] += (dp[i - 1][j] + dp[i - 1][(j + 3 - tmp) % 3]) % mod;
        }
    }
    //打印答案，因为从0开始，所以到i-1
    cout << dp[len - 1][0] % mod << endl;
    system("pause");
    return 0;
}