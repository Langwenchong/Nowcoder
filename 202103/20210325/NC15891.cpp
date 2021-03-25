#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
int ans = -1;
//存储获取糖的数量，以及达到这个站点消耗的糖的数量
int a[N], b[N];
int n;

//当下剩余的糖的数量，所处站点编号，已经拿过糖的次数
void dfs(int extra, int x, int c)
{
    //如果拿糖次数>3
    //或者剩余糖的数量<0,说明到达不了这个站点
    if (c > 3 || extra < 0)
    {
        //退出
        return;
    }
    //如果到达了n+1，那么就走完了，统计糖的个数
    if (x == n + 1)
    {
        ans = max(ans, extra);
        return;
    }
    //去往下一个站点，并且此次站点不拿糖
    dfs(extra - b[x], x + 1, c);
    //去往下一个站点，并且此次站点拿糖
    extra += a[x];
    dfs(extra - b[x], x + 1, c + 1);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        cin >> b[i];
    }
    dfs(0, 1, 0);
    cout << ans << endl;
    system("pause");
    return 0;
}