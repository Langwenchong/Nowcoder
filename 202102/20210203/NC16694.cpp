#include <bits/stdc++.h>
using namespace std;
//找到的零点个数
int num = 0;
double a, b, c, d;
double f(double x)
{
    //带入x计算
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> a >> b >> c >> d;
    //逐一尝试
    for (double i = -100.00; i < 100.00; i++)
    {
        //二分法查找i~i+1内是否有0点
        if (f(i) * f(i + 1) <= 0)
        {
            //可能i是0点
            if (f(i) == 0)
            {
                cout << fixed << setprecision(2) << i << " ";
                num++;
            }
            //或者i+1是0点，但是i和i+1不可能都是0点，题干说的
            else if (f(i + 1) == 0)
            {
                //保留两位小数
                cout << fixed << setprecision(2) << i + 1 << " ";
                i++;
                num++;
            }
            else
            {
                //或者在i和i+1区间内
                double l = i, r = i + 1;
                double m = (l + r) / 2;
                //不断二分直至题干要求的精度
                while (r - l >= 0.01)
                {
                    if (f(l) * f(m) <= 0)
                    {
                        r = m;
                    }
                    else
                    {
                        l = m;
                    }
                    m = (l + r) / 2;
                }
                cout << fixed << setprecision(2) << m << " ";
                num++;
            }
        }
        //找到3个了就退出
        if (num >= 3)
        {
            cout << endl;
            break;
        }
    }
    system("pause");
    return 0;
}