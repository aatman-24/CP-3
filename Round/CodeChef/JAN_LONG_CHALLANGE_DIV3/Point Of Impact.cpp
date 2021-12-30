#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;

/*

Logic is that -> 


find the initial pos on the side which is 
min_val = min(N-x,N-y).
new_x = x + min_val;
new_y = y + min_val;

if(x==y) then it is must (N,N);
else 
{
    1) on (bottom line (x-axis))  
    2) on (right side)
    3) on (up line) 
    4) on (right side)
}

so using module i just simultate process....

*/



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    ll N,M,x,y,new_x,new_y;
    int t; cin>>t;
    while(t--){
        
        cin>>N>>M>>x>>y;
      
        if(x == y) cout<<N<<' '<<N<< endl;
        else {
            int n = (M-1) % 4;
            ll min_val = min({N-x,N-y});
            new_x = min_val + x;
            new_y = min_val + y;
            // cout << new_x << ' ' << new_y << endl;
            n--;
            if(N-x < N-y) {
                for(int k = 0; (n > -1) && (k <= n); k++) {

                if(new_y == N) {
                    new_y = N - new_x; new_x = (ll)0;
                }
                else if (new_y == (ll)0) {

                    new_y = N - new_x; new_x = N;
                }
                else {

                    ll temp = new_x;
                    new_x = new_y;
                    new_y = temp;
                }
            }
            }
            else {
                for(int k = 0; (n > -1)&& (k <= n); k++) {

                    if(new_x == N) {
                        new_x = N - new_y; new_y = (ll)0;
                    }
                    else if (new_x == (ll)0) {

                        new_x = N - new_y; new_y = N;
                    }
                    else {

                        ll temp = new_x;
                        new_x = new_y;
                        new_y = temp;
                    }
                }

            }

            cout<< new_x <<' '<< new_y <<endl;
        }
       
    }
        

    return 0;
}

