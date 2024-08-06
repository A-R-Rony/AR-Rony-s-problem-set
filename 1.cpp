
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
#define IOS ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);

typedef pair<int,int>pr;
#define mp   make_pair
#define all(i)     i.begin() , i.end()
#define ft     first
#define sn     second
#define pb push_back
#define eps 1e-9
#define SP cout<<fixed<<setprecision(10);

        /// BISMILLHIR RAHMANIR RAHIM
///------------------------------------------------------------

#define dbg cout<<"rony\n";
#define inf 100000
#define MAXN 1000000000

const int mod = 1e9+7;


ll Lcm(ll a,ll b)
{
    return (a/__gcd(a,b))*b;
}
void solve()
{
   int a[3];
   cin >> a[0] >> a[1] >> a[2];
   sort(a,a+3);
   cout<<a[1]<<endl;

}
int main()
{
    IOS;
    int t;
    t = 1;
    //cin >> t;
    while ( t-- )
        solve();
    return 0;
}
   /// A L H A M D U L I L L A H
