#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;


void display(vi &arr)
{
	for(double i = 0 ; i < arr.size(); i++) cout << arr[i] << ' ';
	cout << endl;
}


void see(vvi &arr)
{
	for(double i = 0 ; i < arr.size(); i++)
	{
		for(double j = 0 ; j < arr[i].size(); j++) cout << arr[i][j] << '-' << i+1 <<'|';
		cout << endl;
	} 
	cout << endl;
}


vi weight = {10000000,1000000,500000,200000,10000};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	int n,m;
	int level,minutes,minute_total;	

	while(true)
	{
		cin >> n; if(n == 0) break;
		
		vi arr(n,0);
		for(int i = 0 ; i < n ;i++) cin >> arr[i];



		cin >> m;
		int MAX_LEVEL  = -10;
		vvi checkpoint(5);
		vi level_error(5,INT_MAX);
		for(int i = 0 ; i < m ;i++) 
		{
			cin >> level >> minutes;
			checkpoint[level-1].push_back(minutes);
			level_error[level-1] = INT_MAX;

			if(MAX_LEVEL < level - 1) MAX_LEVEL = level - 1;
		}


		// sort(arr.begin(),arr.end());
		int final_total_error = INT_MAX;
		vi result(n,0);
		int og_error = 0;
		do
		{
			int total_error = 0;
			int og_temp_error = 0;
			for(int j = 0; j <= MAX_LEVEL ; j++)
			{

				int sum_error = 0;
				for(double k = 0 ; k < checkpoint[j].size() ; k++)
				{
					int chk = checkpoint[j][k];
					minute_total = 0;
					for(int i = 0 ; i < n ; i++)
					{
						if(chk >= minute_total + arr[i]) 
						{ 
							minute_total += arr[i];
						}
						else
						{
							sum_error += min(abs(chk - minute_total) , abs(chk - arr[i] - minute_total));
						}
					}

				}
				total_error += (sum_error * weight[j]);
				og_temp_error += (sum_error); 
			}


			if(total_error <= final_total_error)
			{
				// display(arr);
				// cout << "total_error : " << total_error << '|' << "final_total_error  : " << final_total_error << endl;
				final_total_error = total_error;
				og_error = og_temp_error;
				result = arr;
			}

		}while(next_permutation(arr.begin(),arr.end()));

		// cout << endl;

		// 	Data set 1
		// Order: 15 45 30 45
		// Error: 0
		// Data set 2
		// Order: 15 13 33 25 18 10
		// Error: 19

		// cout << i <<
		display(result);
		cout << og_error << endl;
	}



	return 0;

}