#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
double t[N], c[N];

int main()
{
    double T, C;
    int n;
    cin >> n;
    cin >> T >> C;
    double v = 0.0;
    v += T * C;
    double tmax = 0.0, tmin = 1e9, c1 = C;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
        v += t[i] * c[i];
        c1 += c[i];
        tmax = max(t[i], tmax);
        tmin = min(t[i], tmin);
    }
    //求平均值
    double aver = v / c1;
    //小于最小温度，那么可以调节的最大温度就是最小值
    //大缸中的水是降温的，比杯中最低温的水温度还低
    if (aver <= tmin)
    {
        cout << "Possible" << endl;
        //保留小数点4位
        cout << fixed << setprecision(4) << tmin << endl;
    }
    //能够大于那么就输出平均值
    //大缸的水是升温的，比杯中最高温度的水温度还高
    else if (aver >= tmax)
    {
        cout << "Possible" << endl;
        cout << fixed << setprecision(4) << aver << endl;
    }
    //否则不可能调节
    else
    {
        //原因很简单对于tmin<aver<tmax
        //再怎么加水tmin只会无限趋于aver而不会等于aver
        //再怎么加水tmax也只会无限趋近于aver而不会等于aver
        cout << "Impossible" << endl;
    }
    system("pause");
    return 0;
}