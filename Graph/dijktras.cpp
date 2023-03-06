typedef long long ll;

vector<ll> dijktras(int src, vector<vector<pair<int,int>>>& g) {
    int n = g.size();
    vector<ll> dist(n, LONG_MAX);
    
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
    pq.push({0, src});
    dist[src] = 0;
    
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(dist[u] < d) continue;
        for(auto [v, wt] : g[u]) {
            if(dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}