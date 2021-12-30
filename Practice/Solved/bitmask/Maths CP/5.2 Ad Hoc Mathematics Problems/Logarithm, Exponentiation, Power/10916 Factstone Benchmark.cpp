#include <bits/stdc++.h>
#include <iostream>
#define ll long long

using namespace std;


typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef map<char,int> mci;
typedef vector<int> vi;
typedef vector<vi> vvi;

/*
#Explanation : We are given Year and We have to identify the word_size use by the processer 
on that Year then Find the largest N such that We can Fit N! on that word_size.

Hit : We can Fit the (2^K - 1) Number onto the Kth bit processer.

suppose, 
for the Year = 1960 -> word_size = 4 -> MAX_number_fit = 2^4 - 1 -> 15. < (4!) -> answer = 3
for the Year = 1981 (1980 is Latest) -> word_size = 16 -> MAX_number_fit = 2^16 - 1 -> 65535. < (9!) -> answer = 8

1960 1970 1980 1990 2000 2010 2020 2030.........2060
4    8     16   32    64   128 ....

geometric sereis = 4(1,2,4,8,16...) where a = 1, r = 2

so we get ar^n/r-1 -> (1)(2)^n/2-1 -> 2^n.

so nth term = 2^2 * 2^n -> 2^(n+2)

which give us the word_size...

But How you can find the n....like for,
1960 - 1969 -> 1.
1970 - 1979 -> 2.
1980 - 1989 -> 3.

so n = floor(YEAR - 1960/10);

so we can write the last equation is for word_size = pow(2,2+n);

Now we can find the ans such that,
while((i!) < pow(2,word_size)) i = 1 to 32;

Is it okay? -> NO No No NO.

for 2160, n -> 20
word_size = 2 ^ 22 -> 4194304 (MAX_Word_Size)
Max_LIMIT = 2^4194304 (which is too large and not possible brute force Here)
How you can apply brute force for the 2^4194304 This Number? 


Then Then Then ?

But we know that we have to find largest n which satisife below equation,


-> n! < pow(2,word_size) 

-> n! < 2^word_size (This is not possible right 2 ^ word_size)

-> log2(n!) < word_size (But this is possible word_size which is max 2^22)

-> log2(n * (n-1) * (n-2) * (n-3) ... * log(1))  < word_size

-> log2(1) + log2(2) + log2(3) + ..... log2(n) < word_size (if n! < 2^K than we reach until n otherwise not.)


  log2(1) + log2(2) + log2(3) + ..... log2(n) < word_size

  So we calculate for all the 1960-2160 and store in the array.


 check on the code..

 And when we got the input we get the index of it using same formula (YEAR - 1960)/10 which give
 index location.

*/




int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif


    int k;
    unsigned int word_size;
    vi arr;

    // calculate the word_size of all year. 
    for(int i = 1960; i <= 2160; )
    {
        k = (i - 1960)/10;
        word_size = pow(2,k+2);
        arr.push_back(word_size);
        i += 10;
    }

    int size = arr.size();
    vi result(size);  

    // calculate n! for all word_size. log2(1) + log2(2) + log2(3) + ..... log2(n) < word_size
    k = 0;
    double sum_of_log = 0;
    for(int i = 1; k <= size;)
    {
        while((int)(sum_of_log + log2(i)) < arr[k]) {i++; sum_of_log += log2(i);}
        result[k] = i; k++;
    }

    int YEAR;
    while(cin >> YEAR)
    {
        if(YEAR == 0) break;

        int index = (YEAR - 1960)/10;
        cout << result[index] << endl;
    }


    return 0;
}

