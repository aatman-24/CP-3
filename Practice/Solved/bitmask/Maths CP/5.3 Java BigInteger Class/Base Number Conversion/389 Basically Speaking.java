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

        String N;
        while(sc.hasNext()){
           N = sc.next();
           int base_from = sc.nextInt(); 
           int base_to = sc.nextInt();
          
            BigInteger Number = new BigInteger(N,base_from);

            String res = Number.toString(base_to).toUpperCase();
            if(res.length() > 7) res = "ERROR";
            System.out.printf("%7s\n",res);

        }
    }
}