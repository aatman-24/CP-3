import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
import java.util.*;

/* 

TIME COMPLEXITY: 

APPORACH:
*/


class Main 
{ 
    public static void main(String[] args) throws IOException 
    { 

        Scanner sc = new Scanner(System.in);

        BigInteger[] fact = new BigInteger[61];
        fact[0] = BigInteger.valueOf(1);

        for(int i = 1; i <= 60; i++) {
            fact[i] = fact[i-1].multiply(BigInteger.valueOf(i));
        }
               
        int n,k;
        int case_n = 1;
        while(sc.hasNextInt()) {
            n = sc.nextInt(); 
            if(n == 0) break;
            k = sc.nextInt();
            int[] arr = new int[n+1];
            for(int i = 0; i <= n ; i++) arr[i] = 0;
            for(int i = 0; i < n ; i++) {
                int p = sc.nextInt();
                arr[p] = 1;
            }

            int unique = 0;
            for(int i = 0 ; i <= n ; i++) {
                unique += arr[i];
            }

            BigInteger result = fact[unique];

            out.printf("Case %d:\n",case_n);
            for(int i = 0 ; i< k ; i++) {
                int p = sc.nextInt();
                out.println(result.divide(fact[p]).divide(fact[unique-p]));
            }
            case_n++;
        }


    } 
} 




