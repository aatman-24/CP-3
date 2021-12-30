#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


const string charcters = "abcdefghiklmnopqrstuvwxyz";

template <typename T>
void display(vector<T> &temp)
{
	for(double ele = 0 ; ele < temp.size() ; ele++)
	{
		cout << temp[ele] << ' ' ;
	}
	cout << endl;
}



double makePattern(const string &p,vector<char> &vec_pattern)
{
	double n = p.size();
	map<char,char> mapper;
	int j  = 0;
	for(double i = 0; i < n ; i++)
	{
		if(mapper.find(p[i]) == mapper.end())
		{
			mapper[p[i]] = charcters[j];
			vec_pattern.push_back(charcters[j]);
			j++;
		}
		else
		{
			vec_pattern.push_back(mapper[p[i]]);
		}
	}
	return mapper.size();
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	string pattern,text;
	std::vector<char> vec_pattern;

	int t;cin >> t;

	
	double differnt_ele;

	while(t--)
	{
		cin >> pattern >> text;
		differnt_ele =  makePattern(pattern,vec_pattern);


		vector<int> counter_of_differnt_elements(differnt_ele,0);

		for(double i = 0 ; i < pattern.size() ; i++)
		{
			if(differnt_ele > 0 && vec_pattern[i] == charcters[0]) counter_of_differnt_elements[0]++;
			if(differnt_ele > 1 &&  vec_pattern[i] == charcters[1]) counter_of_differnt_elements[1]++;

		}



		int x_pos,y_pos,str_y;
		x_pos = 0;
		if(differnt_ele > 1)
		{
			for(double i = 0; i < pattern.size() ; i++)
			{
				if(vec_pattern[i] == charcters[1])
				{
					str_y = i;
					break;
				}
			}
		}
			

	
		
		string make_x,make_y;

		double n = text.size();
		string temp;

		double len_a,len_b;

		


		if(differnt_ele == 1)
		{
			len_a = n / counter_of_differnt_elements[0] * 1.0;
			if(len_a - int(len_a) == 0)
			{
					for(double i = x_pos ; i < len_a;i++)
				{
					make_x += text[i];
				}
				string temp = "";
				for(double i = 0 ; i < pattern.size() ; i++)
				{
					temp += make_x;
				}
				if(text == temp)
				{
					cout << make_x << endl;
				}
			}
			continue;
		}



		len_a = 1;

		while (len_a * counter_of_differnt_elements[0] < n )
		{
			len_b = (n - len_a * counter_of_differnt_elements[0])/(counter_of_differnt_elements[1] * 1.0);

			if(len_b - int(len_b) == 0)
			{

				make_x = "";
				make_y = "";



				for(double i = x_pos ; i < len_a;i++)
				{
					make_x += text[i];
				}


				y_pos = len_a * str_y;

				for(double i = 0 ; i < len_b;i++)
				{
					make_y += text[y_pos++];
				}

				temp = "";

				for(double i = 0 ; i < pattern.size() ; i++)
				{
					if(vec_pattern[i] == charcters[0]) temp += make_x;
					if(vec_pattern[i] == charcters[1]) temp += make_y;
				}

				if(temp == text)
				{
					cout << make_x << ' ' << make_y << endl;
				}
			}

			len_a++;
		}


	}



}