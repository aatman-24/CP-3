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

int X = 48;

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
	
	string a;
	int num,n;
	while(cin >> a)
	{
		if(a == "0") break;

		n = a.size();
		num = (int(a[0]) - X);
		if(n % 2 == 0)
		{
			num *= 10;
			num += (int(a[1]-X));
		}
		cout << int(sqrt(num));
		
		n = (n-1)/2;
		while(n) {cout << '0'; n--;};
		cout << endl;
		
	}

	return 0;
}

