#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;

vector<int> vec[maxn];
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, q;
    cin >> n >> q;
    int big = 0;
    for (int i = 1; i <= n; ++i)
    {
        int p;
        cin >> p;
        big = max(big, p);
        //将质量为p的贝壳的键值压入p容器，所以vec[p]存放的是所有质量为p的贝壳键值
        vec[p].push_back(i);
    }
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        int ans = 0;
        for (int i = x; i <= big; i += x)
        {
            //大于等于质量为i的键值
            int zuo = lower_bound(vec[i].begin(), vec[i].end(), l) - vec[i].begin();
            //大于质量为i的键值
            int you = upper_bound(vec[i].begin(), vec[i].end(), r) - vec[i].begin();
            //相见就是所有质量为i的贝壳的数量
            ans += you - zuo;
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}