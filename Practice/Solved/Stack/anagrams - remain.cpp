#include <bits/stdc++.h>
#include <iostream>
#define ll long long


using namespace std;

void display(std::vector<string> temp)
{
	for (double i=0; i < temp.size() ; i++)
	{
		cout << temp.at(i) << ' ';	
	}
	cout << endl;
}



string sr,tr,sr_cp,tr_cp;
vector<string> result;
int f_ch_time,let_go;
char f_ch;

void do_opr(string cr,stack<char> cr_stack,stack<char> mid,stack<char> sr_st,int index,int f_time);

void do_ioo(string cr,stack<char> cr_stack, stack<char> mid,stack<char> sr_st,int index,int f_ch_time)
{

	if(sr_st.top() == f_ch) let_go++;
	if(let_go < f_ch_time)
	{
		cout << "heso" << endl;
		cr += 'i';
		mid.push(sr_st.top()); sr_st.pop();

	}
	else
	{
		cr += "io";
		cr_stack.push(sr_st.top()); sr_st.pop();
		index++;
	}
	
	do_opr(cr,cr_stack,mid,sr_st,index,f_ch_time);
}

void do_oio(string cr,stack<char> cr_stack, stack<char> mid,stack<char> sr_st,int index,int f_ch_time)
{
	cr += 'o';
	cr_stack.push(mid.top()); mid.pop();
	index++;
	do_opr(cr,cr_stack,mid,sr_st,index,f_ch_time);
}

void do_opr(string cr,stack<char> cr_stack,stack<char> mid,stack<char> sr_st,int index,int f_time)
{
	// if(cr.size() == (2 * tr.size()))
	if(cr_stack.size() == tr.size())
	{
		result.push_back(cr);
		return;
	}
		cout << cr  << "------------------" << sr_st.size() << endl;

			while((sr_st.size() != 0) && (tr.at(index) != sr_st.top()))
			{
				if((!mid.empty()) && (tr.at(index) == mid.top()) && (let_go > 1)) break;
				mid.push(sr_st.top()); 
				sr_st.pop();
				cr += 'i';
				if(sr_st.empty()) break;
			}
		// }
	
		
		if((!sr_st.empty()) && (tr.at(index) == sr_st.top()) )
		{
			// if()
			do_ioo(cr,cr_stack,mid,sr_st,index,f_ch_time);			
		}
		if((!mid.empty()) && (tr.at(index) == mid.top()))
		{
			// set = 1;
			do_oio(cr,cr_stack,mid,sr_st,index,f_ch_time);
		}
		if(sr_st.empty() && cr_stack.size() != tr.size())
		{
			return ;
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

	while(cin >> sr)
	{
		cin >> tr;
		result.clear();
		f_ch_time = 0;
		f_ch = tr.at(0);
		int count = 1;
		while(count--)
		{
			stack<char> sr_st;
			for(double i = 0 ; i < sr.size() ; i++)
			{
				sr_st.push(sr.at(i));
			}
			stack<char> mid;
			stack<char> cur_st;
			string str = "";
			int index = 0;
			let_go = 0;
			do_opr(str,cur_st,mid,sr_st,index,f_ch_time);
			f_ch_time++;
		}


	}
	display(result);



}	



