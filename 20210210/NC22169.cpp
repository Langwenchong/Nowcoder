#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, tmp, num;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        tmp = 0;
        num = i;
        //将tmp按照数i的从后到前写一遍
        while (num != 0)
        {
            tmp *= 10;
            tmp += num % 10;
            num /= 10;
        }
        //如果一样，那么就是回文数
        if (tmp == i)
        {
            cout << i << endl;
        }
    }
    return 0;
    system("pause");
    return 0;
}