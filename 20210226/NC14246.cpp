#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        //木桩从小到大排序
        sort(a + 1, a + n + 1);
        int ans = 0, tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            //记录增大木桩的数量
            if (a[i] > tmp)
            {
                tmp = a[i];
                ans++;
            }
        }
        //实际上也可以使用数组去重更简单，只需要把相同高度的木桩去重
        //使用数组的unique函数自动去重并返还剩余元素个数
        // ans = unique(a + 1, a + n + 1) - (a+1);
        cout << ans << endl;
    }
    system("pause");
    return 0;
}