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
  Ml m;
  rep(i, n) {
    ll a;
    cin >> a;
    m[a]++;
  }

  vector<ll> a;
  a.push_back(0);
  a.push_back(0);
  for(auto i = m.begin(); i != m.end(); i++) {
    if (i->second >= 4) {
      a.push_back(i->first);
    }
    if (i->second >= 2) {
      a.push_back(i->first);
    }
  }
  sort(a.begin(), a.end(), greater<ll>());
  cout << a[0] * a[1] << endl;
  
  return 0;
}
