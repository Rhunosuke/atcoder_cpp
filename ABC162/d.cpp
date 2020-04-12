#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;

int main() {
  int n;
  string s;
  cin >> n;
  cin >> s;
  int cntR[n], cntG[n], cntB[n];
  cntR[n-1] = 0; cntG[n-1] = 0; cntB[n-1] = 0;
  if (s[n-1] == 'R') cntR[n-1]++;
  else if (s[n-1] == 'G') cntG[n-1]++;
  else if (s[n-1] == 'B') cntB[n-1]++;

  repI(i, 1, n) {
    cntR[n-1-i] = cntR[n-i];
    cntG[n-1-i] = cntG[n-i];
    cntB[n-1-i] = cntB[n-i];
    if (s[n-1-i] == 'R') cntR[n-1-i]++  ;
    else if (s[n-1-i] == 'G') cntG[n-1-i]++;
    else if (s[n-1-i] == 'B') cntB[n-1-i]++;
  }

  char rgb[3] = {'B', 'G', 'R'};
  ll ans = 0;

  do {
    rep(i, n) {
      repI(j, i+1, n) {
        if (s[i] != rgb[0] || s[j] != rgb[1]) continue;
        if (rgb[2] == 'R') {
          if (j == n - 1) ans += cntR[j];
          else ans += cntR[j+1];
          if (2*j - i < n - 1) {
            if (cntR[2*j-i] != cntR[2*j-i+1]) ans--;
          }
          if (2*j - i == n - 1) {
            if (cntR[2*j-i] == 1) ans--;
          }
        }
        if (rgb[2] == 'G') {
          if (j == n - 1) ans += cntG[j];
          else ans += cntG[j+1];
          if (2*j - i < n - 1) {
            if (cntG[2*j-i] != cntG[2*j-i+1]) ans--;
          }
          if (2*j - i == n - 1) {
            if (cntG[2*j-i] == 1) ans--;
          }
        }

        if (rgb[2] == 'B') {
          if (j == n - 1) ans += cntB[j];
          else ans += cntB[j+1];
          if (2*j - i < n - 1) {
            if (cntB[2*j-i] != cntB[2*j-i+1]) ans--;
          }
          if (2*j - i == n - 1) {
            if (cntB[2*j-i] == 1) ans--;
          }
        }
        // cout << "i,j: " << i << " " << j << " " << ans << endl;
      }
    }
} while(next_permutation(rgb, rgb + 3));

cout << ans << endl;



  /*
  cntR, cntG, cntB are displayed;
  rep(i, n) {
    cout << cntR[i] << " "  << cntG[i] << " " << cntB[i] << endl;
  } */


  return 0;
}
