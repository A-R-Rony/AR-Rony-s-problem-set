Code:

#define MAXN 1000010
#define inf 1e6+5
const ll mod = 1e9 + 7;

ll n;
ll a[MAXN];

void solve()
{

    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    ll ans = 0;

    ll x = 0;
    for (ll i = 0; i < n; i++)
    {
        ll y = 1;
        if (a[i] == a[i + 1] && i + 1 < n)
        {
            while (a[i] == a[i + 1] && i + 1 < n) {
                y++;
                i++;
            }
        }
        ll z = n - (x + y);
        ans += (((x * y) % mod) * z) % mod;
        x += y;
        ans %= mod;
    }

    cout << ans << en;

}