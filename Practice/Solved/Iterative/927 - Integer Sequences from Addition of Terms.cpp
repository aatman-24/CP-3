#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<ll int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


ll int pow(int n,int i)
	{
		if(i == 0)
			return 1;
		else
		{
			ll int ans = pow(n,i/2);
			ll int result = ans * ans;
			if((i & (1 << 0)) == 1)
			{
				result *= n;
			}
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

	float degree,d,k;

	int t; cin >> t;
	while(t--)
	{
		cin >> degree;
		vi coff(degree+1,0);
		for(int i = 0 ; i <= degree ;i++) cin >> coff[i];
		cin >> d >> k;


		// How to get n ? -> (d * n(n+1)/2) using this equation you get n means for given k what 
		// is the value of n.

		float p = (k / d) * 2.0;
		float delta = 1.0 + (4 * 1 * p);
		int n = ceil((-1 + sqrt(delta)) / 2.0);

		ll int equation = 0;	
		for(int i = 0 ; i <= degree ; i++)
		{
			equation += (coff[i] * pow(n,i));
		}
		cout << equation << endl;
	}

	return 0;

}