#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;





// #Question 11: Calendar matching. O(N) - O(N). N = Total Elements.


// # Apporach : 1) Naive Approach. O(N^2) - O(N). (update Previous value)
			//  2) Merge both with considering both the time limit and try to find gap. O(N).
	


void display(vector<pair<int,int>> &ele)
{
	int m = ele.size();
	for(double i = 0 ; i < m; i++)
	{
		cout << ele[i].first << '-' << ele[i].second << ' ';
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


	// vector<int> elements;

	vector<pair<int,int>> first,second,result;

	int duration,time_slot,hrs,u_lim,l_lim,max_lim_first,minute,min_lim_first,max_lim_second,min_lim_second;
	char del;
	int t; cin >> t;
	while(t--)
	{
		cin >> time_slot;
		while(time_slot--)
		{
			cin >> hrs >> del >> minute;
			u_lim = hrs*60 + minute;
			cin >> del;
			cin >> hrs >> del >> minute;
			l_lim = hrs*60 + minute;
			first.push_back({u_lim,l_lim});
		}

		cin >> hrs >> del >> minute >> del;
		min_lim_first = hrs*60 + minute;
		cin >> hrs >> del >> minute; 
		max_lim_first = hrs*60 + minute;

		cin >> time_slot;
		while(time_slot--)
		{
			cin >> hrs >> del >> minute;
			u_lim = hrs*60 + minute;
			cin >> del;
			cin >> hrs >> del >> minute;
			l_lim = hrs*60 + minute;
			second.push_back({u_lim,l_lim});
		}

		cin >> hrs >> del >> minute >> del;
		min_lim_second = hrs*60 + minute;
		cin >> hrs >> del >> minute; 
		max_lim_second = hrs*60 + minute;


		cin >> duration;


		display(first);
		display(second);

		int uper = max(min_lim_second,min_lim_first);
		int lower = min(max_lim_second,max_lim_first);

		first.push_back({lower,lower});
		second.push_back({lower,lower});

		cout << uper << ' ' << lower << endl;

		double i = 0,j = 0;
		double n,m;
		n = first.size(); m = second.size();
		while(first.at(i).second < uper) i++;
		while(second.at(j).second < uper) j++;
		
		while(i < n - 1  ||  j < m - 1)
		{

			while((i < n -1 ) && abs(first.at(i).second - first.at(i+1).first) < 30) i++;
			while((j < m -1 ) && abs(second.at(j).second - second.at(j+1).first) < 30) j++;

			int next_val = min(first.at(i+1).first,second.at(j+1).first);
			if(first.at(i).second < second.at(j).second)
			{
				if((next_val - second.at(j).second >= 30)) result.push_back({second.at(j).second,next_val});
			}
			else
			{
				if((next_val - first.at(i).second >= 30)) result.push_back({first.at(i).second,next_val});
			}
			i++;j++;
		}

		for(double k = 0 ; k < result.size() ;k++)
		{
			cout << int(result[k].first/60) << ':' ;
			cout << (result[k].first/60.0 - round(result[k].first/60))*60;
			cout << '-';
			cout << int(result[k].second/60) << ':' ;
			cout << (result[k].second/60.0 - round(result[k].second/60))*60;
			cout << endl;
			
		}
	}
	return 0;
}	



