// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long

// ll judge(ll x)
// {
//     ll num = 0;
//     string s = to_string(x);
//     cout << s << endl;
//     for (ll i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '0' || s[i] == '4' || s[i] == '6' || s[i] == '9')
//             num++;
//         if (s[i] == '8')
//             num += 2;
//     }
//     return num;
// }

// int main()
// {
//     ll T;
//     cin >> T;
//     while (T--)
//     {
//         ll a, b;
//         cin >> a >> b;
//         ll ans = 0;
//         for (ll i = a; i <= b; i++)
//         {
//             ans += judge(i);
//         }
//         cout << ans << endl;
//     }
//     system("pause");
//     return 0;
// }

#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        int sum = 0;
        for (int j = a; j <= b; j++)
        {
            int temp = j;
            while (temp != 0)
            {
                int ans = temp % 10;
                if (ans == 4 || ans == 6 || ans == 9 || ans == 0)
                    sum++;
                else if (ans == 8)
                    sum = sum + 2;
                temp = temp / 10;
            }
        }
        cout << sum << endl;
    }

    system("pause");
    return 0;
}