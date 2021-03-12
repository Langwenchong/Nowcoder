#include <bits/stdc++.h>
const int maxx = 1e5 + 15;
#define ll long long
//取模提前声明，好习惯
const ll mod = 1e9 + 7;
using namespace std;
string s;

//快速幂取模板子，注意第一个放C底下的数，第二个放C上面的数
ll qmi(int a, int k)
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

//逆元取模的组合数板子
ll C(ll k, ll n)
{
    int num = 1;
    for (int i = 1, j = k; i <= n; i++, j--)
    //一共分子和分母只需要计算n次
    {
        //这里用来计算Ckn
        num = num * j % mod;
        //这里是求n!的逆元，以便能够取模
        num = num * qmi(i, mod - 2) % mod;
    }
    return num;
}

int main()
{
    ll i, m, n;
    cin >> s;
    cin >> m;
    n = s.length();
    //多余出来的位数
    ll ans = 0;
    //i至少有n个，同时还忽悠m-n个多于的位，这里就是在模拟这些位放在哪里
    //如果是插在子序列的左边或中间，那么就只能有25个选择
    //否则子序列右边就是26个选择
    //枚举子序列左边的位数（包括子序列自身）
    //那么i-n是插到子序列左边的多于位数的个数（有25个选择的位数个数）
    //m-i是放到子序列右边即后面的位数个数（有26个选择的位数的个数）
    //实际上模拟取模的二项式定理
    for (i = n; i <= m; i++)
    {
        //注意当长度为4，那么实际上C的底数是3即为n-1,上面就是
        ans += C(n - 1, i - 1) * qmi(25, i - n) % mod * qmi(26, m - i) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}