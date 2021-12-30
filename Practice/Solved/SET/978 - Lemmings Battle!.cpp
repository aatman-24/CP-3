#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>


using namespace std;

int main()
{


	double b,gs,bs,temp,temp_b;
	vector<int> blue,green;
	int t; cin >> t;

	while(t--)
	{
		priority_queue<int> pq_g,pq_b;
		cin >> b >> gs >> bs;
		for(int i = 0 ; i < gs;i++)
		{
			cin >> temp;
			pq_g.push(temp);
		}
		for(int i = 0 ; i < bs;i++)
		{
			cin >> temp;
			pq_b.push(temp);
		}

		
		while(true)
		{
			temp_b = b;
			blue.clear(); green.clear();
			if(!(pq_b.empty() || pq_g.empty())) 
			{
				while(temp_b--)
				{
					if (pq_g.top() == pq_b.top())
					{	
						pq_g.pop(); pq_b.pop();
					}
					else if(pq_g.top() > pq_b.top())
					{
						temp = pq_g.top() - pq_b.top();
						pq_g.pop(); pq_b.pop();
						green.push_back(temp);
					}
					else
					{
						temp = pq_b.top() - pq_g.top();
						pq_g.pop(); pq_b.pop();
						blue.push_back(temp);
					}
					if(pq_b.empty() || pq_g.empty()) break;	
				}
				for(double i = 0;i < green.size();i++)
				{
					pq_g.push(green[i]);
				}
				for(double i = 0;i < blue.size();i++)
				{
					pq_b.push(blue[i]);
				}
			}
			else
			{
				break;
			}
				
		}

		if(pq_b.empty() && pq_g.empty()) cout << "green and blue died" << endl;
		else if(pq_g.empty())
		{
			cout << "blue wins" << endl;
		}
		else if(pq_b.empty())
		{
			cout << "green wins" << endl;
		}
		else
		{
				if(pq_b.top() == pq_g.top())
					{
						cout << "green and blue died" << endl;

					}
				else if(pq_b.top() > pq_g.top())
					{
						cout << "blue wins" << endl;
					}
				else
					{
						cout << "green wins" << endl;
					}
				pq_g.pop(); pq_b.pop();
		}
			
		while(!pq_b.empty())
		{
			cout << pq_b.top() << endl;
			pq_b.pop();
		}

		while(!pq_g.empty())
		{
			cout << pq_g.top() << endl;
			pq_g.pop();
		}
		if(t != 0) cout << endl;
	}
	return 0;
}	



