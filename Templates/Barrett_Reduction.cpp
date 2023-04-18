#include <bits/stdc++.h>
using namespace std;

class FastMod {
 private:
  using ull = unsigned long long;
  using L = __uint128_t;
  ull b, m;

 public:
  FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
  ull reduce(ull a) {
    ull q = (ull)((L(m) * a) >> 64);
    ull r = a - q * b;
    return r >= b ? r - b : r;
  }
};

int main() {
  int M = 1e9 + 7;
  FastMod F(M);
  unsigned long long x;
  cin >> x;
  // Mengeluarkan x mod M untuk semua:
  // * 2 <= M <= 1000000007
  // * 0 <= x < M^2
  cout << F.reduce(x) << "\n";  
}