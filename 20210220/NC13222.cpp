#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int a[N], b[N];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int ans = 1e9;
    for (int i = 1; i <= m - n + 1; i++)
    {
        int sum = 0;
        for (int j = i; j <= i + n - 1; j++)
        {
            sum += (a[j - i + 1] - b[j]) * (a[j - i + 1] - b[j]);
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    system("pause");
    return 0;
}