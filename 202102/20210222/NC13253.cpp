#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string t, s, tmp;
    cin >> n;
    cin >> t;
    //逐一尝试1~n的k进制串表示
    for (int k = 2; k < 17; k++)
    {
        //记录1~n的k进制串
        s = "";
        for (int i = 1; i <= n; i++)
        {
            //从1~n枚举整数值
            int num = i;
            //临时存储i的k进制串，最后不断拼接成为1~n的k进制串
            tmp = "";
            //使用循环取余的方法模拟转换进制
            while (num)
            {
                int cnt = num % k;
                if (cnt < 10)
                {
                    tmp += cnt + '0';
                }
                else
                {
                    //大于9的时候用ABCDE等表示
                    tmp += 'A' + cnt - 10;
                }
                num /= k;
            }
            //最后得到的是反的，要翻转一下字符串
            reverse(tmp.begin(), tmp.end());
            s += tmp;
        }
        //find()函数寻找子串在母串中出现的第一次位置，没有则返还-1
        if (s.find(t) != -1)
        {
            cout << "yes" << endl;
            system("pause");
            return 0;
        }
    }
    cout << "no" << endl;
    system("pause");
    return 0;
}