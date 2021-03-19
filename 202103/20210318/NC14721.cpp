#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 1e5 + 5;
int m[N], e[N];
int c[N];

bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    ll n, k;
    cin >> n >> k;
    ll i;
    ll ans = 0;
    for (i = 1; i <= n; ++i)
        //存入早上的甜度
        cin >> m[i];
    for (i = 1; i <= n; ++i)
    {
        //存入晚上的甜度
        cin >> e[i];
        //默认都吃晚上的
        ans += e[i];
        c[i] = m[i] - e[i];
    }
    //将早晚甜度差值最大的从大到小排序
    sort(c + 1, c + n + 1, cmp);
    //有k个早上的可以甜度更大
    for (i = 1; i <= k; ++i)
    {
        ans += c[i];
    }
    cout << ans << endl;
    system("pause");
    return 0;
}