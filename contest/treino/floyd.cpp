#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rm pop_back
#define f first
#define s second
#define INF 99999

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 1e5 + 10;

int main()
{
    int n, m; cin >> m >> n;
    int dist[m][n];

    for (int k = 0; k < n; k++){
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++){
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < n; j++){
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INF && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    return 0;
}