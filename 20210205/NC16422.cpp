#include <bits/stdc++.h>
using namespace std;
string book[1005];

bool cmp(string a, string b)
{
    if (a.length() != b.length())
    {
        //a编号长度比b编号长度短
        return a.length() < b.length();
    }
    //否则按照字典序排序即可
    return a < b;
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        //存储图书馆的图书编号
        cin >> book[i];
    }
    //排序
    sort(book + 1, book + 1 + n, cmp);
    //检验q组借阅情况
    while (q--)
    {
        int len;
        string s;
        cin >> len >> s;
        //假设没有能借的图书
        int flag = 0;
        for (int i = 1; i <= n; i++)
        {
            //一定要注意细节，可能这次的图书编号比借阅图书编号短，那么就跳过检验，否则会越界
            if (book[i].length() >= s.length())
            {
                //裁剪出和借阅图书编号相同长度的图书编号后几位，如果相等
                if (book[i].substr(book[i].length() - len) == s)
                {
                    //返还这个书就是最短编号的可借阅图书
                    cout << book[i] << endl;
                    flag = 1;
                    break;
                }
            }
        }
        if (!flag)
        {
            //没找到返还-1
            cout << -1 << endl;
        }
    }
    system("pause");
    return 0;
}