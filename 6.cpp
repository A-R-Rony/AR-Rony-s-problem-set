#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>ordered_set;

typedef long long int ll;
typedef unsigned long long int ull;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

typedef pair<int, int>pr;
#define mp   make_pair
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb push_back
#define eps 1e-9
#define SP cout<<fixed<<setprecision(10);

/// BISMILLHIR RAHMANIR RAHIM
///------------------------------------------------------------
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define dbg cout<<"rony\n";
#define setbit(n,k)  n&(1 << (k-1))

#define inf 100000
#define MAXN 100010

const int mod = 1e9 + 7;

ll bigmod(ll a, ll n)
{
    ll rs = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            n /= 2;
            a = (a * a) % mod;
        }
        else {
            n--;
            rs = (rs * a) % mod;
        }
    }
    return rs;
}

ll MULTI(ll a, ll n)
{
    if (n == 0) return 0;
    ll an = MULTI(a, n / 2);
    if (n % 2 == 0) an = (an + an) % mod;
    else an = (an + an + a) % mod;
    return an;
}
void solve()
{
    ll a, x, n;
    cin >> a >> x >> n;

    if (x == 1) {
        cout << a % mod << endl;
        return;
    }
    ll bm = bigmod(x, n);

    bm = (bm - 1 + mod) % mod;
    bm = (bm * x);
    bm %= mod;

    ll k = bigmod(x - 1, mod - 2); // inverse
    k = (k * bm);
    k %= mod;

    ll an = MULTI(a, k);

    an %= mod;
    cout << an << endl;
}
int main()
{

    ll t;
    t = 1;
    //cin >> t;
    int c = 0;
    while ( t-- )
    {
        //cout<<"Case "<<++c<<": ";
        solve();
    }
    return 0;
}
/// A L H A M D U L I L L A H