#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<pair<int,string>> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i).second << '\n';
	}
}


void seperate_by_space(string book,vector<string> &all_word)
{
	for (double i = 0 ; i < book.size() ;i++)
	{
		string title = "";
		while(book[i] != ' ')
			{
				title += book.at(i);
				i++;
				if(i >= book.size()) break;
			}
			all_word.push_back(title);	
		}
}

int make_only_author_name(std::vector<string> &all_word,string &book_name)
{
	int i = 1;
	string title = "";
	int n = int(all_word.size());
	while (i < n)
	{	
		title = title + all_word.at(i)  + " ";
		i++;
	}
	for (double i = 1; i < title.size()- 2 ;i++) {book_name += title.at(i);}
	if (all_word.at(0) == "BORROW") return 0;
	else return 1;
}


void make_title_author(vector<string> &all_word,string &new_title,string &new_author)
{
	int i = 0;
	string title = "";
	int n = int(all_word.size());
	while (all_word.at(i) != "by")
	{	
		title = title + all_word.at(i)  + " ";
		i++;
	}
	i++;
	string author = "";
	while(i < n)
	{
		author = author +  all_word.at(i) + " ";
		i++;
	}
	for (double i = 1; i < title.size()- 2 ;i++) new_title += title.at(i);
	for (double i = 0; i < author.size()-1 ;i++) new_author += author.at(i);
	all_word.clear();
}

int find_reverse(int temp,vector<string> &sorted_author,std::vector<string> &author)
{
	string author_name = sorted_author.at(temp);
	for(double i = 0 ; i < author.size(); i++)
	{
		if (author_name == author.at(i))
		{
			return i;
		}
	}
	return -1;

}

void do_something(vector<pair<int,string>> &book_return,vector<bool> &visited,vector<string> &title,vector<string> &sorted_author,std::vector<string> &author)
{	
	sort(book_return.begin(),book_return.end());
	// display(book_return);
	for(double i = 0; i < book_return.size();i++)
	{
		int n = book_return.at(i).first;
		// cout << n  << endl;
		int temp = n;
		visited.at(n) = true;
		string book_name = book_return.at(i).second;
		if (temp == 0)
		{
			cout << "Put \"" << book_name << "\" first"  << endl;
		}
		else
		{
			while(temp > 0)
			{
				if(visited[--temp])
				{
					temp = find_reverse(temp,sorted_author,author);
					cout << "Put \"" << book_name << "\" after \"" << title.at(temp) << "\"\n"; 
					break;
				}
				if (temp == 0)
				{
					cout << "Put \"" << book_name << "\" first"  << endl;
					break;
				}
			}		

		}
		

	}
	cout << "END" << endl;
	book_return.clear();
}


int find(const vector<string> &title,string word,vector<string> &sorted_author,std::vector<string> &author)
{
	int key;
	for(double i = 0 ; i < title.size(); i++)
	{
		if (word == title.at(i))
		{
			key = i;
			break;
		}
	}
	string author_name = author.at(key);
	for(double i = 0 ; i < sorted_author.size(); i++)
	{
		if (author_name == sorted_author.at(i))
		{
			return i;
		}
	}
	return -1;
	
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

	string row_data;
	std::vector<string> all_word;
	std::vector<string> author;
	std::vector<string> title;
	std::vector<bool> visited;
	std::vector<pair<int,string>> book_borrow;
	std::vector<pair<int,string>> book_return;
	while(1)
	{
		getline(cin,row_data);
		if (row_data == "END") break;
		seperate_by_space(row_data,all_word);
		string new_title = "";
		string new_author = "";
		make_title_author(all_word,new_title,new_author);
		author.push_back(new_author);
		title.push_back(new_title);
	}
	visited.assign(author.size(),true);
	std::vector<string> sorted_author(author);
	sort(sorted_author.begin(),sorted_author.end());
	while(1)
	{
		getline(cin,row_data);
		if (row_data == "END") break;
		else if (row_data == "SHELVE")
		{
			do_something(book_return,visited,title,sorted_author,author);
		}
		else
		{
			all_word.clear();
			seperate_by_space(row_data,all_word);
			string book_name="";
			if(make_only_author_name(all_word,book_name))
				{
					int a = find(title,book_name,sorted_author,author);
					pair<int,string> pis;
					pis.first = a;
					pis.second = book_name;
					book_return.push_back(pis);
				}
			else 
				{
					int a = find(title,book_name,sorted_author,author);
					visited.at(a) = false;
					pair<int,string> pis;
					pis.first = a;
					pis.second = book_name;
					book_borrow.push_back(pis);
				}
		}
	}


	
}	










