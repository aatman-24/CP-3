#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;



// #Approach : Here we have to make number like which contain only (1 & 2) of given p length.
// and check whether it is divide by 2^q or not.

// so we can use bit manipulation. try all possiblity using (1 & 2).  Like 10001001 here we consider 1->1 
// and 0->2.

// where a = {0,1}. 

// then we used num = a*(10^n) + a*(10^n-1) + .... + a*10^0. Equation to form the number.

// LIMIT CONDITION : here number can be upto 17 length. so here we have to used long long int -> (2^63) (20 len).

ll int pow(int base,int n)
{
	if(n == 0)
		return 1;
	else
	{
		ll int result = pow(base,n/2);
		result *= result;
		if(n % 2 == 1)
			result *= base;
		return result;
	}
}


int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	ll int p,q,k_th_value;
	ll int t; cin >> t;
	for(int j = 0; j < t; j++)
	{

		cin >> p >> q;
		ll int low = LLONG_MAX;
		ll int high = LLONG_MIN;

		for(ll int i = 0 ; i < (1 << p); i++)
		{

			ll int num = 0;
			for(int k = 0 ; k < p; k++)
			{
				ll int bit_set = (i & (1 << k));
				if(bit_set)
				{
					k_th_value = 1;
				}
				else
				{
					k_th_value = 2;
				}

				num += (pow(10,k) * k_th_value);
			}

			if((num % (1 << q)) == 0)
			{

				if(low > num) low = num;
				if(high < num) high	 = num;
			}


		}

		if(low == LLONG_MAX && high == LLONG_MIN) cout << "Case " << j+1 << ": " << "impossible" << endl;
		else if(low == high)
		{
			cout << "Case " << j+1 << ": " << low <<  endl;
		}
		else
		{
			cout << "Case " << j+1 << ": " << low << ' ' << high << endl;
		}
		
	}	


	return 0;
}