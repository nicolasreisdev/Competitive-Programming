    #include <bits/stdc++.h>
    using namespace std;

    int main(){
        int n;cin >> n;
        for(int i = 0; i < n;i++){
            bool a = false;
            int cont = 0;
            string x, y;cin >> x;
            y = x;
            reverse(y.begin(), y.end());
            if(x == y)a = true;
            while(!a){
                cont++;
                long long z = stoll(x) + stoll(y);
                x = to_string(z);
                y = x;
                reverse(y.begin(), y.end());
                if(x == y)a = true;
            }
            cout << cont << " " << y << endl;
        }
        return 0;
    }