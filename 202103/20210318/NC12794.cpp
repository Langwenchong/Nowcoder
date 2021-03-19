#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0;
    double x0, x1, x2, y0, y1, y2;
    while (cin >> x0)
    {
        cin >> y0 >> x1 >> y1 >> x2 >> y2;
        if (x0 == 0 && !x1 && !x2 && !y1 && !y0 && !y2)
            break;
        t++;
        double r = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
        double ans1 = r * acos(((x1 - x0) * (x2 - x0) + (y1 - y0) * (y2 - y0)) / (r * r)); //求弧长公式
        double a = x1, b = y1, c, d, ans2 = 0;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> c >> d;
            ans2 += sqrt((a - c) * (a - c) + (b - d) * (b - d));
            a = c, b = d;
        }
        ans2 += sqrt((a - x2) * (a - x2) + (b - y2) * (b - y2));
        cout << "Case #" << t << ": ";
        if (ans1 < ans2)
            cout << "Stick to the Circle."
                 << "\n\n";
        else
            cout << "Watch out for squirrels!"
                 << "\n\n";
    }
    system("pause");
    return 0;
}