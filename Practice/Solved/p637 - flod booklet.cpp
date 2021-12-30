#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << endl;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int a;
	while(cin >> a)
	{
		if (a == 0) break;
		int n = pow(2,ceil(log2(a)));

		std::vector<int> num;
		num.assign(n,0);
		for (double i = 0; i < a ; i++)
		{
			num[i] = i+1;
		}

		double t = 1.0;
		int index = n - 1;
		int f_index;
		int s_index;
		string side;
		int temp = index;

		cout << "Printing order for " << a << " pages:\n";
		if ( a == 1)
		{
			cout << "Sheet 1, front: Blank, 1" << endl;
		}
		while (t != ((n/2)+1))
		{
			f_index = temp;
			s_index =  index - f_index;
			int first = num.at(f_index);
			int second = num.at(s_index);
			if ((!first) && (!second)) break;
			int sheet_num = ceil(t/2);
			int j=0;
			if (f_index > s_index)
			{
				side = "front";
				j++;
			}
			else
			{
				side = "back ";
				j--;
			}
			cout << "Sheet " << sheet_num << " " << side << ":" ;
			if (first == 0) cout << "blank,";
			else cout << first << ", ";
			if (second == 0) cout << "blank" << endl;
			else cout << second << endl;
			temp = index - f_index + j;
			t++;
		}
	}
	
}	



