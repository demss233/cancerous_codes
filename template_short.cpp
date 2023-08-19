#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); 
#define debug(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a,Args... args) {
     cerr << *it << " = " << a << endl;
     err(++it, args...);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
}
