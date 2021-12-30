#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;



// 2 * arr[M] = arr[M-1] + arr[M-2] 

// #Approach : Here we have upto n=10000 elements. so if we use brute force is still work O(N^2).
// we use two for loop first one for the M.so we set boundary (1,n-1)(first and last never become
// mid elements). another for loop for the arr[M-2] elements we check for all the elements after the arr[M]
// using formula check wether arr[M-1] elements is visited or not.If visited that means it is on left 
// side of M so we can say this is not arithmetic progression.


bool check_arithmetic_progression(vi &arr)
{
	double n = arr.size();
	vi seen(n,0);
	seen[arr[0]] = 1;
	for(int i = 1 ; i < n-1 ; i++)
	{
		for(int j = i+1; j < n ; j++)
		{
			int ele = (arr[i] << 1) - arr[j];
			if(ele >= 0 && ele < n && seen[ele] == 1) 
				{
					return true;
				}
		}
		seen[arr[i]] = 1;
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int  n;
	char ch;

	while(true)
	{
		cin >> n; 
		if(n == 0) break;
		cin >> ch;
		vi arr(n,0);
		for(int i = 0; i < n ; i++) cin >> arr[i];
		if(check_arithmetic_progression(arr)) cout << "no" << endl;
		else cout << "yes" << endl;
	
	}
	return 0;

}