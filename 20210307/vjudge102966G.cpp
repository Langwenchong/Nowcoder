#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int l, n;
    while (cin >> l >> n)
    {
        int ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (y == 0)
                //记录向左走的距离值
                ans = max(ans, x);
            else
                //向右走的距离值
                ans = max(ans, l - x);
        }
        //取最大值即可
        cout << ans << endl;
    }
    system("pause");
    return 0;
}