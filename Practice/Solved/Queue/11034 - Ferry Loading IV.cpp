#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#define ll long long


using namespace std;




void display(std::vector<std::vector<int>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		for(double j = 0 ; j < temp.at(i).size(); j++)
		{
			cout << temp.at(i).at(j) << ' ';
		}
		cout << endl;
	}
}

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';	
	}
	cout << endl;
}



bool comp(int p1,int p2)
{
	return true;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int l,m,temp,left_cn,right_cn,side,result_count,current_cap;
	deque<int> left_queue;
	deque<int> right_queue;
	string left_ya_right;

	int t; cin >> t;
	while(t--)
	{
		cin >> l >> m;
		l = l * 100;
		left_cn = 0;
		right_cn = 0;
		while(m--)
		{
			cin >> temp >> left_ya_right;
			if(left_ya_right == "left")
			{
				left_queue.push_back(temp);
				left_cn++;
			}
			else
			{
				right_queue.push_back(temp);
				right_cn++;
			}
		}
		if(!(left_cn || right_cn))
		{
			cout << '0' << endl;
			break;
		}
		side = 1;
		result_count = 0;
		while((left_cn) || (right_cn))
		{
			
			if(side)
			{
				if(left_cn != 0)
				{
					current_cap = 0;
					while((left_cn) && (l >= current_cap + left_queue.front()))
					{
						current_cap += left_queue.front();
						left_queue.pop_front();
						left_cn--;
					}
				}	
				side = 0;
				result_count++;
			}
			else
			{
				
				if(right_cn != 0)
				{
					current_cap = 0;
					while((right_cn) && (l >= current_cap + right_queue.front()))
					{
						current_cap += right_queue.front();
						right_queue.pop_front();
						right_cn--;	
					}
				}
				side = 1;
				result_count++;
			}
		}
		cout << result_count << endl;
		left_queue.clear();
		right_queue.clear();
	}
	
	
}	



