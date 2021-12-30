import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;


// 10551 Basic Remains

class Main{
    
    public static int findBiggestBase(String a){
        int max_base = 2;
        for(int i = 0 ; i < a.length(); i++){
            if((int)a.charAt(i) >= 65){
                if((int)a.charAt(i) - 65 + 11 > max_base) max_base = (int)a.charAt(i) - 65 + 11;
            }
            else
            {
                if((int)a.charAt(i) - 48 + 1 > max_base) max_base = (int)a.charAt(i) - 48 + 1;
            }
        }
        return max_base;
    }

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        String N,M;
        while(sc.hasNext()){
           N = sc.next().trim();
           M = sc.next().trim();

           int i = findBiggestBase(N);
           int k = findBiggestBase(M);
           int j = k; 
           
           int set=0;
            for(; i <= 36; i++)
            {
                for(j = k; j <= 36; j++)
                { 
                    
                    String s = new BigInteger(N,i).toString();
                    String p = new BigInteger(M,j).toString();


                   if(s.equalsIgnoreCase(p)){
                        set = 1;
                        break;
                    }
                    
                }

                if(set == 1) break;
            }

            if(set == 1){
                System.out.println(N + " (base " + i + ") = " + M + " (base " + j + ")");
            }
            else System.out.println( N + " is not equal to "+ M +" in any base 2..36");


        }
    }
}