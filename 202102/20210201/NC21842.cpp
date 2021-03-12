#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, x2, x3, x4;
    int y1, y2, y3, y4;
    cin >> x1 >> x2 >> x3 >> x4;
    cin >> y1 >> y2 >> y3 >> y4;
    int length[7];
    length[1] = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    length[2] = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
    length[3] = (x1 - x4) * (x1 - x4) + (y1 - y4) * (y1 - y4);
    length[4] = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
    length[5] = (x2 - x4) * (x2 - x4) + (y2 - y4) * (y2 - y4);
    length[6] = (x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4);
    sort(length + 1, length + 7);
    int num = 0;
    for (int i = 1; i < 7; i++)
    {
        for (int j = i + 1; j < 7; j++)
        {
            if (length[i] == length[j])
            {
                num++;
            }
        }
    }
    if (num == 7)
    {
        cout << "It's a square" << endl;
    }
    else
        cout << "Not a square" << endl;
    system("pause");
    return 0;
}
