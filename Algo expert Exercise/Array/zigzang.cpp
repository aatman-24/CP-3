#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;





// #Question 11: Zig-Zang TRaversal. O(N) - O(N). N = Total Elements.


// # Apporach : 1) Both My_approach and algoexpert apporach is same except some condition. O(N).


void display(vector<vector<int>> &ele)
{
	int m = ele.size();
	int n = ele[0].size();
	for(double i = 0 ; i < m; i++)
	{
		for(double j = 0 ; j < n ; j++)
		{
			cout << ele[i][j] << ' ';
		}
		cout << endl;	
	}
}	

void display(vector<int> &ele)
{
	for(double i = 0 ; i < ele.size();  i++)
	{
		cout << ele[i] << ' ';
	}
	cout << endl;
}


void MyApproach(vector<vector<int>> &ele)
{
	double m = ele.size();
	double n = ele[0].size();
	vector<int> result;
	int i = 0,j=0;
	while(i < m && j < n)
	{
		if(i == m && j == n)
		{
			result.push_back(ele[i][j]);
			break;
		}
		if(i == j)
		{
			result.push_back(ele[i][j]);
			i++;j--;			//(here downword) First Go in Upward or Downword decided by this step.
			// i--;j++; // for upword.
		}
		else if (i > j)
		{
			while(i > -1 && j < n)
			{
				result.push_back(ele[i][j]);
				i--; j++;
			}
		}
		else
		{
			while(j > -1 && i < m)
			{
				result.push_back(ele[i][j]);
				i++; j--;
			}
		}
		if(i == m && j == n) break;
		if(i < j)
		{
			i++;
			if(j >= n)
			{
				i += (n - j + 1);
				j = n - 1;
			}
		}
		else
		{
			j++;
			if(i >= m)
			{
				j += (m - i + 1);
				i = m - 1;
			}
		}
	}
	display(result);
}






void bestAndEfficient(vector<int> elements)
{

}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	// vector<int> elements;
	int t; cin >> t;


	int m,n;
	while(t--)
	{
		cin >> m >> n;
		vector<vector<int>> elements(m,vector<int>(n,0));
		for(double i = 0 ; i < m; i++)
		{
			for(double j = 0 ; j < n ; j++)
			{
				cin >> elements[i][j];
			}
		}
		// display(elements);
		MyApproach(elements);
		// LocalMinimun(elements);
		// bestAndEfficient(elements);
	}
	return 0;
}	



