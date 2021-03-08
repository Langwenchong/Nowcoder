#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int _map[N][N];

void find(int a, int b, int c, int d)
{
    int sum = 0;
    for (int i = a; i <= c; i++)
    {
        for (int j = b; j <= d; j++)
        {
            if (_map[i][j])
                sum++;
        }
    }
    cout << sum << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> _map[i][j];
        }
    }
    while (m--)
    {
        int index;
        cin >> index;
        if (index == 1)
        {
            int x, y;
            cin >> x >> y;
            _map[x][y] = !_map[x][y];
        }
        else
        {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            find(a, b, c, d);
        }
    }
    system("pause");
    return 0;
}