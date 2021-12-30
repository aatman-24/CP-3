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


vi arr,check,final_arr;
int N,TARGET,min_dif,nearest_sum;


void display(vi final_arr)
{
	for(double i = 0; i < final_arr.size(); i++) 
		if(final_arr[i] == 1) 
			cout << arr[i] << ' '; 
}


void should_i_use(int cur_sum)
{
	if(TARGET - cur_sum < min_dif)
	{
		min_dif = TARGET - cur_sum;
		final_arr = check;
		nearest_sum = cur_sum;
	}
}

void backtrack(int nIndex,int cur_sum)
{
	if(nIndex == N) return;

	for(int i = nIndex ; i < N; i++)
	{
		if(cur_sum + arr[i] <= TARGET)
		{
			int temp = cur_sum;
			cur_sum += arr[i];
			check[i] = 1;
			should_i_use(cur_sum);
			if(cur_sum == TARGET) return;
			backtrack(i+1,cur_sum);

			check[i] = 0;
			cur_sum = temp;
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
	

	while(cin >> TARGET)
	{
		cin >> N;
		arr.assign(N,0); check.assign(N,0);
		for(int i = 0 ; i < N ; i++) cin >> arr[i];

		min_dif = INT_MAX;	
		backtrack(0,0);
		display(final_arr);
		cout << "sum:";
		cout << nearest_sum << endl;
	}

	return 0;
}

