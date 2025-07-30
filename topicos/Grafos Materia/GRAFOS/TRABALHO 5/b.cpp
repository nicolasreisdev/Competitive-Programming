/*
README
Aluno: Nicolas Eliel dos Reis Silva - Matrícula: 112703
Fontes de consulta: http://shygypsy.com/tools/ e conhecimentos adquiridos em INF 333
*/

#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
#define pb push_back
#define rm pop_back
#define f first
// #define s second
#define sz size
#define in insert

typedef pair<int, int> p;
typedef long long ll;
const int MAX = 0x3f3f3f3f;
const ll LMAX = 0x3f3f3f3f3f3f3f3f;

// CÓDIGO DISPONIBILIZADO EM http://shygypsy.com/tools/

/**
 *   //////////////////
 *   // MAXIMUM FLOW //
 *   //////////////////
 *
 * This file is part of my library of algorithms found here:
 *      http://www.palmcommander.com:8081/tools/
 * LICENSE:
 *      http://www.palmcommander.com:8081/tools/LICENSE.html
 * Copyright (c) 2004
 * Contact author:
 *      igor at cs.ubc.ca
 **/

/****************
 * Maximum flow * (Ford-Fulkerson on an adjacency matrix)
 ****************
 * Takes a weighted directed graph of edge capacities as an adjacency
 * matrix 'cap' and returns the maximum flow from s to t.
 *
 * PARAMETERS:
 *      - cap (global): adjacency matrix where cap[u][v] is the capacity
 *          of the edge u->v. cap[u][v] is 0 for non-existent edges.
 *      - n: the number of vertices ([0, n-1] are considered as vertices).
 *      - s: source vertex.
 *      - t: sink.
 * RETURNS:
 *      - the flow
 *      - fnet contains the flow network. Careful: both fnet[u][v] and
 *          fnet[v][u] could be positive. Take the difference.
 *      - prev contains the minimum cut. If prev[v] == -1, then v is not
 *          reachable from s; otherwise, it is reachable.
 * DETAILS:
 * FIELD TESTING:
 *      - Valladolid 10330: Power Transmission
 *      - Valladolid 653:   Crimewave
 *      - Valladolid 753:   A Plug for UNIX
 *      - Valladolid 10511: Councilling
 *      - Valladolid 820:   Internet Bandwidth
 *      - Valladolid 10779: Collector's Problem
 * #include <string.h>
 * #include <queue>
 **/

#include <string.h>

// the maximum number of vertices
#define NN 500

// adjacency matrix (fill this up)
int cap[NN][NN];

// flow network
int fnet[NN][NN];

// BFS
int q[NN], qf, qb, prevF[NN];

int fordFulkerson(int n, int s, int t)
{
    // init the flow network
    memset(fnet, 0, sizeof(fnet));

    int flow = 0;

    while (true)
    {
        // find an augmenting path
        memset(prevF, -1, sizeof(prevF));
        qf = qb = 0;
        prevF[q[qb++] = s] = -2;
        while (qb > qf && prevF[t] == -1)
            for (int u = q[qf++], v = 0; v < n; v++)
                if (prevF[v] == -1 && fnet[u][v] - fnet[v][u] < cap[u][v])
                    prevF[q[qb++] = v] = u;

        // see if we're done
        if (prevF[t] == -1)
            break;

        // get the bottleneck capacity
        int bot = 0x7FFFFFFF;
        for (int v = t, u = prevF[v]; u >= 0; v = u, u = prevF[v])
            bot = min(bot, cap[u][v] - fnet[u][v] + fnet[v][u]);

        // update the flow network
        for (int v = t, u = prevF[v]; u >= 0; v = u, u = prevF[v])
            fnet[u][v] += bot;

        flow += bot;
    }

    return flow;
}

int main(){
    fastio;
    
    int t; cin >> t;

    while(t--){
        int n, m; cin >> n >> m;
        memset(cap, 0, sizeof(cap));
        int numVertices = m + 6 + 2; // participantes + tipos de camisa + fonte e sumidouro (0 fonte e m + 6 + 1 sumidouro)
        map<string, int> camisas;
        camisas["XS"] = m + 1;camisas["S"] = m + 2;camisas["M"] = m + 3;camisas["L"] = m + 4;camisas["XL"] = m + 5;camisas["XXL"] = m + 6;
        for(int i = 1; i <= m; i++){
            cap[0][i] = 1; // para cada pessoa temos que ela pode ter apenas 1 camisa (fonte -> pessoa)
        }
        for(int i = m + 1; i <= m + 6; i++){
            cap[i][m + 6 + 1] = n / 6; // cada tipo de camisa tem que ter n / 6 camisas (camisa -> sumidouro)
        }
        for(int i = 1; i <= m;i++){
            string a, b; cin >> a >> b;
            cap[i][camisas[a]] = 1; // pessoa -> camisa
            cap[i][camisas[b]] = 1; // pessoa -> camisa
        }
        int ans = fordFulkerson(numVertices, 0, numVertices - 1); // fluxo máximo
        if(ans == m) cout << "YES" << endl; // se o valor que chega ao sumidouro for igual ao número de pessoas
        else cout << "NO" << endl;
    }

    return 0;
}