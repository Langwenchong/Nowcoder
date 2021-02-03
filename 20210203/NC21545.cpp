#include <bits/stdc++.h>
using namespace std;
int arr[55];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n); //要将初始位置从左到右排序
    int x;
    cin >> x;
    int cnt = arr[n] - arr[1];
    int left, right;
    for (int i = 1; i < n; i++)
    {
        //i右边的所有牛左移，i自身以及i左边的所有牛右移
        //那么最左边界值只能在1右移和i作业之间产生
        left = min(arr[1] + x, arr[i + 1] - x);
        //那么最右边界值只能在1右移和i作业之间产生
        right = max(arr[n] - x, arr[i] + x);
        if (right - left < cnt)
        //如果距离更短，更新
        {
            cnt = right - left;
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}