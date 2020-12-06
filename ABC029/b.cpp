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

  ll ans = 0;

  rep(i, 12) {
    string s;
    cin >> s;

    if (s.find("r") != string::npos)
      ans++;
  }

  cout << ans << endl;

  return 0;
}
