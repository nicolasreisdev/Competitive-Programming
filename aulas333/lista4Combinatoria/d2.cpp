#include <bits/stdc++.h>
using namespace std;

vector<int> bin(vector<int> v, int n)
{
    vector<int> res;
    int carry = 0;
    for (int i = 0; i < v.size(); i++)
    {
        carry += v[i] * n;
        res.push_back(carry % 10);
        carry /= 10;
    }
    while (carry)
    {
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<int> v;
        v.push_back(1);
        for (int i = n + 2; i < n * 2; i++)
            v = bin(v, i);
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i];
        cout << endl;
        cin >> n;
    }

    return 0;
}