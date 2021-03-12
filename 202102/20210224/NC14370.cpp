#include <bits/stdc++.h>
using namespace std;

int f[1005], t[1005], v[105];

int T, n, i, j;
int main()
{
    cin >> T >> n;
    for (i = 1; i <= n; i++)
        cin >> t[i] >> v[i];
    //f[i]物品1~i范围选取
    for (i = 1; i <= n; i++)
        //注意，逆序是逆序的即背包容量从大到小，fot已经特判能否装入
        for (j = T; j >= t[i]; j--)
            //右边的都是第i-1次循环的结果
            f[j] = max(f[j], f[j - t[i]] + v[i]);
    cout << f[T] << endl;
    system("pause");
    return 0;
}