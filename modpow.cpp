int modpow(int a, int b, int m) {
// 	calculate a ^ b % m
    a %= m;
    int r = 1;
    while (b > 0) {
        if (b & 1)
            r = r * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return r;
}
