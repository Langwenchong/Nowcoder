#include <bits/stdc++.h>
using namespace std;

#define mod 10007

//快速幂计算a^k
int qmi(int a, int k)
{
    a %= mod;
    //ans是结果值
    int ans = 1;
    //采用的是二进制的计算方法
    while (k)
    {
        //这里k在机器中是二进制表示，与1相与，只有k的最后一位是1才能使得if条件成立
        if (k & 1)
            //此时ans就乘以一个基数a
            ans = ans * a % mod;
        //每一次a都要扩大一倍表示下一位的位权
        a = a * a % mod;
        //k右移一位取最低位
        k >>= 1;
    }
    return ans;
}

int main()
{
    int a, b, k, n, m;
    cin >> a >> b >> k >> n >> m;
    //快速幂计算a^n和b^m
    int ans = qmi(a, n) * qmi(b, m) % mod;
    for (int i = 1, j = k; i <= n; i++, j--)
    //一共分子和分母只需要计算n次
    {
        //这里用来计算Ckn
        ans = ans * j % mod;
        //这里是求n!的逆元，以便能够取模
        ans = ans * qmi(i, mod - 2) % mod;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}