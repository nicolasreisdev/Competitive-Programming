#include <bits/stdc++.h>
using namespace std;

bool conf(string x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == '(' || x[i] == '[')
        {
            for (int j = i + 1; j < x.size(); j++)
            {
                if (x[j] == ')' && x[i] == '(')
                {
                    x.erase(x.begin() + j);
                    x.erase(x.begin() + i);
                    return conf(x);
                }
                if (x[j] == ']' && x[i] == '[')
                {
                    x.erase(x.begin() + j);
                    x.erase(x.begin() + i);
                    return conf(x);
                }
            }
        }
    }
    if (x.empty())
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    string x;
    cin.ignore();
    for (int i = 0; i < n; i++){
        getline(cin,x);
        if (conf(x))cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}