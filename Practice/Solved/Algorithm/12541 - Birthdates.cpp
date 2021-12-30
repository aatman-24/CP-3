#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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


class Person
{
public:
	string name;
	int year;
	int month;
	int date;
};


bool comp(Person p1,Person p2)
{
	if (p1.year < p2.year) return true;
	else if((p1.year == p2.year) && (p1.month < p2.month)) return true;
	else if((p1.year == p2.year) && (p1.month == p2.month) && (p1.date < p2.date)) return true;
	else return false;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	vector<Person> all_person;

	int t; cin >> t;
	while(t--)
	{
		Person p;
		cin >> p.name >> p.date >> p.month >> p.year;
		all_person.push_back(p);
	}


	sort(all_person.begin(),all_person.end(),comp);


	cout << all_person[all_person.size()-1].name << endl;
	cout << all_person[0].name << endl;


}	



