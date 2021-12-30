import java.math.BigInteger;
import java.util.Scanner;


// 10551 Basic Remains


class Main{
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            int base = sc.nextInt();
            if(base == 0) break;

            BigInteger p = sc.nextBigInteger(base);
            BigInteger m = sc.nextBigInteger(base);

            BigInteger result = p.mod(m);
            System.out.println(result.toString(base));
        }
    }
}