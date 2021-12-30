#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
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

		int componetsSize(int p) {return sz[find(p)];}

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

		int maxSizeGroup()
		{
			int result = 0;

			for(int i = 0 ; i < size ; i++)
			{
				if(sz[i] > result) result = sz[i];
			}

			return result;
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
	
	int n,m,size_of_group,member;


	while(cin >> n >> m,(n || m))
	{
				// if((n == 0) && (m == 0)) break;
		UnionFind a1 = UnionFind(n);
		for (int i = 0 ; i < m ; i++)
		{
			cin >> size_of_group;
			if(size_of_group)
			{
				int first_member ;
				cin >> first_member;
				for(int k = 0 ; k < size_of_group - 1; k++)
				{
					cin >> member;
					a1.unify(first_member,member);
				}
			}
			
		}

		cout << a1.componetsSize(0) << endl;
		// break;
	}




	return 0;

}