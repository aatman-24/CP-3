#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>
#include <iomanip>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	double n,a_0,a_n1,sumOf_Cvalues;
	vector<double> c_values;
	int t; cin >> t;


	while(t--)
	{#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>
#include <iomanip>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


equation which i dereived is:

// a1 = (n*a[0] + a[n+1] - 2 * [n*c1 + (n-1)c2 + (n-3)c3 + .. + ... +0]) / (n + 1).

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	double n,a_0,a_n1,sumOf_Cvalues;
	vector<double> c_values;
	int t; cin >> t;


	while(t--)
	{
		cin >> n >> a_0 >> a_n1;
		c_values.assign(n+1,0);

		for(int i = n ; i > 0 ; i--) cin >> c_values[i];

		sumOf_Cvalues = 0;
		for(int i = 1; i <= n; i++) sumOf_Cvalues += (c_values[i] * i);

		sumOf_Cvalues *= 2;
		
		double ans = ((n * a_0) + (a_n1) - sumOf_Cvalues) / (n + 1); 

		
		if(t) printf("%.2f\n\n",ans);
		else printf("%.2f\n",ans);

	}

	return 0;
}


		cin >> n >> a_0 >> a_n1;
		c_values.assign(n+1,0);

		for(int i = n ; i > 0 ; i--) cin >> c_values[i];

		sumOf_Cvalues = 0;
		for(int i = 1; i <= n; i++) sumOf_Cvalues += (c_values[i] * i);

		sumOf_Cvalues *= 2;
		
		double ans = ((n * a_0) + (a_n1) - sumOf_Cvalues) / (n + 1); 

		
		if(t) printf("%.2f\n\n",ans);
		else printf("%.2f\n",ans);

	}

	return 0;
}

