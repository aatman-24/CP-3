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


};





int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	

	int t; cin >> t;
	vector<pair<string,string>> frd_ships;
	int n_fship;
	string str1,str2;


	map<string,int> name_to_number;
	while(t--)
	{
		cin >> n_fship;
		for(int i = 0 ; i < n_fship ; i++)
		{
			cin >> str1 >> str2;
			frd_ships.push_back({str1,str2});
			if(name_to_number.find(str1) == name_to_number.end())
			{
				name_to_number[str1] = name_to_number.size();
			}
			if(name_to_number.find(str2) == name_to_number.end())
			{
				name_to_number[str2] = name_to_number.size();
			}

		}



		// for(auto i:name_to_number)
		// {
		// 	cout << i.first  << i.second << endl;
		// }

		int n = int(name_to_number.size());

		UnionFind a1 = UnionFind(n);

		for (int i = 0 ; i < n_fship ;i++)
		{
			int num1 = name_to_number[frd_ships[i].first] - 1;
			int num2 =  name_to_number[frd_ships[i].second] - 1;
			a1.unify(num1,num2);
			cout << a1.componetsSize(num1) << endl;

		}
		name_to_number.clear();
		frd_ships.clear();
		// cout << endl;
	}

	return 0;

}