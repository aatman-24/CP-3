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



// s = n/2 * (2a + (n - 1) * d)
// d = 1; -> s = n/2 * (2a + n - 1)
// 2s = 2an * n^2 - n
// a = (2s - n^2 + n) / 2n;

// a is first value and if we find n such that, s = n/2(A0 + An) we can get An.


ll M;

ll check_n_is_valid(ll n)
{
	ll a = 2*M - (n * n)+ n;
	if(a % (2*n) == 0) return (a/(2*n));
	return -1;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	while(cin >> M)
	{
		if(M == -1) break;

		ll n = sqrt(2*M);

		for(ll i = n ; i > 0 ; i--)
		{
			ll a = check_n_is_valid(i);
			if(a >= 0){
				cout << M << " = " << a <<  " + ... + " << a + i - 1 << endl;
				break;
			}
		}

	}




	return 0;
}

