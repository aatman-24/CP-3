#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<int> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{

			cout << temp.at(i) << ' ';
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int N,set1,max_ele,tem_ele,temp,in_store_ele;
	stack<int> all_ele_st;
	vector<int> in_store;
	while(cin >> N ,(N || 0))
	{
	
		for(int i = N ; i > 0 ;i--)
			{
				all_ele_st.push(i);
			}
			
			while(cin >> temp,(temp || 0))
			{
				stack<int> all_ele_st_copy(all_ele_st);
				stack<int> less_stack,result_stack;
				max_ele = -1;
				set1 = 0;
				in_store.assign(N,0);
				in_store[0] = temp;

				for(int i = 1 ; i < N ;i++)
				{
					cin >> temp;
					in_store[i] = temp;
				}
				// display(in_store);
				for(int index = 0 ; index < N ;index++)
				{
					in_store_ele = in_store[index];
					if(max_ele <= in_store_ele)
					{
						while(in_store_ele != all_ele_st_copy.top())
						{
							tem_ele = all_ele_st_copy.top();
							max_ele = max(tem_ele,max_ele);
							less_stack.push(tem_ele);
							all_ele_st_copy.pop();	
						}
						result_stack.push(all_ele_st_copy.top());
						max_ele = max(all_ele_st_copy.top(),max_ele);
						all_ele_st_copy.pop();
					}
					else
					{

						if(in_store_ele == less_stack.top())
						{
							tem_ele = less_stack.top();
							result_stack.push(tem_ele);
							less_stack.pop();	
						}
						else
						{
							set1 = 1;
							break;
						}
					}

				}
				if((result_stack.size() == double(N)) && (set1 == 0))
				{
					cout << "Yes" << endl;
				}
				else cout << "No" << endl;
				in_store.clear();
			}
	cout << endl;
	}
	
}




