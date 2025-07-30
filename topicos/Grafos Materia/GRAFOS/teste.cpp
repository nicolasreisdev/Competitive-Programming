for(int i = 0; i < n-1;i+=2){
    for(auto e: arestas){
        if(dist[e.first] + e.second < dist[e.second]){
            dist[e.second] = dist[e.first] + e.second;
        }
    }
}