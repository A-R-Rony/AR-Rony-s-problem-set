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
#define pb     push_back
#define totalone(mask)  __builtin_popcount(mask)
#define chkbit(mask,bit)  (mask&(1LL << bit))

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
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 100010
#define inf 1e6+5
const int mod = 1e9 + 7;
vector<int>g[MAXN];
ll n, a[MAXN];

struct segment_tree
{
    struct node {
        ll suru , ses, mn;

        void init(ll l, ll r) {
            suru = l, ses = r;
            if (l == r) mn = a[l];
        }
    } g[4 * MAXN];

    void fill_cn(node &cn, node &ln, node &rn) // fill_current_node
    {
        cn.mn = min(ln.mn, rn.mn);
    }
    void build(ll cn, ll l, ll r)
    {
        g[cn].init(l, r);

        if (l == r ) return;
        ll md = l + (r - l) / 2;

        build(cn * 2, l, md);
        build(cn * 2 + 1, md + 1, r);

        fill_cn (g[cn], g[cn * 2] , g[cn * 2 + 1]);
    }

    ll query(ll cn, ll l, ll r)
    {
        ll x = g[cn].suru;
        ll y = g[cn].ses;
        if (y < l || x > r) return 1e15;

        if (l <= x && r >= y ) return g[cn].mn;

        ll ans = query(cn * 2, l, r);
        ans = min(ans, query(cn * 2 + 1, l, r));
        return ans;
    }

} stre;
ll find_left(ll l, ll r, ll id)
{
    ll an = -1;
    while (l <= r)
    {
        ll md = l + (r - l) / 2;
        ll mn = stre.query(1, md, id);
        if (mn >= a[id]) {
            an = md;
            r = md - 1;
        }
        else l = md + 1;
    }
    return an;
}
ll find_right(ll l, ll r, ll id)
{
    ll an = -1;
    while (l <= r)
    {
        ll md = l + (r - l) / 2;
        ll mn = stre.query(1, id, md);
        if (mn >= a[id]) {
            an = md;
            l = md + 1;
        }
        else r = md - 1;
    }
    return an;
}
ll sum(ll a, ll n)
{
    ll an = (2 * a) + (n - 1);
    an *= n;
    an /= 2;
    return an;
}
void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += i;
    }

    stre.build(1, 1, n);

    ll an = 0;

    for (ll i = 1; i <= n; i++)
    {
        ll l = find_left(1, i, i);
        ll r = find_right(i, min(a[i] - 1, n), i);
        // debug(l, r);
        ll area = (r - l + 1) * a[i];
        area -= sum(l, r - l + 1);
        // debug(area);
        an = max(an, area);
    }
    cout << an << en;
}
int main()
{
    IOS;
    ll t;
    t = 1;
    cin >> t;

    int c = 0;
    while ( t-- )
    {
        // cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}