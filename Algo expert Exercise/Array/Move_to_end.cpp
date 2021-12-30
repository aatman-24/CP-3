#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 4: Move Same Elements to End. O(N) - O(1). (Two Pointer apporach).



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


	int m,match,temp,p1,p2;
	vector<int> elements;
	cin >> m >> match;
	while(m--)
	{
		cin >> temp;
		elements.push_back(temp);
	}
	p1 = 0;
	p2 = elements.size() - 1;
	while(p1 < p2)
	{
		if(elements[p1] == match)
		{
			while((p1 < p2) && (elements[p2] == match))
			{
				p2--;
			}
			swap(elements[p1],elements[p2]);
			p1++;
			p2--;
		}
		else 
		{
			p1++;
		}
	}
	display(elements);
	return 0;
	
}	



