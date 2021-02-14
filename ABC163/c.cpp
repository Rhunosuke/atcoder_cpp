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
  ll n;
  cin >> n;
  M m;
  repI(i, 1, n) {
    ll a;
    cin >> a;
    a--;
    m[a]++;
  }

  rep(i, n) cout << m[i] << endl;;


  return 0;
}
