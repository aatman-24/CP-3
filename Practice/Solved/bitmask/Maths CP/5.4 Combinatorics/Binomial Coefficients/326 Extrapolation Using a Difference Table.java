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
        Scanner sc = new Scanner(System.in);

        

        while(true) {
            int n = sc.nextInt();
            if(n == 0) break;
            
            ArrayList<Integer> arr = new ArrayList<Integer>();
            ArrayList<Integer> tempArr = new ArrayList<Integer>();
            
            int[] b = new int[n];
            for(int i = 0 ; i < n ; i++) arr.add(sc.nextInt());

            for(int i = 0; i < n; i++) {
                b[i] = arr.get(arr.size()-1);

                for(int j = 1; j < arr.size(); j++) {
                    int tmp = arr.get(j) - arr.get(j-1);
                    tempArr.add(tmp);
                }
                arr.clear();
                for(int l= 0 ; l < tempArr.size(); l++) arr.add(tempArr.get(l));
                tempArr.clear();

            }

            int k = sc.nextInt();
            if(n != 1) {
                for(int i = 0 ; i < k ; i++) {
                    for(int m = n-2; m > -1; m--) {
                        b[m] = b[m] + b[m+1];
                    }
                }
            }
            int var = n + k;
            System.out.println("Term " + var +  " of the sequence is " + b[0]);
        }        
        // out.flush();
    } 
} 




