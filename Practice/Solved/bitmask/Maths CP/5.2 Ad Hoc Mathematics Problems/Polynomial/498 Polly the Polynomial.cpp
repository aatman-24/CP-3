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

NOTHING JUST CHECK HOW TO GET DATA INTO NUMER FORMAT.


EQUATION : coeff[j] * (power(x_values[i],n-j-1))  (J = 0 -> N-1)


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
        coeff.clear();
        parseData(s,coeff);

        getline(cin,s);

        x_values.clear();
        parseData(s,x_values);



        ll n = coeff.size();
        for(ll i = 0; i < x_values.size(); i++)
        {
            ll result = 0;
            for(ll j = 0 ; j < coeff.size(); j++)
            {
               result += (coeff[j] * (power(x_values[i],n-j-1)));
            }
            
            if(i != x_values.size()-1) cout << result << ' ';
            else cout << result << endl;
        }


    }

    return 0;
}

