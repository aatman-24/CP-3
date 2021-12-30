import java.math.BigInteger;
import java.util.Scanner;

/*
Apporach : Store all the prime until 10000 into the array and then sliding window. O(N).

*/


class Main{

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int a[] = new int[10001]; 
 
        BigInteger I  = BigInteger.ONE;

        int i = 0;
        while(I.nextProbablePrime().compareTo(BigInteger.valueOf(10001)) == -1)
        {
            a[i] = I.nextProbablePrime().intValue();
            I = I.nextProbablePrime();
            i++;
        }
        int N;
        int n = i;
        while(sc.hasNext())
        {
            N = sc.nextInt();
            if(N == 0) break;
            int lf = 0; 
            int rt = 0;
            int cur_sum = 0;
            int cnt = 0;
            while(lf < n && a[lf] <= 10000)
            {
                if(cur_sum < N)
                {
                    cur_sum += a[rt];
                    if(rt+1 < n)rt++;
                }
                else if(cur_sum == N)
                {
                    cnt++;
                    cur_sum += a[rt];
                    cur_sum -= a[lf]; 
                    if(rt+1 < n)rt++; 
                    lf++;                    
                }
                else{
                    cur_sum -= a[lf];
                    lf++;
                }
            }

            System.out.println(cnt);
        }

        }
}