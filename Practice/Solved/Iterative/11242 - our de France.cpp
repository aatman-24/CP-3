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
typedef vector<double> vd;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;


void display(vd &arr)
{
	for(double i = 0 ; i < arr.size() ;i++) cout << arr[i] << ' ';
	cout << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	


	double front_n,rare_n;

	while(cin >> front_n)
	{
		if(front_n == 0) break;

		cin >> rare_n;

		vd front_gear(front_n,0);
		vd rare_gear(rare_n,0);


		for(int i = 0 ; i < front_n ; i++) cin >> front_gear[i];
		for(int i = 0 ; i < rare_n ; i++) cin >> rare_gear[i];


		vd drive_ration(front_n*rare_n, 0);

		int k = 0;
		for(int i = 0 ; i < front_n ; i++)
		{
			for(int j = 0 ; j < rare_n ; j++)
			{
				drive_ration[k] = rare_gear[j]/front_gear[i];
				k++;
			}
		}

		sort(drive_ration.begin(),drive_ration.end());

		// display(drive_ration);

		double max_ratio = INT_MIN;


		for(int i = 1 ; i < k ; i++)
		{
			if((drive_ration[i] / drive_ration[i-1]) > max_ratio) 
				{
					// cout << drive_ration[i] << '|' << drive_ration[i-1] << endl;
					(max_ratio = drive_ration[i] / drive_ration[i-1]) ;
				}
		}

		printf("%0.2f\n",max_ratio);

		// cout << std::fixed << max_ratio  << endl;
	}


	return 0;

}