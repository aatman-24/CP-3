#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>
#include <climits>
#include <numeric>


#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
==============================> APPORACH <=============================================

TIME COMPLEXITY : 


*/

map<char,int> get_number = {{'V',0},{'U',1},{'C',2},{'D',3}};
int LSB = 7;
int BASE = 4;
int total;

void SUMMATION(vi num1, vi &num2)
{
    int carry = 0;
    for(int i = LSB;i > -1; i--)
    {
        total = (num2[i]+num1[i]+carry);
        num2[i] = (total) % 4;
        carry = total / 4;
    }
}

void LEFT_SHIFT(vi &num2)
{
    for(int i = 1; i <= LSB ; i++)
    {
        num2[i-1] = num2[i];
    }
    num2[LSB] = 0;
}

void RIGHT_SHIFT(vi &num2)
{
    for(int i = LSB-1; i > -1; i--)
    {
        num2[i+1] = num2[i];
    }
    num2[0] = 0;
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    string NUM1,NUM2,NUM3;
    vi num1,num2,num3;
    int n;
    double k;
    char OPREATION;

    cout << "COWCULATIONS OUTPUT" << endl;
    int test_case; cin >> test_case;
    while(test_case)
    {

        
        cin >> NUM1;
        cin >> NUM2;

        num1.assign(8,0);
        num2.assign(8,0);
        num3.assign(8,0);



        k = NUM1.size() - 1;
        for(double i = LSB; k > -1; i--)
        {
            num1[i]= get_number[NUM1[k]];
            k--;
        }

        k = NUM1.size() - 1;
        for(double i = LSB; k > -1; i--)
        {
            num2[i]= get_number[NUM2[k]];
            k--;
        }

        n = 3;
        while(n--)
        {
            cin >> OPREATION;
            if(OPREATION == 'A')
            {
                SUMMATION(num1,num2);
            }
            if(OPREATION == 'R')
            {
                RIGHT_SHIFT(num2);
            }
            if(OPREATION == 'L')
            {
                LEFT_SHIFT(num2);
            }
        }

        cin >> NUM3;
        k = NUM3.size() - 1;
        for(double i = LSB; k > -1; i--)
        {
            num3[i]= get_number[NUM3[k]];
            k--;
        }

        int flag = 0;
        for(double i = 0; i < 8;i++)
        {
            if(num2[i] != num3[i]) {flag = 1; break;}   
        }

        if(flag) cout << "NO" << endl;
        else cout << "YES" << endl;
        test_case--;
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}

