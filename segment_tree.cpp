struct segment_tree {
     const int inf = 1e18 + 7;
     vector<int> a, lazy;
     vector<bool> can;
     vector<ar<int, 3>> tree;
 
     segment_tree(vector<int> v) {
          int N = sz(v);
          a.resize(N);
          for(int i = 0; i < N; ++i) {
               a[i] = v[i];
          }
          tree.resize(4 * N); //somewhat equal to (1 << (1 << n))
          lazy = vector<int>(4 * N, 0);
          can = vector<bool>(4 * N, false);
     }
 
     void build(int lvl, int l, int r) {
          lazy[lvl] = 0;
          if(l == r) {
               tree[lvl][0] = a[l];
               tree[lvl][1] = a[l];
               tree[lvl][2] = a[l];
               return;
          }
          int mid = (l + r) / 2;
          build(2 * lvl + 1, l, mid);
          build(2 * lvl + 2, mid + 1, r);
          tree[lvl][0] = min(tree[2 * lvl + 1][0], tree[2 * lvl + 2][0]);
          tree[lvl][1] = max(tree[2 * lvl + 1][1], tree[2 * lvl + 2][1]);
          tree[lvl][2] = (tree[2 * lvl + 1][2] + tree[2 * lvl + 2][2]);
     }
 
     ar<int, 3> query(int lvl, int l, int r, int s, int e) {
          if(lazy[lvl] != 0) {
               tree[lvl][2] += lazy[lvl] * (r - l + 1);
               tree[lvl][0] += lazy[lvl];
               tree[lvl][1] += lazy[lvl];
               if(l != r) {
                    lazy[2 * lvl + 1] += lazy[lvl];
                    lazy[2 * lvl + 2] += lazy[lvl];
               }
               lazy[lvl] = 0;
          }
          if(l > r || s > r || e < l) 
               return {inf, -inf, 0};
          if(l >= s && r <= e) 
               return tree[lvl];
          int mid = (l + r) / 2;
          ar<int, 3> ll = query(2 * lvl + 1, l, mid, s, e);
          ar<int, 3> rr = query(2 * lvl + 2, mid + 1, r, s, e);
          ar<int, 3> tup = {min(ll[0], rr[0]), max(ll[1], rr[1]), ll[2] + rr[2]};
          return tup;
     }
 
     void update(int lvl, int l, int r, int si, int x) {
          if(l == r) {
               tree[lvl][0] = x;
               tree[lvl][1] = x;
               tree[lvl][2] = x;
               return;
          }
          int mid = (l + r) / 2;
          if(si <= mid) 
               update(2 * lvl + 1, l, mid, si, x);
          else
               update(2 * lvl + 2, mid + 1, r, si, x);
          tree[lvl][0] = min(tree[2 * lvl + 1][0], tree[2 * lvl + 2][0]);
          tree[lvl][1] = max(tree[2 * lvl + 1][1], tree[2 * lvl + 2][1]);
          tree[lvl][2] = tree[2 * lvl + 1][2] + tree[2 * lvl + 2][2];
     }
 
     void update(int lvl, int l, int r, int s, int e, int x) {
          if(lazy[lvl] != 0) {
               tree[lvl][0] += lazy[lvl];
               tree[lvl][1] += lazy[lvl];
               tree[lvl][2] += lazy[lvl] * (r - l + 1);
               if(l != r) {
                    lazy[2 * lvl + 1] += lazy[lvl];
                    lazy[2 * lvl + 2] += lazy[lvl];
               }
               lazy[lvl] = 0;             
          }
          if(l > r || s > r || e < l) 
               return;
          if(s <= l && e >= r) {
               tree[lvl][2] += x * (r - l + 1);
               tree[lvl][0] += x;
               tree[lvl][1] += x;
               if(l != r) {
                    lazy[2 * lvl + 1] += x;
                    lazy[2 * lvl + 2] += x;
               }
               return;
          }
          int mid = (l + r) / 2;
          update(2 * lvl + 1, l, mid, s, e, x);
          update(2 * lvl + 2, mid + 1, r, s, e, x);
          tree[lvl][0] = min(tree[2 * lvl + 1][0], tree[2 * lvl + 2][0]);
          tree[lvl][1] = max(tree[2 * lvl + 1][1], tree[2 * lvl + 2][1]);
          tree[lvl][2] = tree[2 * lvl + 1][2] + tree[2 * lvl + 2][2];
     } 
};
