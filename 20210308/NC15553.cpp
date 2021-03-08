#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[2000005];
int main()
{

    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            //前缀和，a[i]就是1~i的所有数之和
            cin >> a[i], a[i] += a[i - 1];
        }
        ll ma = -1e18, ans = -1e18;
        //从k开始找，意味着一定是长度大于等于k的数之和
        for (int i = k; i + k <= n; i++)
        {
            //寻找第一个最大值，a[i]-a[i-k]保证了长度一定是k
            ma = max(ma, a[i] - a[i - k]);
            //很巧，ans刚好是找a[i+1]~a[i+k]的数之和，避免了两个区间交叉的情况出现
            ans = max(ans, ma + a[i + k] - a[i]);
        }
        cout << ans << endl;
    }
    system("pause");
    return 0;
}