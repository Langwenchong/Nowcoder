#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0;
    int n;
    cin >> n;
    //当乘10%即模10的时候不是整数，那么所有牌的人数都++
    if (n % 10 != 0)
    {
        a++;
        b++;
        c++;
    }
    //当乘20%即模10/2=5的时候不是整数，那么银、铜人数都++
    if (2 * n % 10 != 0)
    {
        b++;
        c++;
    }
    //当乘30%即模10/3的时候不是整数，那么铜牌人数++
    if (3 * n % 10 != 0)
    {
        c++;
    }
    cout << a << " " << b << " " << c << endl;
    system("pause");
    return 0;
}