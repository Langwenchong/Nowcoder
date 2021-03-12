#include <bits/stdc++.h>
using namespace std;

struct Student
{
    int Ch;
    int Math;
    int Eng;
    int sum;
    int id;
} s[305];

bool cmp(Student a, Student b)
{
    if (a.sum != b.sum)
    {
        return a.sum > b.sum;
    }
    else
    {
        if (a.Ch != b.Ch)
        {
            return a.Ch > b.Ch;
        }
        else
        {
            return a.id < b.id;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i].Ch >> s[i].Math >> s[i].Eng;
        s[i].id = i;
        s[i].sum = s[i].Ch + s[i].Math + s[i].Eng;
    }
    sort(s + 1, s + n + 1, cmp);
    for (int i = 1; i <= 5; i++)
    {
        cout << s[i].id << " " << s[i].sum << endl;
    }
    system("pause");
    return 0;
}