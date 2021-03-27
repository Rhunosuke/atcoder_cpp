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

int main() {
  ll n;
  cin >> n;
  vector<bitset<32>> a(n);
  rep(i, n) {
    int inta;
    cin >> inta;
    a[i] = bitset<32>(inta);
  }

  if (n==1) {
    cout << a[0].to_ullong() << endl;
    return 0;
  }

  ll ans = INF;

  rep(bit, 1<<(n-1)) {
    vector<int> d(n-1);
    rep(i, n-1) if (bit & (1 << i)) {
      d[i] = 1;
    }

    ll groupnum = __builtin_popcount(bit) + 1;
    vector<bitset<32>> b(groupnum);

    ll si = 0, sj = 0;
    rep(i, n-1) {
      if (d[i] == 1) {
        repI(j, si, i+1) {
          b[sj] = b[sj] | a[j];
        }
        si = i+1;
        sj++;
      }
    }
    repI(i, si, n) {
      b[groupnum-1] = b[groupnum-1] | a[i];
    }

    bitset<32> exor;
    rep(i, groupnum) {
      exor = exor ^ b[i];
    }

    chmin(ans, ll(exor.to_ullong()));
  }

  cout << ans << endl;

  return 0;
}
