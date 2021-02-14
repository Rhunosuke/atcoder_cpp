#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;
ll INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(m);
  rep(i, m) cin >> a[i];

  ll sum = accumulate(a.begin(), a.end(), 0);
  if (n - sum < 0) cout << -1 << endl;
  else cout << n - sum << endl;


  return 0;
}
