#include<bits/stdc++.h>
using namespace std;

int main()
{
    double mat[2][3];

    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            cin >> mat[i][j];

    double aux = mat[1][0]/mat[0][0];
    for(int i = 0 ; i < 3 ; i++)
    {
        mat[1][i] -= (mat[0][i]*(aux));
    } 

    double x, y;

    if(mat[1][0] == 0 && mat[1][1] == 0)
    {

        cout << "sistema indeterminado\n";
        return 0;
    }
    else
    {
        y = mat[1][2]/mat[1][1];
        x = (mat[0][2]-mat[0][1]*y)/mat[0][0];
        cout << fixed << setprecision(2) << x << " " << fixed << setprecision(2) << y << endl;
    }

    return 0;
}