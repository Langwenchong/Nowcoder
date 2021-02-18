#include <bits/stdc++.h>
using namespace std;

const int N = 2010;
//c[i][j]表示的是Cij取余K的余数
int c[N][N];
//s[i][j]表示的是Cij中是k整数倍的个数
int s[N][N];

int main()
{
    int t, k;
    cin >> t >> k;
    //对每种情况的c[i][j]进行预处理检验其模k的余数
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            //如果j是0，那么c[i][j]一定是1
            if (!j)
                c[i][j] = 1 % k;
            else
            {
                //否则按照递推式由前两项的和推得的结果c[i][j]模k记录余数
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % k;
            }
            //如果刚好c[i][j]是0，那么也就是说此时的Cij情况是k的整数倍
            if (!c[i][j])
                //那么就增加一种整除k的情况
                s[i][j] = 1;
        }
    }
    //整理对于不同的i,j能够整除k的情况个数
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i)
                s[i][j] += s[i - 1][j];
            if (j)
                s[i][j] += s[i][j - 1];
            //这里要注意如果i,j都是非零，那么前面的两次累加，多加了一次s[i-1][j-1]，要减去一次
            if (i && j)
                s[i][j] -= s[i - 1][j - 1];
        }
    }
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        //直接输出事先打表出的不同i,j对应的整除k的情况数量即可
        cout << s[n][m] << endl;
    }
    system("pause");
    return 0;
}