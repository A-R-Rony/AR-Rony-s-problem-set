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
#define MAXN 1010

const int mod = 1e9 + 7;
ll n;
ll a[MAXN];
ll mem[MAXN][10];

ll f(ll i, ll j, ll sm)
{
    //cout<<i<<" "<<j<<" "<<sm<<endl;
    if (j == 5)
    {
        if (sm % 5 == 0) return 1;
        return 0;
    }
    //if(mem[i][j] != -1) return mem[i][j];

    ll A = 0;
    for (ll k = i + 1; k <= n; k++)
    {
        A += f(k, j + 1, sm + a[k]);
        A %= mod;
    }
    mem[i][j] = A;
    return mem[i][j];
}
void solve()
{
    cin >> n;
    for (ll i = 1; i <= n; i++) cin >> a[i];
    memset(mem, -1, sizeof(mem));

    ll an = f(0, 0, 0);
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