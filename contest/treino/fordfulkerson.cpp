int fordFulkerSon(vector<vector<int>> &g, int s, int d)
{
    vector<vector<int>> r = g; // grafo residual
    int pai[g.sz()];           // vetor de pais
    memset(pai, -1, sizeof pai);
    int fluxoMaximo = 0;
    while (true)
    {
        int dist[g.sz()]; // vetor de distancias
        memset(dist, MAX, sizeof(dist));
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        { // bfs
            int u = q.front();
            q.pop();
            for (int v = 0; v < g.sz(); v++)
            { // para cada vizinho
                if (r[u][v] > 0 && dist[v] == MAX)
                { // se tem capacidade e ainda nao foi visitado
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    pai[v] = u;
                }
            }
        }
        if (dist[d] == MAX)
            break;       // caso nao tenha caminho
        int fluxo = MAX; // fluxo inicial
        for (int v = d; v != s; v = pai[v])
        {                                     // percorre do alvo até a origem
            fluxo = min(fluxo, r[pai[v]][v]); // minimo(fluxo , capacidade)
        }
        // cout << "fluxo: " << fluxo << endl;
        for (int v = d; v != s; v = pai[v])
        { // percorre do alvo até a origem
            r[pai[v]][v] -= fluxo;
            r[v][pai[v]] += fluxo;
        }
        // cout << fluxo << endl;
        fluxoMaximo = max(fluxoMaximo, fluxo);
    }
    return fluxoMaximo;
}