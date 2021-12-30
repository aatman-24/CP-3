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


class UnionFind
{
	private:
		int size,numComponets;
		vi id,sz;
	public:
		UnionFind(int size)
		{
			this -> size = size;
			numComponets = size;
			id.assign(size,0);
			sz.assign(size,1);
			for(int i=0; i < size ;i++) id[i] = i;
		}

		int find(int p)
		{
			int root = p;
			while(root != id[root]) root = id[root];

			while(p != root)
			{
				int nxt = id[p];
				id[p] = root;
				p = nxt;
			}
		
			return root;
		}

		bool connected(int p,int q) {return find(p) == find(q);}

		void unify(int p,int q)
		{
			if(connected(p,q)) return;
			int root1 = find(p);
			int root2 = find(q);

			if(sz[root2] < sz[root1])
			{
				sz[root1] += sz[root2];
				id[root2] = root1;
			}
			else 
			{
				sz[root2] += sz[root1];
				id[root1] = root2;
			}

			numComponets--;
		}


};





int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	string temp;
	char q_or_c;
	int num1,num2,n,pos,neg;

	int t; cin >> t;
	getline(cin,temp);
	while(t--)
	{
		cin >> n;
		getline(cin,temp);
		UnionFind a = UnionFind(n);
		pos = 0; neg = 0;
		while(getline(cin,temp))
		{
			if(temp.empty()) break;
            sscanf(temp.c_str(),"%c %d %d",&q_or_c,&num1,&num2);
			if(q_or_c == 'c')
			{
				a.unify(num1-1,num2-1);
			}
			else if(q_or_c == 'q')
			{
				if(a.connected(num1-1,num2-1)) pos++;
				else neg++;
			}
		}
		cout << pos << ',' << neg << endl;
		cout << endl;
	}

	return 0;

}