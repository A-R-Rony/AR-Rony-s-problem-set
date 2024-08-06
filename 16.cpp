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
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 100005
#define inf 1e6+5
const ll mod = 1000000007;
int n, m;

void solve()
{
    int n;
    cin >> n;

    vector<int>an(n + 1, 2);
    if (n == 1) {

        debug(n);
    }

    for (int i = 1; i <= n; i++) {

        if (n % i == 0) {
            int d = n / i;
            if (i < d) {
                an[i] = 0;
                an[d] = 1;
            }

        }
    }


    for (int i = 1; i <= n; i++) cout << an[i];
    cout << en;
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
        // cout << "Case " << ++c << ": ";
        solve();
    }
    return 0;
}