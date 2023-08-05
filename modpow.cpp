const int M = 1e9 + 7;
int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}
int diff(int a, int b) {
    return sum(a, M - b);
}
int mult(int a, int b) {
    return a * 1ll * b % M;
}
int modpow(int n, int k) {
    if(k == 0)
        return 1;
 
    int pw = pow2(n, k / 2);
    pw = mul(pw, pw);
 
    return (k % 2 == 0 ? pw : mul(pw, n));
}
