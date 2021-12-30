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
		cout << temp.at(i) << ' ';	
	}
	cout << endl;
}



class TeamInfo
{

public:
	// int N = 7;
	int team_no;
	int total_time=0;
	int solve=7;
	int count = 0;
	vector<int> problem = {0,0,0,0,0,0,0};


	void question_is_solved(char pro,int time)
	{
		total_time += (time + problem.at(int(pro) - int('A')) * 20);
		problem.at(int(pro) - int('A')) = 0;
		solve--;
		count++;
	}

	void question_is_not_solved(char pro)
	{
		problem.at(int(pro) - int('A')) += 1;
	}

};


bool comp(TeamInfo t1,TeamInfo t2)
{
	if(t1.solve < t2.solve) 
		{
			return true;
		}
	else if((t1.solve == t2.solve) && (t1.total_time < t2.total_time)) 
		{
			return true;
		}
	else if((t1.solve == t2.solve) && (t1.total_time == t2.total_time) && (t1.team_no < t2.team_no)) 
		{
			return true;
		}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int t; cin >> t;
	while(t--)
	{
		vector<int> register_team(25,0);
		int total_team = 0;
		vector<TeamInfo> all_info;

		int t_no,hrs,minute;
		char pro,sta,dust;

		for(int i = 0 ;i < 25 ;i++)
		{
			TeamInfo temp;
			temp.team_no = i + 1;
			all_info.push_back(temp);
		}

		while(cin >> t_no)
		{

			cin >> pro >> hrs >> dust >> minute >> sta;
			TeamInfo &team = all_info.at(t_no-1);
			if(register_team[t_no-1] == 0)
				{
					register_team[t_no-1] = 1;
					total_team += 1;
				}
			if(sta == 'Y')
			{
				team.question_is_solved(pro,((hrs*60 )+ minute));
			}
			else
			{
				team.question_is_not_solved(pro);
			}
		
		}

		sort(all_info.begin(),all_info.end(),comp);



		cout << "RANK" <<  " TEAM"  << " PRO/SOLVED" <<  " TIME" << endl;

		int rank = 1;
		int i = 0;
		while(i < total_team)
		{
			
			if(all_info.at(i).count != 0)
			{
				cout << "   " << rank << "    " << all_info.at(i).team_no << "    " << all_info.at(i).count << "        " << all_info.at(i).total_time << endl;
				while((all_info.at(i).count != 0) && (i < total_team - 1) && (all_info.at(i).count == all_info.at(i+1).count && all_info.at(i).total_time == all_info.at(i+1).total_time))
				{
					cout << "   " << rank << "    " << all_info.at(i+1).team_no << "    " << all_info.at(i+1).count << "        " << all_info.at(i+1).total_time << endl;
					i++;
				}
			}
			else
			{
					while(i < total_team)
					{
						cout << "   " << rank << "    " << all_info.at(i).team_no << endl;
						i++;
					}
			}
			i++;
			rank = i+1;
			
		}
	}

		

}	



