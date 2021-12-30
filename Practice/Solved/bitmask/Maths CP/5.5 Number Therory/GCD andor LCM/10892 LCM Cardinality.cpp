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

-> Cardinality (a,b) is less than N and It is possible only in divisor of N means N factor.
we collect all factor and then use simple..... checking.

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

    int N;
    set<int> st;
    while(cin >> N) {
        if(N == 0) break;
        st.clear();
        for(int i = 1; i <= sqrt(N); i++) {
            if(N % i == 0) {st.insert(i); st.insert(N/i);}
        }

        int cnt = 0;
        for(auto i : st) {
            for(auto j : st) {
                if(i <= j && lcm(i,j) == N) cnt++; 
            }
        }
        cout << N << ' ' << cnt << "\n";
    }
}

