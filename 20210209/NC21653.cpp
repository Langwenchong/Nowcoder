#include <bits/stdc++.h>
#define LL long long
#define INF 99999999999999

using namespace std;
const int N = 1e5 + 7;

int f(int a[], int i, int j)
{
    LL sum = 0;
    //必须是从最小行到最大行，所以比较起点和终点x
    int begin = min(i, j); //起点行数
    int end = max(i, j);   //终点行数
    while (begin <= end)
    {
        sum += a[begin]; //求解跨行的值之和
        begin++;
    }
    return sum;
}
int main()
{
    int a[N], sx, sy, ex, ey, n;
    cin >> n;
    cin >> sx >> sy >> ex >> ey;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    LL y = abs(ey - sy) + 1;    //跨的行数，细节：取绝对值后必须加1
    LL ans = INF;               //一开始初始化ans为最大值无穷
    for (int i = 0; i < n; i++) //遍历所有行，算的时候必须经过这个行
    {
        LL sum = y * a[i];   //横向相加
        sum += f(a, i, sx);  //以sx为起点，竖向相加
        sum -= a[i];         //去掉当前行的值，因为上面已经加过了
        sum += f(a, i, ex);  //ex为起点，竖向相加
        sum -= a[i];         //去掉当前行的值，因为上面已经加过了（最终以sx,ex为两端点，呈U型走向）
        ans = min(ans, sum); //更新最小值
    }
    cout << ans << endl;
    system("pause");
    return 0;
}