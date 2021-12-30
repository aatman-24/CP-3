#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> Apporach <=============================================

EQUATION : (coeff[j] * (n-j-1) * (power(X,n-j-2))


*/

ll sign;
ll num;

vector<ll> coeff;
vector<ll> x_values;


void parseData(string s,vector<ll> &arr)
{
    sign = 1;
    for(double i = 0; i < s.size(); i++)
    {
        if(s[i] == '-')
        {
            sign = -1;
            i++;
        }

        num = 0;
        while(s[i] != ' ' && i < s.size())
        {
            num = (num * 10) + int(s[i]-'0');
            i++;
        }

        arr.push_back(sign*num);
        sign = 1;
    }
}

ll power(ll base, ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1) ans *= base;
        base = base * base;
        n = n/2;
    }
    return ans;
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    string s;
    while(getline(cin,s))
    {
        x_values.clear();
        parseData(s,x_values);

        getline(cin,s);
        coeff.clear();
        parseData(s,coeff);

        int X = x_values[0];

        ll n = coeff.size();
        ll result = 0;
        for(ll j = 0 ; j < coeff.size(); j++)
        {
            result += (coeff[j] * (n-j-1) * (power(X,n-j-2)));
        }
        cout << result << endl;

    }
    return 0;
}
