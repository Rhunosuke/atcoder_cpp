#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;

int main() {
  string n;
  cin >> n;
  string ans = "No";
  rep(i, int(n.length())) {
    if (n[i] == '7') ans = "Yes";
  }

  cout << ans << endl;

  return 0;
}
