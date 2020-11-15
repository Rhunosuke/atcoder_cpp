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
  ll n, w;
  cin >> n >> w;
  vector<ll> s(n), t(n), p(n);
  rep(i, n) cin >> s[i] >> t[i] >> p[i];

  vector<ll> table(2e5 + 1);
  rep(i, n) {
    table[s[i]] += p[i];
    table[t[i]] -= p[i];
  }

  reps1(i, 2e5 + 1) {
    table[i] += table[i-1];
    // if (i <= 30) cout << i << " " << table[i] << endl;
  }

  if (*max_element(table.begin(), table.end()) <= w) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
