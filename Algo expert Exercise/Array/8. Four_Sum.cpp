#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 7: Four elements Sum. O(N^2) - O(N^2) || O(N^3) - O(n).   N = Total Elements.


// # Apporach : 1) Two Pointer + Two Extra Pointer(left and right)


void display(vector<int> temp)
{
	for(double i = 0 ; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';
	}
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



	// #Method 1 : Striver Method: Or Normal Method. O(N^3) - O(n(only for pairs)).

	vector<int> elements,temp_vec;
	vector<vector<int>> ans;
	int temp,n,sum,left,right;
	int t; cin >> t;
	while(t--)
	{
		cin >> n >> sum;
		for (int i = 0; i < n; i++)
		{
			cin >> temp;
			elements.push_back(temp);
		}

		sort(elements.begin(), elements.end()); // Sort Elements.


		int currentsum;

		for (int i = 0; i < n - 1 ; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				currentsum = elements[i] + elements[j];
				left = j + 1;
				right = n-1;
				while(left < right)
				{
					if(elements[left] + elements[right] + currentsum == sum)
					{
						temp_vec = {elements[i],elements[j],elements[left],elements[right]};
						ans.push_back(temp_vec);
						left++; right--;
						temp_vec.clear();
					}
					else if(elements[left] + elements[right] + currentsum < sum)
					{
						left++;
					}
					else
					{
						right--;
					}
				}
			}
		}

		for(double i = 0 ; i < ans.size() ; i++)
		{

			for (int j = 0; j < 4; j++)
			{
				cout << ans[i][j] << ' ';
			}
			cout << endl;
			
		}
		
		ans.clear();


	}





	// #Method 2 : Algo Expert Method O(N^2) - O(N^2).

	vector<int> elements,temp_vec;
	map<int,vector<pair<int,int>>> mapper;
	vector<pair<int,int>> vector_pair;
	vector<vector<int>> ans;
	int temp,n,sum,cur_sum;

	int t; cin >> t;
	while(t--)
	{
		cin >> n >> sum;
		for (int i = 0; i < n; i++)
		{
			cin >> temp; elements.push_back(temp);
		}
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				cur_sum = elements[i] + elements[j];
				if(mapper.find(sum - cur_sum) != mapper.end())
				{
					vector_pair = mapper[sum - cur_sum];
					for(double p = 0; p < vector_pair.size(); p++)
					{

						temp_vec = {elements[i],elements[j],vector_pair[p].first,vector_pair[p].second};
						ans.push_back(temp_vec);
						temp_vec.clear();
					}
				}
			}

			for (int k = 0; k < i; k++)
			{
				cur_sum = elements[i] + elements[k];
				mapper[cur_sum].push_back({elements[i],elements[k]});
			}
		}


	for(double i = 0 ; i < ans.size() ; i++)
	{

		for (int j = 0; j < 4; j++)
		{
			cout << ans[i][j] << ' ';
		}
		cout << endl;
		
	}


}

	return 0;
}	



