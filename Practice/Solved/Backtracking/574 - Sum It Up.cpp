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

// #Apporach : It is simple backtracking. Maybe you have problems with unique solution.
// Here I used set of c++. Bcz set store only unique elements no mattter it is int
// or vector it store uniquly. 



vi arr,result;
set<vi> final_result;
int N,total;

void display(vi arr)
{
	for(double i = 0 ; i < arr.size() ; i++) 
		if(arr[i]) cout << arr[i] << ' ';
	cout << endl;
}

void backtracking(int nIndex, int cur_sum, int j)
{
	if(cur_sum == total) {final_result.insert(result); return;}
	if(cur_sum > total) return;

	for(int i = nIndex; i < N; i++)

	{
		if(arr[i] + cur_sum <= total)
		{
			result.push_back(arr[i]);
			backtracking(i+1,cur_sum+arr[i],j+1);
			result.pop_back();
		}
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
	

	
	while(true)
	{
		cin >> total;
		cin >> N;
		if(N == 0) break;
		arr.assign(N,0);
		for(int i = 0 ; i < N ; i++) cin >> arr[i];
		final_result.clear();
		result.clear();
		backtracking(0,0,0);

		cout << "Sums of " << total << ":\n";
		if(final_result.size() == 0) cout << "NONE" << endl;
		else
		{
			for(auto it = final_result.rbegin(); it != final_result.rend(); it++)
			{
				vi temp = *it;
				for(double i = 0 ; i < temp.size() ; i++)
				{
					if(i != temp.size() - 1) cout << temp[i] << '+';
					else cout << temp[i] << endl;
				}
			}
		}
			
	}


	return 0;
}

