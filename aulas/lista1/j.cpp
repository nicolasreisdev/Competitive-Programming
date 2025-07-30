#include <bits/stdc++.h>
using namespace std;

bool conf(string x){
    stack<char> s;
    for (int i = 0; i < x.size(); i++){
        if (x[i] == '(' || x[i] == '['){
            s.push(x[i]);
        }
        else{
            if (s.empty())
                return false;
            if (x[i] == ')' && s.top() == '(')
                s.pop();
            else if (x[i] == ']' && s.top() == '[')
                s.pop();
            else
                return false;
        }
    }
    if (s.empty())
        return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    string u;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, u);
        if (conf(u))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}