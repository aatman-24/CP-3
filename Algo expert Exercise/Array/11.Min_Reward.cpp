#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;





// #Question 11: Min Reward. O(N) - O(N). N = Total Elements.


// # Apporach : 1) Naive Approach. O(N^2) - O(N). (update Previous value)
			//  2) MIN Local Approach. O(N) - O(N) . (expand from the Local Minimum) - O(3*N).
			//  3) Best And Easiest. O(N) - O(N). Total Time - O(2*N). 


void display(vector<int> &ele)
{
	for(double i = 0 ; i < ele.size(); i++)
	{
		cout << ele[i] << ' ';
	}
	cout << endl;
}

void naiveApproach(vector<int> elements)
{
	double n = elements.size();
	vector<int> cost(n,1);
	for (int i = 1; i < n; i++)
	{
		int j = i;
		while(j > 0 && elements[j-1] > elements[j])
		{
			cost[j-1] = max(cost[j-1],cost[j]+1);
			j--;
		}
		if(elements[i-1] < elements[i])
		{
			cost[i] = cost[i-1]+1;;
		}
	}
	display(cost);
	cout << accumulate(cost.begin(),cost.end(),0) << endl;
}


void FindLocalMinIndex(vector<int> &elements,vector<int> &local_indexs)
{
	int n = elements.size();
	if(n == 1)
	{
		local_indexs.push_back(0);
	}
	else
	{
		for(double i = 0 ; i < n; i++)
		{
			if(i == 0)
			{
				if(elements[i] < elements[i+1]) local_indexs.push_back(i);
			}
			else if(i == n - 1)
			{
				if(elements[i-1] > elements[i]) local_indexs.push_back(i);
			}
			else if(elements[i] < elements[i-1] && elements[i] < elements[i+1])
			{
				local_indexs.push_back(i);
			}
		}
	}
	
}


void ExpandLocal(vector<int> &arr,vector<int> &cost,int index)
{
	int left = index;
	int right = index;
	double n = arr.size();
	while(left > 0 && arr[left-1] > arr[left])
	{
		cost[left-1] = max(cost[left-1],cost[left]+1);
		left--;
	}
	while(right < n - 1 && arr[right] < arr[right+1])
	{
		cost[right+1] = cost[right] + 1;
		right++;
	}
	
}

void LocalMinimun(vector<int> elements)
{
	double n = elements.size();
	vector<int> local;
	vector<int> cost(n,1);

	FindLocalMinIndex(elements,local);

	for(double i = 0 ; i < local.size(); i++)
	{
		int val = local[i];
		ExpandLocal(elements,cost,val);
	}
	display(cost);
	cout << accumulate(cost.begin(),cost.end(),0) << endl;
}

void bestAndEfficient(vector<int> elements)
{
	int n = elements.size();
	vector<int> cost(n,1);
	for(int i = 1 ; i < n ; i++)
	{
		if(elements[i-1] < elements[i])
		{
			cost[i] = cost[i-1] + 1;
		}
	}
	for(int i = n - 1; i > 0 ;i--)
	{
		if(elements[i-1] > elements[i])
		{
			cost[i-1] = max(cost[i-1],cost[i] + 1);
		}
	}
	display(cost);
	cout << accumulate(cost.begin(),cost.end(),0) << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vector<int> elements;
	int t; cin >> t;


	int m,temp;
	while(t--)
	{
		cin >> m;
		for(int i = 0 ; i < m ;i++)
		{
			cin >> temp;
			elements.push_back(temp);
		}
		naiveApproach(elements);
		LocalMinimun(elements);
		bestAndEfficient(elements);
	}
	return 0;
}	



