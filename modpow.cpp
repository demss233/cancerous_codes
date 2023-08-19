const int mod = 1e9 + 7;

int modpow(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % mod, e /= 2)
        if (e & 1) ans = ans * b % mod;
    return ans;
}
