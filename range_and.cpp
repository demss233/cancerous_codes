const int NAX  = 205000;
const int BIT = 32;

int pref[BIT][NAX];
void precompute(vector<int> v, int n) {
    for (int i = 0; i < BIT; i++) {
        pref[i][0] = ((vec[0] >> i) & 1);
        for (int j = 1; j < n; j++) {
            pref[i][j] = ((vec[j] >> i) & 1);
            pref[i][j] += pref[i][j - 1];
        }
    }
}

int query(int l, int r) {
    int ans = 0;
    for (int i = 0; i < BIT; i++) {
        int x;
        if (l == 0) x = pref[i][r];
        else x = pref[i][r] - pref[i][l - 1];
        if (x == r - l + 1)
            ans = (ans | (1 << i));
    }

    return ans;
}
