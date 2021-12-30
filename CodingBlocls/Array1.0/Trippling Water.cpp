#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


void display(vector<int> &ele)
{
	int m = ele.size();
	for(double i = 0 ; i < m; i++)
	{
		cout << ele[i] << ' ';
	}
	cout << endl;
}	

// #codingBlocks

// Question : Trippling Water. O(N) -O(N)
// soultion : pre-process the left and right max height/



void myapproach(vector<int> &building)
{
	vector<int> left,right,result;
	double n = building.size();
	left.assign(n,0); right.assign(n,0),result.assign(n,0);
	left[0] = 0;
	right[n-1] = 0;
		for(int i = 1 ; i < n ; i++)
		{
			if((building[i] < building[i-1]) || (building[i] < left[i-1]))
			{
				left[i] = max(building[i-1],left[i-1]) - building[i];
				if((building[i] <= building[i-1]) && (building[i] < left[i-1]))
				{
					left[i] += 1;
				}
				
 			}
 			else
 			{
 				left[i] = 0;
 			}
		}

		for(int i = n - 2 ; i > -1 ; i--)
		{
			if((building[i] < building[i+1]) || (building[i] < right[i+1]))
			{
				right[i] = max(building[i+1],right[i+1]) - building[i];
				if((building[i] <= building[i-1]) && (building[i] < right[i+1]))
				{
					right[i] += 1;
				}
				
 			}
 			else
 			{
 				right[i] = 0;
 			}
		}


		for(int i = 0; i < n; i++)
		{
			if((left[i] != 0 && right[i] != 0))
			{
				result[i] = min(left[i],right[i]);
			}
			else
			{
				result[i] = 0 ;
			}
			
		}
		cout << accumulate(result.begin(),result.end(),0);

}

void easiest(vector<int> &elements)
{
	vector<int> left,right,result;
	double n = elements.size();
	left.assign(n,0);right.assign(n,0);result.assign(n,0);
	left[0] = elements[0];
	right[n-1] = elements[n-1];
	for (int i = 1; i < n; i++)
	{
		left[i] = max(left[i-1],elements[i]);
	}

	for (int i = n-2; i > -1 ; i--)
	{
		right[i] = max(right[i+1],elements[i]);
	}

	for (int i = 0; i < n; i++)
	{
		result[i] = min(left[i],right[i]) - elements[i];
	}

	cout << accumulate(result.begin(),result.end(),0) << endl;
} 


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vector<int> building;

	int t,n,temp; cin >> t;
	while(t--)
	{
		building.clear();
		
		cin >> n;
	
		for(int i = 0 ; i < n; i++)
		{
			cin >> temp;
			building.push_back(temp);
		}

		display(building);

		// myapproach(elements);
		easiest(building);


		


	}



}