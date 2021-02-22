#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, a, b;
    while (cin >> x >> y >> a >> b)
    {
        int ans = 0;
        if ((x == 1 || y == 1) || ((x == 2 && y == 2) && (a + b >= 2)))
        {
            cout << "INF" << endl;
            continue;
        }
        else
        {
            //否则有限次兑换
            while (a >= x || b >= y)
            {
                //用x个瓶子兑换
                if (a >= x)
                {
                    int tmp1 = a / x;
                    a = a % x;
                    a += tmp1;
                    b += tmp1;
                    ans += tmp1;
                }
                //用y个瓶盖兑换
                if (b >= y)
                {
                    int tmp2 = b / y;
                    b = b % y;
                    a += tmp2;
                    b += tmp2;
                    ans += tmp2;
                }
            }
            cout << ans << endl;
        }
    }
    system("pause");
    return 0;
}