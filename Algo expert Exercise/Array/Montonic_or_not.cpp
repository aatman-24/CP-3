#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 4: Given Array is Monotonic or Not. O(M*logM + N*logN) - O(1).
// Monotonic means not increasing || not decresing.

// like...
// -1 -5 -10 -1100 -1100 -1101 -1102 -9000 ->> Monotonic
// 1 1 1 2 3 4 3 5 ->> Not Monotonic.


void display(vector<int> temp)
{
	for(double i = 0 ; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';
	}
	cout << endl;
}

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int m,temp,p1;
	vector<int> elements;
	int t; cin >> t;
	while(t--)
	{
		cin >> m;
		while(m--)
		{
			cin >> temp;
			elements.push_back(temp);
		}
		p1 = 0;
		m = elements.size();
		int set = 0;
		while(p1 < m - 1)
		{
			if(elements[p1] == elements[p1+1])
			{
				p1++;
			}
			else
			{
				if(elements[p1] < elements[p1+1])
				{
					while(p1 < m - 1)
					{
						if(elements[p1] > elements[p1+1])
						{
							set = 1;
							break;
						}
						p1++;
					}
				}
				else
				{
					while(p1 < m - 1)
					{
						if(elements[p1] < elements[p1+1])
						{
							set = 1;
							break;
						}
						p1++;
					}
				}
				if(set) break;
			}

		}
		if(set) cout << "Non Monotonic" << endl;
		else cout << "MOnotonic" << endl;
		elements.clear();
	}
	
	return 0;
	
}	



