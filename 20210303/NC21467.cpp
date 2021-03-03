#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
//存储货币
int a[105];
//vis标记数组
//0表示不可以被其他货币表示
//1表示可以被其他货币表示也就可有可无
int vis[N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        //初始化
        memset(a, 0, sizeof(a));
        memset(vis, 0, sizeof(vis));
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        //排序
        sort(a + 1, a + n + 1);
        //默认每一个货币都是必须存在的
        int ans = n;
        //首先0肯定是可有可无的
        vis[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            //如果vis为1，那么这个货币可有可无
            //货币数量-1
            if (vis[a[i]])
            {
                ans--;
            }
            //否则这个货币必须存在
            //然后所有可以表示的货币值j+a[i]肯定也就是可以被表示了
            //都标记为1表示可有可无
            for (int j = 0; j <= a[n]; j++)
            {
                //枚举j从a[i]到最大货币值
                //如果j是可以被表示的
                if (vis[j])
                {
                    //那么j+a[i]肯定也可以被表示
                    vis[j + a[i]] = 1;
                }
            }
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}