#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define debug cout << "Ok" << endl

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

TIME COMPLEXITY : O(N*log(min(a,b)))

simple cal....

*/

ll gcd(ll a,ll b) {return b == 0 ? a : gcd(b,a%b);}
ll lcm(ll a, ll b) {return (a * (b / gcd(a,b)));}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n;
    ll t; cin >> t;
    REP(case_n,t)
    {

        cin >> n;

        ll a[n];
        REP(i,n) cin >> a[i];

        if(n < 2) cout << "Case " << case_n+1 << ": " << a[0] << "/1" << endl;
        else {

            ll tmp_lcm = lcm(a[0],a[1]);
            for(int i = 2; i < n; i++) tmp_lcm = lcm(tmp_lcm,a[i]);

            ll denominator = 0;
            REP(i,n) denominator += (tmp_lcm/a[i]);


            ll cmn = gcd(n*tmp_lcm,denominator);
            cout << "Case " << case_n+1  << ": " << n*tmp_lcm/cmn << '/' << denominator/cmn << endl;            
        }

    }

    return 0;
}

