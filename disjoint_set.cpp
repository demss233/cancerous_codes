struct disjoint_set {
     vector<int> parent, size;

     disjoint_set(int n) {
          parent = vector<int>(n + 1);
          iota(all(parent), 0);
          size = vector<int>(n + 1, 1);
     }    

     int find(int x) {
          if(parent[x] == x) return x;
          return parent[x] = find(parent[x]);
     }
     bool unite(int a, int b) {
          if(find(a) == find(b)) return 0;
          if(size[a] > size[b])
               parent[b] = a, size[a] += size[b];
          else 
               parent[a] = b, size[b] += size[a];
          return 1;
     }
}
