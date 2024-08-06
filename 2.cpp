#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    string s, a = "aeiou";
    cin >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[j] == s[i]) {
                break;
            }
            if (j == 4) {
                for (int k = 0; k < 5; k++) {
                    if (a[k] == s[i - 1]) ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
