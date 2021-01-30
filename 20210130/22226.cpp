#include <bits/stdc++.h>
using namespace std;
int vis[1000001] = {0};
int result[1000001]={0};
int cnt=0;


int main()
{
    int T;
    cin >> T;
    // while (T--)
    // {
    //     int n;
    //     cin >> n;
    //     int sum = 0;
    //     for (int i = 2; i <= n; i++)
    //     {
    //         bool ok = true;
    //         for (int j = 2; j < i; j++)
    //         {
    //             if (i % j == 0)
    //             {
    //                 ok = false;
    //                 break;
    //             }
    //         }
    //         if (ok)
    //         {
    //             sum++;
    //         }
    //     }
    //     cout << sum << endl;
    // }
    memset(vis, 0, sizeof(vis));
    for (int i = 2; i <= 1000001; i++)
    {
        if (!vis[i])
        {
            cnt++;
            for (int j = 2*i; j <= 1000001; j += i)
                vis[j] = 1;
        }
        result[i]=cnt;
    }
    while (T--)
    {
        int n;
        cin >> n;
        cout<<result[n]<<endl;
    }
    system("pause");
    return 0;
}