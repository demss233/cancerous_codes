int binpow(int a, int b) {
    int mul = 1;
    while (b > 0) {
        if (b & 1)
            mul = mul * a;
        a = a * a;
        b >>= 1;
    }
    return mul;
}
