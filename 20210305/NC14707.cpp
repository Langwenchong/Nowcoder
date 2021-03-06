#include <bits/stdc++.h>
using namespace std;

//记录每一秒会有多少个人在用wifi
int a[5005];

int main()
{
    int n, m;
    cin >> n >> m;
    int Max = -1;
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        //[l,r]区间的每一秒使用wifi的人数+1
        for (int i = l; i <= r; i++)
        {
            a[i]++;
            if (a[i] > Max)
            {
                //取每一时刻最大wifi位数
                Max = a[i];
            }
        }
    }
    int ans;
    //如果能整除，就是MAX/m
    if (Max % m == 0)
    {
        ans = Max / m;
    }
    else
    {
        //否则有余数要加一
        ans = Max / m + 1;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}