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
#define sum(n) ((1LL*(n)*(n+1))/ 2LL)
#define sqr(n) (1LL*(n)*(n))
#define vag(a,b) ((a + b - 1)/b)

#define MAXN 100010
#define inf 1e6+5
const int mod = 1e9 + 7;
string s;
int mem[25][2];
ll n;

ll f(ll i, ll PeraNai)
{
    if (i == n) {
        return 1;
    }
    if (mem[i][PeraNai] != -1) return mem[i][PeraNai];

    char Start = 'a';
    char End = 'z';
    if (!PeraNai) End = s[i];
    ll an = 0;

    for (char j = 'a'; j <= End; j++) {
        an += f(i + 1, PeraNai | (j < End)) % mod;
        an %= mod;
    }
    return mem[i][PeraNai] = an;
}
void solve()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> s;
        memset(mem, -1, sizeof(mem));
        ll an = f(0, 0);
        cout << an << en;
    }
}
int main()
{
    solve();
}