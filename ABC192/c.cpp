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
  ll n, k;
  cin >> n >> k;
  ll tmp = n;

  rep(i, k) {
    vector<ll> v;
    while(tmp != 0) {
      v.push_back(tmp%10);
      tmp /= 10;
    }
    ll g1 = 0, g2 = 0;
    sort(v.begin(), v.end(), greater<ll>());
    rep(i, ll(v.size())) {
      g1 *= 10;
      g1 += v[i];
      g2 *= 10;
      g2 += v[ll(v.size())-1-i];
    }
    tmp = g1 - g2;
  }

  cout << tmp << endl;

  return 0;
}
