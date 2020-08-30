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
  string s, t;
  cin >> s >> t;

  ll cnt = 0;
  for (ll i = 0; i <ll(s.size())-ll(t.size())+1; i++) {
    ll tmp = 0;
    for(ll j = 0; j < ll(t.size()); j++) {
      if (t[j] == s[i+j]) tmp++;
    }
    chmax(cnt, tmp);
  }

  cout << ll(t.size()) - cnt << endl;

  return 0;
}
