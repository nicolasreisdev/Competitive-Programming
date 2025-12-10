#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
    {

        // Estrutura do evento: {tempo, tipo_evento, indice_pessoa}
        // Usamos std::tuple para armazenar os 3 valores.
        using Event = tuple<int, int, int>;

        //  Compara o tempo (int, índice 0)
        //  Compara o tipo_evento (int, índice 1) em caso de empate
        priority_queue<Event, vector<Event>, greater<Event>> pq;

        for (int i = 0; i < persons.size(); ++i)
        {
            pq.emplace(persons[i], 1, i);
        }

        for (const auto &flower : flowers)
        {
            int start = flower[0];
            int end = flower[1];
            // Evento de início (Bloom): {tempo de inicio, tipo 0, -1}
            pq.emplace(start, 0, -1);
            // Evento de fim (Die): {tempo de fim, tipo 2, -1}
            pq.emplace(end, 2, -1);
        }

        // Processar os Eventos 
        vector<int> result(persons.size());
        int currentBlooms = 0;

        while (!pq.empty())
        {
            auto [time, type, index] = pq.top();
            pq.pop();

            if (type == 0)
            { 
                currentBlooms++;
            }
            else if (type == 2)
            { 
                currentBlooms--;
            }
            else
            { 
                result[index] = currentBlooms;
            }
        }

        return result;
    }
};