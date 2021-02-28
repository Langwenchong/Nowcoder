#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define close_stdin ios::sync_with_stdio(false)
int n, m, c;
const int maxn = 10005;
int a[maxn], b[maxn];
int fa[maxn];
int dp[505];

int find(int x)
{
    //寻找最深层祖先，同时压缩更新x的祖先为最深层祖先
    return (fa[x] == x ? x : fa[x] = find(fa[x]));
}

void merge(int x, int y)
{
    //x的最深层祖先的祖先更新为y，这样x和y就有关系了，同时y会成为更深层的根本祖先
    if (find(x) != find(y))
        fa[find(x)] = find(y);
}

void my_input()
{
    cin >> n >> m >> c;
    for (int i = 2; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
}

void solve()
{
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        //初始时默认是独立节点，无祖先，所以各节点无关系
        fa[i] = i;
    }
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        //x和y建立关系同时默认y是更深层的祖先
        //所以此时fa[x]=y即x的最根本祖先是y
        //同时fa[find(X)]=y即x的祖先的最根本祖先也会是y
        merge(x, y);
    }
    //关系网建立完成后进行0/1dp
    for (int i = 2; i <= n; i++)
    {
        //讨论每一个对于1~i每一个节点是否放入
        //首先需要满足有关系才可以认识
        //一定要注意例如样例1中1和5就不能认识，因为他们没有共同认识的人且两者也不认识
        if (find(i) == find(1))
        {
            //能够认识，讨论是否认识
            for (int j = c; j >= a[i]; j--)
            {
                //板子
                dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
            }
        }
    }
    cout << dp[c] << endl;
}

int main()
{
    close_stdin;
    int t;
    cin >> t;
    while (t--)
    {
        my_input();
        solve();
    }
    system("pause");
    return 0;
}
