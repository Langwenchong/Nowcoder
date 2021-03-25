#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
const int maxk = 1e7 + 5;
//假设我们取的下一个数是num[i]
//temp[j]表示在num[i]之前的所有数中所能凑出的余数为j的最长子序列的长度
int temp[maxk];
//dp[j]表示在加上num[i]以后余数为j的子序列的最大长度
int dp[maxk];
//存储数值
int num[maxn];
int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> num[i];
    for (int i = 0; i < n; i++)
    {
        //j==0时可以进入，因为至少存在一个只取num[i]自己组成一个单位长度的子序列使得余数为(0+num[i])%k的子序列长度+1
        //temp[j]==0时不可以进入，因为此时就不存在能凑出来所需要的余数为j的子序列
        //那么相应的余数为(j+num[i])%k的子序列肯定也不存在，所以就不用加一了
        for (int j = 0; j < k; j++)
        {
            if (j == 0 || temp[j] != 0)
                dp[(j + num[i]) % k] = temp[j] + 1;
        }
        //每次检查完num[i]以后
        //dp>=temp,所以我们需要更新temp
        for (int j = 0; j < k; j++)
            temp[j] = max(temp[j], dp[j]);
    }
    cout << temp[0] << endl;
    system("pause");
    return 0;
}