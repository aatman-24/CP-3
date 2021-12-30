#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;





int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	ll int visitedToken,i,p,c,t;
	vector<int> visited;
	vector<int> queue_in_or_not;
	deque<int> dq;

	ll int temp,pointer;
	char next;
	t = 0;
	while(cin >> p >> c,(p || c))
	{
		cout << "Case " << ++t << ":\n";
		visited.assign(p,-1);
		queue_in_or_not.assign(p,0);
		pointer = -1;
		int count_n = 0;
		i = 0;
		while(i < c)
		{
			visitedToken = int(count_n / p);
			cin >> next;
			if(next == 'N')
			{
				if (!dq.empty())
				{
					while(queue_in_or_not[dq.front()] != 1)
					{
						dq.pop_front();
						if(dq.empty() == 1) break;
					}
					if(!dq.empty())
					{
						cout << dq.front()+1 << endl;
						visited[dq.front()]++;
						queue_in_or_not[dq.front()] = 0;

						dq.pop_front();
					}
					else 
					{
						pointer = (pointer+1) % p;
						while (visited[pointer] >= visitedToken)
						{
							pointer = (pointer+1) % p;
						}
						visited[pointer]++;
						cout << (pointer+1) << endl;
					}
				}
				else
				{
					pointer = (pointer+1) % p;
					while (visited[pointer] >= visitedToken)
					{
						pointer = (pointer+1) % p;
					}
					visited[pointer]++;
					cout << (pointer+1) << endl;
				}
				count_n++;

			}
			else
				{
					cin >> temp;
					dq.push_front(temp-1);
					queue_in_or_not[temp-1] = 1;
				}
			i++;
		}
		visited.clear();
		dq.clear();
		queue_in_or_not.clear();
	}	

}
