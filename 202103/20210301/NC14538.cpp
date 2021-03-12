#include <bits/stdc++.h>
using namespace std;

int main()
{
    //一定要注意首位不可以是0但是其他位都是可以从0开始的
    for (int i = 1000; i <= 9999; i++)
    //前四位翻转即为后四位
    {
        string str = "";
        int t = i;
        while (t != 0)
        {
            //强制转换后，拼接
            str = char(t % 10 + '0') + str + char(t % 10 + '0');
            //除10取下一位
            t /= 10;
        }
        cout << str << endl;
    }
    system("pause");
    return 0;
}