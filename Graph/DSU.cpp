class DSU {
public:
   vector<int> par, rank, size;
   DSU(int n) {
       par.resize(n,0);
       rank.resize(n, 0);
       size.resize(n, 1);
       iota(par.begin(), par.end(), 0);
   }


   int find(int x) {
       return par[x] == x ? x : find(par[x]);
   }


   bool un(int u, int v) {
       int x = find(u), y = find(v);
       if(x == y) return false;
       if(rank[x] < rank[y]) swap(x, y);
       else if(rank[x] == rank[y]) rank[x]++;
       par[y] = x;
       size[x] += size[y];
       return true;
   }
};
