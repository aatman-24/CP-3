import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;
import java.util.*;

/* 

TIME COMPLEXITY O(5051): 

check on wikipedia:

 ->     n! / (a0! a1! a2! ... ak!)

APPORACH:
*/


class Main 
{ 
    public static void main(String[] args) throws IOException 
    { 

        Scanner sc = new Scanner(System.in);

    
        BigInteger[] fact = new BigInteger[5051];
        fact[0] = BigInteger.ONE;


        for(int i = 1; i < 5051; i++) {
            fact[i]  = fact[i-1].multiply(BigInteger.valueOf(i));
        }


        int n,k;
        while(sc.hasNextInt()) {
            n = sc.nextInt();
            k = sc.nextInt();
            BigInteger result = fact[n];
            for(int i = 0 ; i < k ; i++) {
                int p = sc.nextInt();
                result = result.divide(fact[p]);
            }

            System.out.println(result);

        }





    } 
} 




