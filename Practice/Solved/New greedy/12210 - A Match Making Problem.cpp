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

bool sort_func(int a,int b) {return a <= b;}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int case_n = 1;
	int n,m;
	vi male,female;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		male.assign(n,0);
		female.assign(m,0);
		for(int i = 0 ; i < n ; i++) cin >> male[i];
		for(int j = 0 ; j < m ; j++) cin >> female[j];

		int youngest = *min_element(male.begin(),male.end());

		if(n > m)
		{
			cout << "Case " << case_n++ << ": " << n - m << ' ' << youngest << endl; 
		}
		else 
		{
			cout << "Case " << case_n++ << ": " << '0' << endl;
		}
	}
	



	return 0;
}

