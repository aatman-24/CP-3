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


// #Approach : It's very simple formula,
// let's take example from 1..10

// we have total 1,2,3...10 Number, final answer = 1,2,3,5,7,9.

// Remove 	K,2K,3K,4K,5K
// Add 	K^2,2*K^2,3*K^2,4*K^2...
// Remove 	K^3,2*K^3,3*K^3,4*K^3...

// Remove 2,4,6,8,10
// add    4,8,
// Remove 8

// so pattern is Like... N - (N/K) + (N/K^2) - (N/K^3) + .... 0
// 
// so final pattern is like.. 1,2,3,5,7,9 OR 1,3,4,5,7,9 OR 1,3,5,7,8,9 (ONLY TAKE 1 FROM {2,4,8});

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	ll N,K,cnt;

	ll t; cin >> t;
	while(t--){
		cin >> N >> K;
		cnt = 0;
		int i = 0;
		int tmp = N;
		while(tmp)
		{
			tmp = N/pow(K,i);
			if(i % 2 == 0) cnt += tmp;
			else cnt -= tmp;
			i++;
		}
		cout << cnt << endl;
	}
	



	return 0;
}

