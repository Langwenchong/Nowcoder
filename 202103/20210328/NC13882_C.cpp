// #include <bits/stdc++.h>
// using namespace std;
// const long long N = 1e5;
// long long n;
// bool ok = false;

// //这次要加的数，和，加的次数
// void dfs(long long x, long long sum, long long num)
// {
//     if (x >= n)
//         return;
//     if (num == 5)
//     {
//         if (sum == n)
//         {
//             ok = true;
//         }
//         return;
//     }
//     //不选这个数x
//     dfs(x + 1, sum, num);
//     sum += x * x;
//     if (sum > n)
//     {
//         return;
//     }
//     //选了这个数x，并且下一个还是选x
//     dfs(x, sum, num + 1);
//     //选了这个数x，并且下一个数选x+1
//     dfs(x + 1, sum, num + 1);
// }
// int main()
// {
//     long long t;
//     cin >> t;
//     while (t--)
//     {
//         ok = false;
//         cin >> n;
//         //从1开始
//         dfs(1, 0, 0);
//         if (ok)
//             cout << "YES" << endl;
//         else
//             cout << "NO" << endl;
//     }
//     system("pause");
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        //这几个数不满足，其他的数都满足
        if (n == 5 || n == 8 || n == 11 || n == 13 || n == 14 || n == 16 || n == 17 || (n != 33 && n >= 19))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    system("pause");
    return 0;
}