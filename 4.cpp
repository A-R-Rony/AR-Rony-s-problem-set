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
vector<int>g[MAXN];
void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;

    int j = 1;

    int ona = 0, onb = 0, za = 0, zb = 0;

    for (int i = 0; i < n; i += 2)
    {
        if (a[i] == '1') ona++;
    }
    for (int i = 1; i < n; i += 2) {
        if (b[i] == '1') ona++;
    }

    za = n - ona;

    for (int i = 0; i < n; i += 2)
    {
        if (b[i] == '1') onb++;
    }
    for (int i = 1; i < n; i += 2) {
        if (a[i] == '1') onb++;
    }

    zb = n - onb;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (za) {
                a[i] = '0';
                za--;
            }
            else {
                a[i] = '1';
            }

            // b er jonno
            if (zb) {
                b[i] = '0';
                zb--;
            }
            else {
                b[i] = '1';
            }
        }
        else {
            if (za) {
                b[i] = '0';
                za--;
            }
            else b[i] = '1';
            // ber jonno
            if (zb) {
                a[i] = '0';
                zb--;
            }
            else a[i] = '1';
        }
    }

    cout << a << endl << b << endl;


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