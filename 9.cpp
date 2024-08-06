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

#define MAXN 1010
#define inf 1e6+5
const int mod = 1e9 + 7;

bool is_sorted(vector<int>a)
{
    vector<int>t;
    t = a;
    sort(all(a));
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != t[i]) return false;
    }
    return true;
}
void solve()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int>ek, dui, tin, v;

    for (int i = 0; i < n; i += 3) {
        ek.pb(a[i]);
    }
    for (int i = 1; i < n; i += 3) dui.pb(a[i]);
    for (int i = 2; i < n; i += 3) tin.pb(a[i]);
    sort(all(ek)); reverse(all(ek));
    sort(all(dui)); reverse(all(dui));
    sort(all(tin)); reverse(all(tin));

    // vector<int>v;

    // debug(ek, dui, tin);
    while (1)
    {
        if (ek.size() == 0 && dui.size() == 0 && tin.size() == 0) break ;
        if (ek.size())
            v.pb(ek.back()),  ek.pop_back();
        if (dui.size())
            v.pb(dui.back()), dui.pop_back();
        if (tin.size())
            v.pb(tin.back()), tin.pop_back();
    }

    if (is_sorted(v)) {
        cout << "YES\n";
    }
    else cout << "NO\n";
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