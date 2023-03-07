
// Recursive 
bool isBipartite(int u, vector<int>& colored, vector<vector<int>>& adj, int color) {
    colored[u] = color;
    for(int v : adj[u]) {
        if(colored[v] == -1 && !isBipartite(v, colored, adj, 1 - color)) return false;
        else if(colored[v] == color) return false;
    }
    return true;
}

//Iterative

bool isBipartite(int src, vector<vector<int>>& g, vector<int>& colored) {
	queue<pair<int,int>> q; // node, color
	q.push({src, 0});
	colored[src] = 0;
	while(!q.empty()) {
		auto [u, color] = q.front(); q.pop();
		for(int v : g[u]) {
			if(colored[v] == -1) {
				q.push({v, 1 - color});
				colored[v] = 1 - color;
			}else if(colored[v] == color) return false;
		}
	}
	return true;
}


