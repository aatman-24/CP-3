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


class  Unionfind
{
	private:
		int size;
		int numComponets;
		

	public:
		vi id,sz;
		Unionfind(int size)
		{
			this->size = size;
			numComponets = size;
			id.assign(size,0);
			sz.assign(size,0);

			for(int i = 0 ;i < size;i++)
			{
				id[i] = i;
				sz[i] = 1;
			}
		}

		int find(int p)
		{

			// find the root of the p componet
			int root = p;
			while(root != id[root]) root = id[root];

			// Path compression 
			// Add the all the child to the root
			while(p != root)
			{
				int next = id[p];
				id[p] = root;
				p = next;
			}

			return root;
		}

		// Return whether or not the elements 'p' and
        // 'q' are in the same components/set.
		bool connected(int p,int q) {return find(p) == find(q);} 

		int componetsSize(int p) {return sz[find(p)];}

		int total_elements()  {return size;}

		int total_componets() {return numComponets;}

		int sizeofset(int p) {return sz[p];}

		void unify(int p,int q)
		{
			if(connected(p,q)) return;

			int root1 = find(p);
			int root2 = find(q);


			// Merge Smaller Componets into larger one
			if(sz[root1] < sz[root2])
			{
				sz[root2] += sz[root1];
				id[root1] = root2;
			}
			else
			{
				sz[root1] += sz[root2];
				id[root2] = root1;
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
	
	


	Unionfind a1 = Unionfind(5);
	a1.unify(2,3);
	a1.unify(2,4);
	a1.unify(0,1);
	a1.unify(0,4);
	// cout << a1.sizeofset(4) << endl;
	cout << a1.componetsSize(3) << endl;

	for (int i = 0 ; i < 5 ;i++)
	{
		cout << i << '|' ;
	}

	cout << endl ;

	for (int i = 0 ; i < 5 ;i++)
	{
		cout << a1.id[i] << '|' ;
	}
	cout << endl;

	for(int i = 0 ; i < 5 ;i++)
	{
		cout << a1.sz[i] << "|";
	}

	return 0;

}