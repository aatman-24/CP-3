#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;


vector<vii> AdjList;
vector<pair<int,ii>> EdgeList;



void display_vd(vector<double> &arr)
{
	for(double i = 0; i < arr.size() ; i++) cout << arr[i] << ' ';
	cout << endl;
}

vector<double> find_first_occurance(string s1,char b)
{
	vector<double> result;
	for(double i = 0; i < s1.size() ; i++)
	{
		if(s1[i] == b) result.push_back(i);
	}
	if(result.size() == 0) result.push_back(-1);
	return result;
}




string merge_two_comp(string s1_temp,string s2)
{

	double j;
	double n = s1_temp.size();
	double m = s2.size();
	

	vector<double> result = find_first_occurance(s1_temp,s2[0]);

	// display_vd(result);
	string re;
	// string s1_temp = s1;
	double min_len = INT_MAX;

	for(double k = 0 ; k < result.size() ; k++)
	{
		string s1 = s1_temp;
		
		j = 0;
		double i = result[k];

		// cout << min_len << endl;

		if(i == -1)
		{
			if(min_len > (m + n - 2))
			{
				min_len = m + n  - 2;
				re = s1 + s2;
			}
			continue;
		}

		while(j < m)
		{
			if(i < n)
			{
				if(s1[i] != s2[j]) 
				{
					if(min_len > (m + n - 2))
					{
						min_len = m + n - 2;
						re = s1 + s2;
						// cout << re << "-----" << endl;
					}
					break;	
				}
				i++;j++;
			}
			else
			{
				// cout << s1 << endl;
				s1 += s2[j];
				j++;
			}

			// if((min_len > s1.size()))
			// {
			// 	re = s1;
			// 	min_len = s1.size();
			// 	// cout << min_len << "------" << endl;
			// }

		}

		

		// cout << s1 << "----------" << endl;
	}

	// cout << re << endl;
	return re;

	// cout << i << endl;

		

}



void display(vector<string> vs)
{
	for(double  i = 0 ; i < vs.size() ; i++) cout << vs[i] << ' ';
	// cout << endl;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	// int mcout << i << endl;,
	int t; cin >> t;
	for(int t_c = 1 ; t_c <= t ; t_c++)
	{
		int m;
		cin >> m;
		string temsp = "ab";
		vector<string> comp(m,temsp);
		for(int i = 0; i < m ;i++) cin >> comp[i];


		// vi perm_arr(n,0);
		// for(int i = 0 ; i < m ; i++) perm_arr[i] = i;

		// display(comp);

		double min_len = INT_MAX;

		do{
			// display(comp);
			string temp = comp[0];
			for(int i = 1; i < m ;i++)
			{
				// here check whether i has any suffix in i+1 result or not.
				// if(temp.size() > min_len) break;
				// cout << temp << '|' << comp[i] << endl;
				temp = merge_two_comp(temp,comp[i]);
				// cout << temp << endl;
				// cout << endl;

			}
			// cout << endl;
			if(temp.size() < min_len) 
				{
					// display(comp);
					// cout << temp << "________________" <<  temp.size() << endl;
					min_len = temp.size();
				}

		}while(next_permutation(comp.begin(),comp.end()));


		cout << "Case "<< t_c <<": " << min_len << endl;
		// cout << min_len << endl;

		// break;

	}


	// string s1 = "atmandfafdsa";

	// cout << s1.find('k') << endl;

	return 0;

}