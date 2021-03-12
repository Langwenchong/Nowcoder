#include <bits/stdc++.h>
using namespace std;
#define maxn 3000
int a[maxn], b[maxn], c[maxn];

int main()
{
    int n;
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        //寻找后来跑到前面穿的衣服，后面的不关心
        {
            if (a[i] == b[j])
            {
                //对于后来衣服穿在更前面的情况，那么至少需要i-j周才可以到
                c[i] = i - j;
                break;
            }
        }
    }
    int r = -1000000;
    for (int i = 1; i <= n; i++)
    {
        if (c[i] > r)
        {
            r = c[i];
        }
    }
    //注意要+1
    cout << r + 1 << endl;
    system("pause");
    return 0;
}