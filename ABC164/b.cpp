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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  if (ceil((double)a / d) < ceil((double)c / b)) cout << "No" << endl;
  else cout << "Yes" << endl;

  return 0;
}
