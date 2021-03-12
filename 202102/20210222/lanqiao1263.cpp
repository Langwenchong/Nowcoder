#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        //计算一行的字符串长度
        int len = m + n - 1;
        //左、右端起始位置
        int l = 1;
        int r = len - m + 1;
        char s[len + 5];
        //上半部分包括中间行的打印
        for (int i = 0; i < (n - 1) / 2 + 1; i++)
        {
            //初始化全部填写.
            memset(s, '.', sizeof(s));
            int ll = l;
            int rr = r;
            //*替换.
            for (int i = 0; i < m; i++)
            {
                s[ll + i] = '*';
                s[rr + i] = '*';
            }
            //输出这一行
            for (int i = 1; i <= len; i++)
            {
                cout << s[i];
            }
            //下一行左起始位置右移，右起始位置左移
            l++;
            r--;
            //换行输出下一行
            cout << endl;
        }
        // l = (n - 1) / 2;会wa
        // r = (len - 1) / 2 + 1;会wa，貌似是起点位置不够具有普遍性
        //正确的起始位置，就是相较于刚刚的中间行的左右起始位置分别左移1个和右移1格
        l-=2;
        r+=2;
        //特判，不加貌似也对
        if(m==1){
            r=(len+1)/2+1;
        }
        //打印下半部分
        for (int i = 0; i < (n - 1) / 2; i++)
        {
            memset(s, '.', sizeof(s));
            int ll = l;
            int rr = r;
            for (int i = 0; i < m; i++)
            {
                s[ll + i] = '*';
                s[rr + i] = '*';
            }
            for (int i = 1; i <= len; i++)
            {
                cout << s[i];
            }
            l--;
            r++;
            cout << endl;
        }
    }
    // system("pause");
    return 0;
}