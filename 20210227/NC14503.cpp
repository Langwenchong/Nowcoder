#include <bits/stdc++.h>
using namespace std;

//最小公倍数=两数乘积/最大公约数
long f(long a, long b)
{
    long m = a * b;
    //最大公约数--相减法
    //     while(a<b || a>b){
    //        if(a<b)b=b-a;
    //        if(a>b)a=a-b;
    //    }

    /*最大公约数--辗转相除法*/
    if (b > a)
        swap(a, b);
    long c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    return m / b;
}
int main()
{
    long a, b, c;
    cin >> a >> b >> c;
    long cnt = f(a, b);
    long ans = f(cnt, c);
    cout << ans << endl;
    system("pause");
    return 0;
}