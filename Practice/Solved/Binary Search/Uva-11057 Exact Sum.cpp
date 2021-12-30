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


// #Approach : second_book_price = M - first_book. Try all the book as first_book and using binary search get
// second_book_price after that you have to chk whether it's gap is minimum or not.

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	vi arr;
	int N,M,first,second;
	int MIN_GAP;
	while(cin >> N)
	{
		arr.assign(N,0);
		for(int i = 0; i < N; i++) cin >> arr[i];
		
		cin >> M;
		sort(arr.begin(),arr.end());
		MIN_GAP = INT_MAX;
		for(int i = 0 ; i < N; i++)
		{
			int second_book_price = M - arr[i];
			int k = lower_bound(arr.begin(), arr.end(), second_book_price) - arr.begin();
			if((i != k && arr[k] + arr[i] == M) && (abs(arr[k] - arr[i]) < MIN_GAP))
			{
				MIN_GAP = abs(arr[k] - arr[i]);
				first = arr[i], second = arr[k];
			}
		}

		cout << "Peter should buy books whose prices are " << first << " and " << second << '.' << endl << endl;

	}


	return 0;
}

