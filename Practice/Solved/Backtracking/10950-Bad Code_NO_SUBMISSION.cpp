#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>
#define ll long long

using namespace std;

// #Note : Code is true but when you submit on Uva ONLINE_JUDGE you got WA verdict due to format
// the output I tried but i don't know where is the mismatch.

#Approach : 



typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

	

int N,encrypted_string_length,count_all;
string encrypted_string;
vector<pair<string,char>> code_ch;


bool isValid(int i,int nIndex)
{
	string chk = code_ch[i].first;
	for(double j = 0 ; j < chk.size(); j++)
	{
		if(encrypted_string[nIndex] != (chk[j])) return false;
		nIndex++;
	}
	return true;
}


void backtracking(int nIndex,string cur_str)
{
	if(nIndex == encrypted_string_length) {cout << cur_str << endl; count_all++;  return;}

	if(count_all == 100) return;

	while(encrypted_string[nIndex] == '0') 
	{
		nIndex++;
		if((nIndex == encrypted_string_length) && encrypted_string[nIndex-1] == '0') return;
	}

	for(int i = 0 ; i < N; i++)
	{
		if(isValid(i,nIndex))
		{
			string temp = cur_str;
			int p_index = nIndex;
			cur_str += code_ch[i].second;
			nIndex += code_ch[i].first.size();
			backtracking(nIndex,cur_str);
			nIndex = p_index;
			cur_str = temp;
		}
	}

}

string filter_str(string tmp)
{
	int n = (int)tmp.size();
	string nw_str = "";
	int i = 0;

	while(i < n)
	{
		if(tmp[i] != '0') break;
		i++;
	}

	if(i == 0) return tmp;
	else
	{
		for(int j = i ; j < n ;j++)
		{
			nw_str += tmp[j];
		}
	}
	return nw_str;
}

bool sort_func(pair<string,char> p1, pair<string,char> p2)
{
	if(p1.second < p2.second) return true;
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

	int t = 1;
	string temp_str;
	cin >> N;
	while(true)
	{
		if(N == 0) break;
		count_all = 0;
		pair<string,char> pc = {"a",'a'};
		code_ch.assign(N, pc);

		for(int i = 0 ; i < N ; i++)
		{
			cin >> code_ch[i].second >> code_ch[i].first;
		}

		sort(code_ch.begin(), code_ch.end(), sort_func);

		cin >> temp_str;
		encrypted_string =  filter_str(temp_str);
		encrypted_string_length = (int)encrypted_string.size();

		cout << "Case #" << t << endl;
		string temp = "";
		backtracking(0,temp);
		cout << endl;
		cin >> N;
		if(N == 0) {break;}
		t++;
	}




	return 0;
}

