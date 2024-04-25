#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define sz size
#define in insert


typedef pair<int,int>p;
typedef long long ll;
const int MAX = 1e5 + 10;
const int MIN = 0;

#include <bits/stdc++.h>

int mdc(int a, int b)
{
    if (b == 0)
        return a;
    return mdc(b, a % b);
}

int MMC(int a, int b)
{
    return a * b / mdc(a, b);
}

int main()
{
    int a,b,c; cin >> a >> b >> c;
    cout << MMC(MMC(a,b),c) << endl;

    return 0;
}