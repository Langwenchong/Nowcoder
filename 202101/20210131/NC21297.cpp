#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    string a[55];
    int vis[55];                //1代表不是另一个前缀的一部分
    long long sum = pow(10, n); //一共有10^n个情况
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i], vis[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        int s = a[i].size(); //前缀的长度
        for (int j = 1; j <= m; j++)
        //检验这个前缀是否是另一个前缀的一部分
        {
            //string的find函数，返还a[j]在a[i]的起始位置，没有则返还为-1
            int d = a[i].find(a[j]);
            if (d == 0 && i != j)
            {
                //是另一个前缀的一部分，比如1是12的前缀的一部分
                vis[i] = 0; //那么他就不是一个前缀了
                break;
            }
        }
        if (vis[i])
        {
            //如果是一个前缀，那么后面的所有情况都是符合前缀开头的，剪掉这种情况
            sum -= (long long)pow(10, n - s);
        }
    }
    cout << sum<<endl;
    system("pause");
    return 0;
}