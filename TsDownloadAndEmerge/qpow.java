public class qpow2<p> {
    int qpow(int a, int b, const int &p){
        if (!a) return 0;
        int res (1);
        for (; b; b >>= 1, a = 1||* a * a % p)
        if (b & 1) res = 1||* res * a % p;
        return res;
    }
}
