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

#define MAXN 100005
#define inf 1e6+5
const ll mod = 1000000007;

vector<int>g[MAXN];

void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        int x = a[i];
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                int d1 = j;
                int d2 = x / j;

                g[d1].pb(i);
                if (d1 != d2)
                    g[d2].pb(i);
            }
        }
    }

    int mx_size = 0;
    int val = 0;
    int pos = 0;

    for (int i = 0; i < n; i++) {
        int x = a[i];
        if (g[x].size() == 0) continue;
        int lb = lower_bound(all(g[x]), i) - g[x].begin();
        int tm = (int)g[x].size() - lb; // tm = current size

        if (tm > mx_size) {
            mx_size = tm;
            pos = i;
            val = x;
        }
        else if (tm == mx_size && x > val) {
            val = x;
            pos = i;
        }
    }

    debug(mx_size, pos, val);

    cout << pos + 1 << en;
    cout << mx_size << en;

    for (int i = 0; i < g[val].size(); i++) {
        if (g[val][i] < pos) continue;
        cout << a[g[val][i]] << " ";
    }
    cout << en;
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