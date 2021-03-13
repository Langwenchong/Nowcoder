#include <bits/stdc++.h>
using namespace std;

//pi的定义，学习了
const double pi(acos(-1));

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double cx, cy, r, n;
        cin >> cx >> cy >> r >> n;
        //一个内角的大小
        double k = 2 * pi / n;
        //其实就是每次旋转一个内角，然后坐标加上cos和sin的值即可
        for (int i = n; i; i--)
        {
            //sin函数和cos函数都是接受的参数为弧度
            double a = cx + cos(k * i) * r;
            double b = cy + sin(k * i) * r;
            //核心：当小于1e-6应该是0.0
            if (fabs(a) < 1e-6)
                a = 0.0;
            if (fabs(b) < 1e-6)
                b = 0.0;
            cout << fixed << setprecision(2) << a << " " << b << endl;
        }
    }
    system("pause");
    return 0;
}