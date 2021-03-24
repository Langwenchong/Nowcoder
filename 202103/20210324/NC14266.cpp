#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
struct Pad
{
    //存储ram和速度
    int a;
    int b;
} pad[N];

bool cmp(Pad x, Pad y)
{
    //将内存从大到小排序
    return x.a > y.a;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> pad[i].a >> pad[i].b;
    }
    //排序后最靠前的是内存最大的
    sort(pad + 1, pad + 1 + n, cmp);
    int ans = 0;
    //记录最大的速度
    int maxb = 0;
    for (int i = 1; i <= n; i++)
    {
        //更新最大速度
        if (pad[i].b > maxb)
            maxb = pad[i].b;
        else
        {
            //此时pad[i]被完爆了，因为他一定比pad[i-1]之前的ram小
            //此时速度又小了，那么就被完爆了
            ans++;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}