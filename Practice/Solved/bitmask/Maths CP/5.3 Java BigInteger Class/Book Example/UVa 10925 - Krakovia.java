import java.math.BigInteger;
import java.util.Scanner;

/* UVa 10925 - Krakovia */

class Main{
    
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int items,person;
        int case_n = 1;
        while(true)
        {
            items = sc.nextInt();
            person = sc.nextInt();
            if(items == 0 && person == 0) break;

            BigInteger sum = BigInteger.ZERO;
            for(int i = 0; i < items; i++)
            {
                sum = sum.add(sc.nextBigInteger());
            }

            System.out.println("Bill #" + case_n +" costs " + sum +": each friend should pay " + sum.divide(BigInteger.valueOf(person)) + "\n" ); 

            case_n++;
        }
    }
}