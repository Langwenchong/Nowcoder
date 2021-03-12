#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 7;   //最大值
const int INF = 0x3f3f3f3f; //无穷大
int dp[MAXN][MAXN];         //从做端点到右端点区间部分填涂的最少次数

int main()
{
    string s; //存入字符串
    cin >> s;
    int len = s.length();                         //字符串长度
    s = ' ' + s;                                  //将字符串预处理前面加一个字符，这样l从1开始更舒服
    memset(dp, INF, sizeof(dp));                  //将所有区间的填涂次数初始化为无穷大
    for (int length = 1; length <= len; length++) //枚举区间长度从1开始到len
    {
        for (int l = 1; l + length - 1 <= len; l++) //枚举左端点的开始处
        {
            //右端点就是左端点+长度-1
            int r = l + length - 1;
            //如果左右端点恰巧相同，那么就是一个字符，填涂一次即可
            if (length == 1)
                dp[l][r] = 1;
            else
            {
                //如果左端点，右端点颜色相同
                if (s[l] == s[r])
                    //那么填涂次数就等于dp[l+1][r]与dp[l][r-1]的最小者
                    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]);
                else
                {
                    //否则必定逐渐还有一个过渡的填色点且他后来要被覆盖所以必定在l,r之间，枚举尝试
                    for (int k = 1; k < r; k++)
                    {
                        dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
                    }
                }
            }
        }
    }
    cout << dp[1][len] << endl;
    system("pause");
    return 0;
}