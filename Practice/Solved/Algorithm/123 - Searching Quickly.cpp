
#include <iostream>
#include <string>
#include <vector>
#include <pair>
#include <algorithm>



using namespace std;

vector<string> ignore_me;





void captiliaze(string &s)
{
	for(double i = 0 ; i < s.size() ; i++)
	{
		s[i] = char(int(s[i]) - 32);
	}
}

void lower(string &s)
{
	for(double i = 0 ; i < s.size() ; i++)
	{
		s[i] = char(int(s[i]) + 32);
	}
}


bool string_is_not_ignorable(string &str)
{
	for(double i = 0 ; i < ignore_me.size();i++)
	{
		if(ignore_me[i] == str) return false;
	}
	return true;
}


int main()
{


	string temp;
	
	vector<string> temp_list;
	vector<vector<string>> line_two_d;
	vector<pair<string,int>> how_much_time;
	vector<pair<string,pair<int,int>>> all_main_words;
	while(cin >> temp)
	{
		if(temp == "::") break;
		ignore_me.push_back(temp);
	}
	string s;
	getline(cin,temp); // Space 
	int line = 0;
	while(getline(cin,temp))
	{
		s = "";
		for(double j = 0 ; j <= temp.size(); j++)
		{
			if((j == temp.size())||temp[j] == ' ')
			{
				if(s.size() == 0) continue;
				if(string_is_not_ignorable(s))
				{
					int count = -1;
					for(double i = 0 ; i < how_much_time.size();i++)
					{
						if(how_much_time.at(i).first == s)
						{
							how_much_time.at(i).second += 1;
							count = how_much_time.at(i).second;

						}
					}
					if(count == -1) 
					{
						how_much_time.push_back({s,++count});
					}
					all_main_words.push_back({s,{line,count}});
				}
				temp_list.push_back(s);
				s = "";
			}
			else
			{
				if(temp[j] <= 90)
				{
					s += char(int(temp[j])+32);
				} 
				else s += temp[j];
			}

			
		}
		line_two_d.push_back(temp_list); temp_list.clear();
		how_much_time.clear();
		line++;
	}

	sort(all_main_words.begin(),all_main_words.end());
	for(double i = 0 ; i < all_main_words.size();i++)
	{
		string sr = all_main_words.at(i).first;
		int line = all_main_words.at(i).second.first;
		int occ = all_main_words.at(i).second.second;
		int time = -1;
		vector<string> star = line_two_d.at(line);
		for(double j = 0 ; j < star.size() ;j++)
		{	
			if(star.at(j) == sr) time++;
			if(j != star.size() -  1)
			{

				if((star[j] == sr) && (time == occ)) 
					{
						captiliaze(sr);
						cout << sr << ' ';
					}
				else cout << star[j] <<  ' ';
			}
			else
			{
				if((star[j] == sr)  && (time == occ)) 
				{
					captiliaze(sr);
					cout << sr << endl;
				}
				else cout << star[j] << endl;
			}

			
		}
	}



}	



