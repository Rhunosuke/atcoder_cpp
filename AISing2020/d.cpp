#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
#define reps1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
using Ml = map<ll, ll>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
ll const DIGIT = 2 * 1e5;

ll mod_pow(ll a, ll n, ll p) {
  if (n == 0) return 1 % p;
  if (n == 1) return a % p;
  if (n % 2 == 1) return (mod_pow(a, 1, p) * mod_pow(a, n-1, p)) % p;
  ll t = mod_pow(a, n / 2, p);
  return (t * t) % p;
}

int main() {
  ll n;
  string x;
  cin >> n >> x;

  bitset<DIGIT> bs2(x);
  ll cnt = bs2.count();

  ll plus_mod = 0;
  ll minus_mod = 0;
  rep(i, n) {
    if (x[n-1-i] - '0') {
      plus_mod = (plus_mod + mod_pow(2, i, cnt+1)) % (cnt+1);
      if (cnt != 1) minus_mod = (minus_mod + mod_pow(2, i, cnt-1)) % (cnt-1);
    }
  }

  rep(i, n) {
    ll mod;
    if (x[i] == '1') {
      if (cnt == 1) {
        cout << 0 << endl;
        continue;
      }
      mod = (minus_mod - mod_pow(2, n-1-i, cnt-1)) % (cnt-1);
      if (mod < 0) mod += (cnt-1);
    } else {
      mod = (plus_mod + mod_pow(2, n-1-i, cnt+1)) % (cnt+1);
      if (mod < 0) mod += (cnt+1);
    }

    ll ans = 1;
    while(mod != 0) {
      mod %= __builtin_popcountll(mod);
      ans++;
    }
    cout << ans << endl;
  }

  return 0;
}
