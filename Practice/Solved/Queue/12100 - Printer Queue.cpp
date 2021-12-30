#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pii pair<int,int>


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



// bool comp(Person p1,Person p2)
// {
// 	if (p1.year < p2.year) return true;
// 	else if((p1.year == p2.year) && (p1.month < p2.month)) return true;
// 	else if((p1.year == p2.year) && (p1.month == p2.month) && (p1.date < p2.date)) return true;
// 	else return false;
// }



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	
	vector<int> jobs;
	int t,temp; cin >> t;
	while(t--)
	{
		int n,m; cin >> n >> m;
		int i = 0;
		queue<pair<int,int>> q;
		while(i != n)
		{
			cin >> temp;
			q.push({i,temp});
			jobs.push_back(temp);
			i++;
		}


		sort(jobs.begin(),jobs.end(),greater<int>());

		i = 0;
		int count = 0;
		while(true)
		{

			while(q.front().second != jobs.at(i))
			{
				pii temp_pii = q.front(); q.pop();
				q.push(temp_pii);
			}
			if(q.front().second == jobs.at(i))
			{
				if(q.front().first == m)
				{
					count++;
					break;
				}
				q.pop();
				i++;
				count++;
			}
		}	
		cout << count << endl;
		jobs.clear();



	}

}	



