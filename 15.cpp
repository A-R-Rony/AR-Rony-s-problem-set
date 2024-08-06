#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>order_set;
typedef pair<int, int>pr;
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb push_back

#define totalone(mask) __builtin_popcount(mask)
#define chkbit(mask,bit) (mask&(1LL << bit))
#define setbit(mask,bit) (mask|(1LL << bit)
#define cngbit(mask,bit) (mask^(1LL << bit))

// debug section start
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
// debug section closed

#define en "\n"
#define dbg(x) cerr<<#x<<" is : "<<x<<en;
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 100002
#define inf 1e6+5
const ll mod = 1000000007;


ll mem[501][MAXN];
ll n;
ll a[501];

void f(ll i, ll val)
{
    // debug(i, val);
    if (i == n) {
        mem[i][val] = 1;
        return;
    }
    if (mem[i][val] == 1) return;

    mem[i][val] = 1;

    if (val * a[i] <= 100000) {
        f(i + 1, val * a[i]);
    }
    f(i + 1, val);
}
void solve()
{

    cin >> n;

    ll one = 0;

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)one++;
    }

    f(0, 1);

    ll q;
    cin >> q;
    int cn = 0;

    for (ll i = 0; i < q; i++) {
        ll x;
        cin >> x;
        if (x == 1 && one) {
            cout << "YES\n";
            continue;
        }
        else if (x == 1) {
            debug("NO");
            cout << "NO\n"; continue;
        }

        if (mem[n][x] == 1) {
            cout << "YES\n";
            // cout << "-------------\n";
            cn++;
        }
        else
            cout << "NO\n";
    }

    debug(q, cn, one);

}
int main()
{
    IOS;
    ll t;
    t = 1;
    // cin >> t;

    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}