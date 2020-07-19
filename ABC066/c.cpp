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
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  deque<ll> deq;

  rep(i, n) {
    if (i % 2 == 0) deq.push_back(a[i]);
    else deq.push_front(a[i]);
  }

  if (n % 2 == 1) reverse(deq.begin(), deq.end());

  rep(i, n) cout << deq[i] << " ";
  cout << endl;

  return 0;
}
