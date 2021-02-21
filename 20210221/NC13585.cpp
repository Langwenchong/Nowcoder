#include <bits/stdc++.h>
using namespace std;

int main()
{
    //标记数组，0表示未使用过，1表示使用过
    int vis[9] = {};
    //对不同的不能直接相连情况的点赋值不同的权重
    int pri[9] = {1, 2, 1, 3, 0, 3, 1, 2, 1};
    string s;
    while (cin >> s)
    {
        //默认都可以
        bool ok = true;
        //一定要初始化标记数组全0
        memset(vis, 0, sizeof(vis));
        //对每一个点逐一检验
        for (int i = 0; i < s.size() - 1; i++)
        {
            //两个相邻点的值
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            if (a == b)
            {
                //相邻两个点相同，如3321
                ok = false;
                break;
            }
            if (vis[a - 1] == 1 || vis[b - 1] == 1)
            {
                //或者当前点被使用过，如1232
                ok = false;
                break;
            }
            //标记这个点被使用过了
            vis[a - 1] = 1;
            //如果两个相邻点是不能直接相连的且他们中间节点还未使用过
            if (pri[a - 1] == pri[b - 1] && !vis[(a + b) / 2 - 1])
            {
                //那么不符合题干
                ok = false;
                break;
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}