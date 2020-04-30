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
  map<string, int> kuji;
  ll n;
  cin >> n;
  ll ans = 0;
  rep(i, n) {
    string s;
    cin >> s;
    if(kuji[s] == 0) {
      ans++;
      kuji[s] = 1;
    }

  }

  cout << ans << endl;

  return 0;
}
