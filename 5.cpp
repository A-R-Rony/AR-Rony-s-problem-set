#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n), gf;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 0) {
            gf.push_back(i);
        }
    }
    ll ans = -1;
    for (int i = 0; i < gf.size(); i++) {
        ll last;
        if (i == 0) {
            last = -1e12;
        }
        else last = gf[i - 1];
        ll next;
        if (i == gf.size() - 1) {
            next = 1e12;
        }
        else next = gf[i + 1];
        if (gf[i] - last >= k + 1 and next - gf[i] >= k + 1) {
            if (ans != -1) {
                if (a[ans] < a[gf[i]]) {
                    ans = gf[i];
                }
            }
            else ans = gf[i];
        }
    }
    if (ans != -1) cout << ans + 1 << endl;
    else cout << "Impossible" << endl;
    return 0;
}
