#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, m, n;
    while (cin >> w >> m >> n)
    {
        //m必须保证小于n
        if (m > n)
        {
            int tmp = n;
            n = m;
            m = tmp;
        }
        //特例
        if (m == n)
        {
            cout << 0 << endl;
            return 0;
        }
        int i = 0;
        int j = 0;
        int num = 1;
        //位置1用(a,b)，位置二用(c,d)
        int a, b, c, d;
        //是否向右填写
        bool dirr = true;
        while (num <= n)
        {
            //找到了位置记录下来
            if (num == m)
            {
                a = i;
                b = j;
            }
            if (num == n)
            {
                c = i;
                d = j;
            }
            num++;
            if (dirr)
            {
                j++;
            }
            else
            {
                j--;
            }
            //切换方向的条件
            if (j == w)
            {
                dirr = false;
                i++;
                j = w - 1;
            }
            if (j == -1)
            {
                j = 0;
                dirr = true;
                i++;
            }
        }
        //曼哈顿距离计算公式
        cout << abs(a - c) + abs(b - d) << endl;
    }
    // system("pause");
    return 0;
}