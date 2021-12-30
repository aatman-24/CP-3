#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;

// #Title: Two Number Sum
// 	- two for loops O(N^2) - O(N)
// 	- sort + two pointer O(N*logN) - O(1)
// 	- hash table (map)	O(N) - O(N)


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	vector<int> elements;
	int num,sum,temp,n;
	
	cin >> num >> sum;
	n = num;
	while(num--)
	{
		cin >> temp;
		elements.push_back(temp);
	}


	// # First Method : Two For Loops O(N^2) - O(N)
	for(int i = 0 ; i < n ; i++)
	{
		for (int j = i+1; j < n ;j++)
		{
			if(elements[i] + elements[j] == sum)
			{
				cout << "First Method:\t" <<elements[i] << '+' << elements[j] << "= " << sum << endl;
			}
		}
	}


	// # Second Method : Sort + Two pointer O(N*logN) - O(N)
	vector<int> element =  elements;
	sort(element.begin(),element.end());
	int left = 0;
	int right = element.size() - 1;
	
	while(left < right)
	{
		if(element[left] + element[right] == sum)
		{
			cout << "Second Method:\t" <<element[left] << '+' << element[right] << "= " << sum << endl;
			left++;
			right--;
		}
		else if(element[left] + element[right] < sum )
		{
			left++;
		} 
		else 
		{
			right--;
		}
		
	}


	// #Third Method: Hash table - map  O(N) - O(N)
	map<int,int> mib;
	for (int i = 0; i < n; ++i)
	{
		if(mib.find(sum - elements[i]) == mib.end())
		{
			mib[element[i]] = element[i];
		}
		else
		{
			cout << "Third Method:\t" << elements[i] << '+' << mib[sum - elements[i]] << "= " << sum << endl;
		}
	}

	return 0;
	
}	



