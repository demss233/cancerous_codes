template <int MOD>
class Modular {
private:
    int val;
    static const int mod = MOD;
    Modular inverse (const Modular &A) {
        Modular u = 0, v = 1;
        int a = A.val;
        int b = mod;
        while(a != 0) {
            int t = b / a;
            b -= t * a; swap(b, a);
            u -= t * v; swap(u, v);
        }
        return (b == 1) ? u : 0;
    }
public:
    explicit operator int() const {
        return val;
    }
    Modular() { val = 0; }
    Modular(ll x) {
        val = x % mod;
        if(val < 0) val += mod;
    }
    friend bool operator==(const Modular &A, const Modular &B) { return A.val == B.val; }
    friend bool operator!=(const Modular &A, const Modular &B) { return A.val != B.val; }
    friend bool operator<(const Modular &A, const Modular &B) { return A.val < B.val; }
    friend bool operator>(const Modular &A, const Modular &B) { return A.val > B.val; }
    Modular &operator+=(const Modular &A) { val += A.val; val %= mod; return *this; }
    Modular &operator-=(const Modular &A) { val -= A.val; if(val < 0) val += mod; return *this; }
    Modular &operator*=(const Modular &A) { val = (int)((ll)val * A.val % mod); return *this; }
    Modular &operator/=(const Modular &A) { return *this *= inverse(A); }
    Modular operator-() const { return Modular(-val); }
    Modular &operator++() { return *this += 1; }
    Modular &operator--() { return *this -= 1; }
    friend Modular operator+(Modular A, const Modular &B) { return A += B; }
    friend Modular operator-(Modular A, const Modular &B) { return A -= B; }
    friend Modular operator*(Modular A, const Modular &B) { return A *= B; }
    friend Modular operator/(Modular A, const Modular &B) { return A /= B; }
    friend istream& operator>>(istream& stream, Modular &A) { ll x; stream >> x; A = Modular(x); return stream; }
    friend ostream& operator<<(ostream& stream, Modular &A) { return stream << A.val; }
};

const int MOD = 1e9 + 7;
