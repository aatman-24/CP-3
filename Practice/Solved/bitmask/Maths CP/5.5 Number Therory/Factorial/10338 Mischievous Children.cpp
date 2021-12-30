#include <bits/stdc++.h>
#define ll long long
#define REP(i,n) for(int i = 0; i < n; i++)
#define REP1(i,n) for(int i = 1; i <= n; i++)
#define debug cout << "Ok" << endl

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================



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



    ll arr[21];
    arr[0] = 1;
    for(ll i = 1;i < 21;i++) {
        arr[i] = arr[i-1] * i;
    }


    int n; cin >> n;
    string str;
    REP1(t,n) {
        cin >> str;
        sort(str.begin(),str.end());
        int cnt = 0;
        vi duplicate;
        REP1(i,(int)str.size()) {
            if(str[i-1] == str[i]) cnt++;
            else {
            duplicate.push_back(cnt+1);
            cnt = 0;
            }

        }

        ll result = arr[str.size()];
        REP(i,(int)duplicate.size()) {
            result /= arr[duplicate[i]];
        }

        cout << "Data set " << t << ": " << result << endl;

    }

    return 0;
}

