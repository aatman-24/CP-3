#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


// #Question 5: Spiral Trversal. O(N) - O(1). N = Total Elements.


// # Apporach : Four Pointer.


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


	int m,n,temp;
	int p1,p2,p3,p4,temp_p1,temp_p4,temp_p2,temp_p3,count;
	vector<vector<int>> elements;
	int t; cin >> t;
	while(t--)
	{
		cin >> m; cin >> n;
		for(int j = 0 ; j < m ;j++)
		{
			vector<int> row;
			for(int i = 0 ;i < n ;i++)
			{
				cin >> temp;
				row.push_back(temp);
			}
			elements.push_back(row);
		}


		p1 = 0; p2 = 0; p3 = n-1; p4 = m-1;
		count = m * n;
		while(count && p1<= p3 && p2 <= p4)
		{
			temp_p1 = p1; temp_p2 = p2 + 1 ; temp_p3 = p3 - 1; temp_p4 = p4 -1 ;
			while(count && temp_p1 <= p3)
			{
				cout << elements[p2][temp_p1] << endl;
				temp_p1++;
				count--;
			}
			while(count && temp_p2 <= p4)
			{
				cout << elements[temp_p2][p3] << endl;
				temp_p2++;
				count--;
			}
			while(count && temp_p3 >= p1)
			{
				cout << elements[p4][temp_p3] << endl;
				temp_p3--;
				count--;
			}
			while(count && temp_p4 >= p1 + 1)
			{
				cout << elements[temp_p4][p1] << endl;
				temp_p4--;
				count--;
			}
			p1++;p2++;p3--;p4--;
		}

	}
	return 0;
}	



