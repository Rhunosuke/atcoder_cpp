#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Pl = pair<ll, ll>;
using M = map<int, int>;
ll const INF = 1ll<<61;
double pi = 3.141592653589793238;
int const DEV = 2019;

int main() {
  string s;
  cin >> s;
  ll n = s.size();

  ll cursor = 0;
  vector<ll> cnt(DEV, 0);
  cnt[cursor]++;
  ll factor = 1;

  rep(i, n) {
    cursor += (s[n-1-i] - '0') * factor;
    factor = factor * 10 % DEV;
    //cout << cursor << " " << cursor % DEV <<  endl;
    cnt[cursor % DEV]++;
  }

  ll ans = 0;

  rep(i, DEV) {
    ans += cnt[i] * (cnt[i]-1) / 2;
  }

  cout << ans << endl;

  return 0;
}
