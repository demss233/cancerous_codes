#include <bits/stdc++.h>
using namespace std;
#define ar array
#define ld long double
#define int long long
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define trace(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define fi first
#define se second
#define forn(i, j, n) for(int i = j; i < n; ++i)
#define forn_(i, j, n) for(int i = j; i >= n; --i)
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a,Args... args) {
     cerr << *it << " = " << a << endl;
     err(++it, args...);
}

int32_t main() {
     cin.tie(0)->sync_with_stdio(0); cin.exceptions(cin.failbit);

     int t = 1;
     // cin >> t;
     while(t--) {
          solve();
     }
}
//txdy
