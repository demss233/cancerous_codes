int modpow(int b, int e) {
    int ans = 1;
    for (; e; b = b * b % P, e /= 2)
        if (e & 1) ans = ans * b % P;
    return ans;
}
