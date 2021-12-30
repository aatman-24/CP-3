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

        // BufferedReader br = new BufferedReader( new FileReader("input.txt")); 
        // PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output1.txt"))); 
        // Scanner sc = new Scanner(br);


        ArrayList<ArrayList<BigInteger>> pascal = new ArrayList<ArrayList<BigInteger>>();
        ArrayList<BigInteger> firstOne = new ArrayList<BigInteger>(Arrays.asList(BigInteger.ZERO,BigInteger.ONE,BigInteger.ZERO));
        pascal.add(firstOne);
        BigInteger newNumber,LIMIT;
        LIMIT = BigInteger.TEN.pow(60);
        int i = 0;
        int set = 0;
        while(true)
        {
            ArrayList<BigInteger> tmp = new ArrayList<BigInteger>();
            tmp.add(BigInteger.ZERO);
            int k = 1;
            while(k < pascal.get(i).size())
            {
                newNumber = pascal.get(i).get(k).add(pascal.get(i).get(k-1));
                if(newNumber.compareTo(LIMIT) == 1 || newNumber.compareTo(LIMIT) == 0) set=1;
                tmp.add(newNumber); 
                k++;
            }
            tmp.add(BigInteger.ZERO);
            pascal.add(tmp);
            if(set==1){break;}
            i++;
        }

        int m = pascal.size();
        for(int s = 0 ; s < m; s++){
            int n = pascal.get(s).size();
            for(int j = 1 ; j < n-1 ; j++) {
                if(j == n - 2) System.out.print(pascal.get(s).get(j));
                else System.out.print(pascal.get(s).get(j) + " ");
            }
            System.out.println();
        }
        
        // out.flush();
    } 
} 




