#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
ll INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  int n, k;
  cin >> n >> k;

  ll ans = 0;
  ll max_num = 0;
  ll min_num = 0;

  rep(i, n + 1) {
    max_num += (n - i);
    min_num += i;
    if (k <= i+1) ans += (max_num - min_num + 1);
  }

  cout << ans % ll(1e9+7) << endl;


  return 0;
}
