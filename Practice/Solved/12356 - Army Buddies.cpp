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

	while(1)
	{
		int soldier,no_of_report;
		cin >> soldier >> no_of_report;
		if(!(soldier || no_of_report)) break;
		std::vector<int> v(soldier+2,0);
		std::vector<int> left(soldier+2,0);
		std::vector<int> right(soldier+2,0);
		for(int i = 1; i <= soldier; i++)
		{
			v[i] = i;
			left[i] = i - 1;
			right[i] = i + 1;
		} 
		while(no_of_report--)
		{
			int l,r;
			cin >> l >> r;
			
			// Relaxtion
			right[left[l]] = right[r];
			left[right[r]] = left[l];

			if(left[l] == 0) cout << '*';
			else cout << left[l];
			if(right[r] == soldier+1) cout << " *\n";
			else cout << ' ' <<right[r] << endl;;
		}
		cout << "-\n";
	}
	
}	



