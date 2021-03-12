#include <bits/stdc++.h>
using namespace std;
int p[100005];
int vis[100005];
int main()
{
    int n, a, b, x, y, cnt = 0;
    //标记数组用来判断数p[i]属于集合A还是集合B
    memset(vis, 0, sizeof(vis));
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    //排序
    sort(p, p + n);
    int valid = 1;
    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            //对于每一个数p[i]同时求出不小于a-p[i]和不小于b-p[i]的值
            x = lower_bound(p, p + n, a - p[i]) - p;
            y = lower_bound(p, p + n, b - p[i]) - p;
            //这个解题方法巧就巧在当a-p[i]或者b-p[i]不存在时，那么返还的键值x,y
            //无论是p[y]+p[i]==b还是p[x]+p[i]==a都不会成立
            //那么也就检验出了a-x或者b-x这个数不存在的情况了，直接退出输出no即可了
            //如果是有一种集合情况满足，那么相应的加入对应的集合，如果是集合A，那么标记数值为1，如果是集合B，那么标记数值是2
            //如果同时满足，那么由于判断B集合的在前面，会优先加入到集合B
            if (!vis[y] && p[y] + p[i] == b)
            {
                //注意标记为2，因为标记0已经被用来当做没被使用的含义了
                vis[i] = vis[y] = 2;
                continue;
            }
            if (!vis[x] && p[x] + p[i] == a)
            {
                //注意标记为1，因为标记0已经被用来当做没被使用的含义了
                vis[i] = vis[x] = 1;
                continue;
            }
            valid = 0;
            break;
        }
    if (!valid)
        cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (int i = 0; i < n - 1; i++)
            //恰巧此时-1就是相对应的标记，B集合2-1=1，A集合1-1=0
            cout << vis[i] - 1 << " ";
        cout << vis[n - 1] - 1 << endl;
    }
    system("pause");
    return 0;
}
