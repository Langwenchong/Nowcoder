#include <bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n, sum = 0, s, ans;
    cin >> n >> s;
    ans = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + 1 + n);
    //其实就是寻找必须要的硬币
    for (int i = n; i >= 1; i--)
        if (sum - a[i] >= s)
            //说明第i个硬币不是必须的硬币
            ans--, sum -= a[i];
    cout << ans << endl;
    system("pause");
    return 0;
}