#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

string key,value,sr="";

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

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';	
	}
	cout << endl;
}


void make_dictnoary_for_me(string line,vector<string> &vs,map<string,string> &mpp)
{
	for(double i = 1; i < line.size() ; i++)
		{	
			if(line[i] == ':')
			{
				key = sr;
				sr = "";
			}
			else if(line[i] == ',' || line[i] == '}')
			{
				value = sr;
				sr = "";
				mpp.insert({key,value});
				vs.push_back(key);
				key=""; value ="";
			}
			else
			{
				sr += line[i];
			}
		}
}


void print_out(vector<string> &temp,char sign)
{
	if(!temp.empty() && temp[0] != "")
	{
		cout << sign << temp.at(0);
		for(double i = 1 ; i < temp.size() ;i++)
		{
			cout << ',' << temp.at(i);
		}
		cout << endl;
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

	vector<string> old_version;
	vector<string> new_version;
	map<string,string> mpp_old;
	map<string,string> mpp_new;
	vector<string> plus;
	vector<string> minus;
	vector<string> multi;

	string line,key,value,sr;
	double p1,p2;

	int t; cin >> t;
	while(t--)
	{

		// getline(cin,line);
		cin >> line;
		make_dictnoary_for_me(line,old_version,mpp_old);
		// getline(cin,line); 
		cin >> line;
		make_dictnoary_for_me(line,new_version,mpp_new);


		sort(old_version.begin(),old_version.end());
		sort(new_version.begin(),new_version.end());

		// display(old_version);
		// display(new_version);


		p1 = 0; p2 = 0;
		while(p1 < old_version.size() && p2 < new_version.size())
		{
			if (old_version[p1] < new_version[p2])
			{
				minus.push_back(old_version[p1]);
				p1++;
			}
			else if(old_version[p1] == new_version[p2])
			{
				if((mpp_old[old_version[p1]] != mpp_new[new_version[p2]]))
				{
					multi.push_back(old_version[p1]);
				}
				p1++; p2++;
			}
			else
			{
				plus.push_back(new_version[p2]);
				p2++;
			}
		}

		while(p1 < old_version.size())
		{
			minus.push_back(old_version[p1]);
			p1++;
		}

		while(p2 < new_version.size())
		{
			plus.push_back(new_version[p2]);
			p2++;		
		}

		print_out(plus,'+');
		print_out(minus,'-');
		print_out(multi,'*');

		if(plus.empty() && minus.empty() && multi.empty())
		{
			cout << "No changes" << endl;
		}

		old_version.clear(); new_version.clear();
		mpp_old.clear();  mpp_new.clear();
		plus.clear(); minus.clear(); multi.clear();
		cout << endl;
	}

	
}	



// sudo code

// t 
// while(t--)
// {
// 	make a two map object from string.
// 	two map m1,m2;
	// two vector two store key old,new;
// 	two pointer p1,p2;
// 	p1 for old one and p2 for new one.

// 	vector +,-.*

// 	while(p1 < m1.size() and p2 < m2.size())
// 	{
// 		if (old[p1] < old[p2])
// 		{
// 			 add old[p1] into - and p1++
// 		}
// 		else if (old[p1] == old[p2])
// 		{
// 			if(old[m[p1]] != old[m[p2]]) and p1 into *
// 			p1++ and p2++
// 		}
// 		else
// 		{
// 			add new[p2] into  + and p2++
// 		}
// 	}

// 	if(p1 != old.size()) add old[p1] into -
// 	if(p2 != new.size()) add new[p2] into +

// }
