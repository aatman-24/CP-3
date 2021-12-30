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

using this formula, -> a (congruts) B (mod N) -> a = k*N + b means that if we add
kth term of N into a or b still it give the same remainder.

-> a % m = b % m
-> (proposition [chk on book]) -> a - b = M (k1 - k2)
        Means that if a % m == b % m give the same reminder then a - b is divided by M means give no
        remainder.

(Proof)...
-> a % m == b % m
-> (a-a) % m = (b - a) % m
-> 0 = (b - a) % m (Means (b - a is divisble by M and give 0 remainder.))
-> (b -a) = M * Kth term. 

Same Here we try to make any(Here we used first Number) number to (zero) and subtract it from all the numbers.
and try to find gcd(which is given).


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


    vi arr;
    int N;
    while(cin >> N) {
        if(N == 0) break;
        arr.clear(); arr.push_back(N);
        while(cin >> N) {
            if(N == 0) break;
            arr.push_back(N);
        }

        int tmp = arr[0];
        REP(i,(int)arr.size()) arr[i] -= tmp;
        int cmn_gcd = gcd(arr[0],arr[1]);
        for(int i = 2;i < (int)arr.size(); i++) cmn_gcd = gcd(cmn_gcd,arr[i]);
        cout << abs(cmn_gcd) << endl;

    }




    return 0;
}

