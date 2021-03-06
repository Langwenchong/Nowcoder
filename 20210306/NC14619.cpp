#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int a[N];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (i == k)
                continue;
            sum ^= a[i];
        }
        if (sum >= a[k])
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    system("pause");
    return 0;
}