	#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 7: Subarray sort. O(N) - O(1). N = Total Elements.


// # Apporach : 1) Find last_index and Min value. (my apporach)
				// 2) Find min_val and max_val both and target its location.


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

	// #Method 1: My apporach
	vector<int> elements;
	int t; cin >> t;
	int max_ele,last_index,min_val,first,set,need;

	// (AlgoExpert) - Find Peak and find Length.
	int n,temp;
	while(t--)
	{
		cin >> n;
		for(int i = 0 ; i < n ;i++)
		{
			cin >> temp;
			elements.push_back(temp);
		}
		set = 1;
		need = 0;
		max_ele = elements[0];

		for(int i = 0 ; i < n ;i++)
		{
			if(max_ele > elements[i])
			{
				need = 1;
				if(set == 1)
				{
					min_val = elements[i];
					set = 0;
				}
				if((set != 1) && (min_val > elements[i]))
				{
					min_val = elements[i];
				}
				last_index = i;
			}
			else
			{
				max_ele = elements[i];
			}
		}

		if(need)
		{
			for(int i = 0 ; i < n;i++)
			{
				if(elements[i] > min_val)
				{
					first = i;
					break;
				}
			}
		}


		if(need)
		{
			cout << first << ' ' << last_index << endl;
		}
		else
		{
			cout << "Already Sorted" << endl;
		}
		
		elements.clear();

	}

	// #Method 2 : Algo Expert

	vector<int> elements;
	int t; cin >> t;

	int n,temp,min_val,max_val,first,second,set;
	while(t--)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> temp; elements.push_back(temp);
		}

		set = 1;
		for(int i = 0 ; i < n ;i++)
		{
			if(i == 0)
			{
				if(elements[i] > elements[i+1])
				{
					min_val =  elements[i+1];
					max_val = elements[i];
					set = 0;
				}
			}
			else if(i == n-1)
			{
				if(elements[i] < elements[i-1])
				{
					if(set)
					{
						min_val = elements[i];
						max_val = elements[i - 1];
						set = 0;
					}
					else
					{
						if(min_val > elements[i]) min_val = elements[i];
						if(max_val < elements[i]) max_val = elements[i];
					}
				}
			}
			else
			{

				if(!((elements[i] < elements[i+1]) && (elements[i] > elements[i-1])))
				{
					if(set)
					{
						min_val = elements[i];
						max_val = elements[i];
						set = 0;
					}
					else
					{
						if(min_val > elements[i]) min_val = elements[i];
						if(max_val < elements[i]) max_val = elements[i];
					}
				}
			}

		}




		for(int  i = 0 ;i < n;i++)
		{
			if(elements[i] > min_val)
			{
				first = i;
				break;
			}

		}
		for (int i = n-1 ; i > -1 ;i--)
		{
			if(elements[i] < max_val)
			{
				second = i;
				break;
			}
		}


		if(!set) cout << first << ' ' << second << endl;
		else cout << "Already Sorted" << endl;
		elements.clear();

	}
	
	return 0;
}	



