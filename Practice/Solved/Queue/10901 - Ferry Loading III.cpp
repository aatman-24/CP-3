#include <bits/stdc++.h>
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

	int n,t,m,c_time,time,ferry_cn,index,lf_cn,rt_cn;
	string c_side;
	std::deque<pair<int,int>> dq;
	std::deque<int> left,right;
	std::vector<int> result;
	int test; cin >> test;
	
	while(test--)
	{
		lf_cn = 0;
		rt_cn = 0;
		cin >> n >> t >> m;
		int m_count = 0;
		while(m_count < m)
		{
			cin >> c_time >> c_side;
			if (c_side == "left")
			{
				dq.push_back({c_time,1});
				left.push_back(m_count);
				lf_cn++;
					
			} 
			else
			{
				dq.push_back({c_time,0});
				right.push_back(m_count);
				rt_cn++;
			} 
			m_count++;
		}


		result.assign(m,0);

		time = 0;
		int m_copy = m;
		int set = 1;
		while(m_copy != 0)
		{
			if(set)
			{
				ferry_cn = 0;
				index = left.front();
				while(lf_cn != 0)
				{

					if((ferry_cn < n) && (dq.at(index).first <= time))
					{
			
						result[index] = time + t;
						left.pop_front();
						index = left.front();
						m_copy--;
						ferry_cn++;
						lf_cn--;

					}
					else  break;
				}
				if(ferry_cn == 0) 
				{
					if(rt_cn == 0 || (lf_cn != 0 && (right.front() > left.front())))
					{
						time = max(dq.at(left.front()).first,time);
						set = 1;

					} 
					else 
					{
						time = max(dq.at(right.front()).first,time) + t;
						set = 0;
					}
				}
				else
				{
					time += t;
					set = 0;
				}

			}
			else
			{
				ferry_cn = 0;
				index = right.front();
				while((index < m )&& (rt_cn != 0))
				{
					if((ferry_cn < n) && (dq.at(index).first <= time))
					{
						result[index] = time + t;
						right.pop_front();
						index = right.front();
						m_copy--;
						ferry_cn++;
						rt_cn--;

					}
					else break;
				}
				if(ferry_cn == 0) 
				{
					if(rt_cn == 0 || (lf_cn != 0 && (right.front() > left.front())))
					{
						time = max(dq.at(left.front()).first,time) + t;
						set = 1;

					} 
					else 
					{
						time = max(dq.at(right.front()).first,time);
						set = 0;
					}
				}
				else
				{
					time += t;
					set = 1;
				}
			}
		}
		display(result);

		result.clear();
		dq.clear();
		right.clear();
		left.clear();

		if(test != 0) cout << endl;

	}


}	



