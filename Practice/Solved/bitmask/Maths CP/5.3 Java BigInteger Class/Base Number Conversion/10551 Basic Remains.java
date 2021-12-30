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

        // String N;
        while(sc.hasNext()){
           int N = sc.nextInt();
           if(N == 0) break;
           BigInteger a = sc.nextBigInteger(N);
           BigInteger b = sc.nextBigInteger(N);
           BigInteger c =  a.mod(b);
           System.out.println(c.toString(N));

        }
    }
}