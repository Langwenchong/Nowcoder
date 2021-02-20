#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    //存入牛数量，和最小距离
    cin >> n >> d;
    int arr[10000] = {}; //题干的最小距离
    int ans[10000] = {}; //答案数组
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    //第一个牛就做到题干给出的位置即可
    ans[1] = arr[1];
    for (int i = 2; i <= n; i++)
    {
        //其他的牛先做到题干给出位置
        ans[i] = arr[i];
        //排序
        sort(arr + 1, arr + i);
        for (int j = 1; j < i; j++)
        {
            //如果第i头牛做的位置在j的内侧且不满足条件，那么就只能做到a[j]+d
            //同理如果坐到外侧不满足条件，也是做到a[j]+d
            if (abs(arr[i] - arr[j]) < d)
            {
                arr[i] = arr[j] + d;
                ans[i] = arr[i];
            }
            else
                //满足条件直接坐下即可
                ans[i] = arr[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}