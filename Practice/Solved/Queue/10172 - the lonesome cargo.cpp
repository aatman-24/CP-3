#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>

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



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif


	int cost,N,items_in_queue,total_ele,item,index;
	double MAX_CAPCITY_OF_STACK,MAX_CAPCITY_OF_QUEUE;
	vector<deque<int>> all_queue;
	int t; cin >> t;
	while(t--)
	{
		cin >> N >> MAX_CAPCITY_OF_STACK >> MAX_CAPCITY_OF_QUEUE;
		stack<int> st;
		total_ele = 0;
		for(int i = 0 ; i < N; i++)
		{
			deque<int> temp;
			cin >> items_in_queue;
			total_ele += items_in_queue;
			while(items_in_queue--)
			{
				cin >> item;
				temp.push_back(item);
			}
			all_queue.push_back(temp);
		}
	
		index = -1;
		cost = 0;
		while(total_ele)
		{

			index = (index + 1) % N;

			// unloading
			if(!st.empty())
			{
					while(!st.empty())
					{
						if(st.top() == index+1)
						{
							total_ele -= 1;;
							st.pop();

						}
						else
						{
							if(all_queue.at(index).size() >= MAX_CAPCITY_OF_QUEUE) break;
							all_queue.at(index).push_back(st.top());
							st.pop();

						}
						cost += 1;
					}

			}

			while((st.size() < MAX_CAPCITY_OF_STACK) && (!all_queue.at(index).empty()))
			{
				int ele = all_queue.at(index).front();
				cost += 1;
				st.push(ele);
				all_queue.at(index).pop_front();
			}
 
			if(total_ele) cost += 2;
		}
		cout << cost << endl;
		all_queue.clear();
	}

	


}	



// sudo-code:

// test case
// MAX_CAPCITY_OF_STACK;
// MAX_CAPCITY_OF_QUEUE;

// 	cost  = 0;

// 	N(number of the stations) S(Stack capcity) Q(A platform capacity)

// 	vector_of_all_queue;

// 	while(N--)
// 	{

// 		create a deque;

// 		num_of_iterms_in_queue
// 		num_of_total_package += num_of_iterms_in_queue
// 			while(num_of_iterms_in_queue--)
// 			{
// 				add_items_in_queue <-- items_of_queue 
				
// 			}
// 		add queue -> vector_of_all_queue;
// 	}

// 	stack st;
// 	vector<int> st_element(N,0);
// 	index = -1;
// 	while(all_element_ != 0)
// 	{
// 		index = (index+1) % N;

// 		if(st_is_not_empty)
// 		{
// 			if(s.top == index+1)
			// {
				 // s.pop() cost+=1
			// }
			// else
			// {
			// 	if(all_queue.at(index).size() >= MAX_CAPCITY_OF_QUEUE) break;
			// 	all_queue.at(index).push_back(st.top());
			// 	st.pop();
			// }
// 		}
// 		if(st_is_not_full && queue is not empty)
// 		{
// 			add element into the stack from the queue.
// 			stack relaxation.
// 		}
// 	}