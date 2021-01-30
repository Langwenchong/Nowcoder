#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int matrix[1010][1010];
    memset(matrix, 0, sizeof matrix);
    int x = 2, y = 0;
    int dir_x = -1, dir_y = 1;
    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            x += dir_x;
            y += dir_y;
            matrix[x][y] = ++tmp;
        }
        if (dir_x == 1)
        {
            x += 2;
            y -= 1;
        }
        else
        {
            x -= 1;
            y += 2;
        }
        dir_x = -dir_x;
        dir_y = -dir_y;
    }
    if (n % 2 == 0)
    {
        x -= 1;
        y += 1;
    }
    else
    {
        x += 1;
        y -= 1;
    }

    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            x += dir_x;
            y += dir_y;
            matrix[x][y] = ++tmp;
        }
        if (dir_x == 1)
        {
            x += 1;
        }
        else
        {
            y += 1;
        }
        dir_x = -dir_x;
        dir_y = -dir_y;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < n; j++)
            cout << matrix[i][j] << " ";

        cout << matrix[i][n] << endl;
    }
    system("pause");
    return 0;
}