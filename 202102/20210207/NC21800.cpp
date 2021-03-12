#include <bits/stdc++.h>
using namespace std;

int num = 0;      //答案初始化
int x[55], y[55]; //x,y坐标存储

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> y[i];
    }
    if (n <= 3)
    {
        //点数少于三个必定可以全部射中，即两个点做x轴，第三个点引垂线做y轴即可
        cout << n << endl;
        system("pause");
        return 0;
    }
    //点数多于3个
    for (int i = 1; i <= n; i++)
    {
        //先选一个点i
        for (int j = 1; j <= n; j++)
        {
            //和j不同的点i，ij组成x轴
            if (i == j)
                continue;
            for (int k = 1; k <= n; k++)
            {
                //k不同于i,j，引垂线垂直于ij作为y轴
                if (k == i || k == j)
                    continue;
                int ans = 3;
                for (int f = 1; f <= n; f++)
                {
                    //检验剩余的f点，肯定是不同于i,j,k
                    if (f == i || f == j || f == k)
                        continue;
                    //在y轴延长线上，使用向量检查
                    int vec1_x = x[i] - x[j]; //向量1（ij向量）X
                    int vec1_y = y[i] - y[j]; //向量1Y
                    int vec2_x = x[k] - x[f]; //向量2（kf向量)X
                    int vec2_y = y[k] - y[f]; //向量2Y
                    //向量检验：X,Y向量满足x1x2+y1y2=0即证明在
                    if (vec1_x * vec2_x + vec1_y * vec2_y == 0)
                        //f添加
                        ans++;
                    //或者f与组成的x轴共线，使用斜率检验
                    else if ((x[i] - x[f]) * (y[f] - y[j]) == (x[f] - x[j]) * (y[i] - y[f]))
                        ans++;
                }
                num = max(num, ans);
            }
        }
    }
    cout << num << endl;
    system("pause");
    return 0;
}