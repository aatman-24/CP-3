import java.math.BigInteger;
import java.util.Scanner;
import java.math.*;


/*
You ask, given  m+ni  how do you determine if it’s a Gaussian prime?

If both  m  and  n  are nonzero, then  m+ni  is a Gaussian prime if and only if  m^2+n^2  is an ordinary
prime.  For  2+3i,  for example,  22+32=13  which is prime, so  2+3i  is a Gaussian prime.

If exactly one of  m  and  n  is zero, then it’s a Gaussian prime if and only if the absolute value 
of the other is an ordinary prime and it's congruent to  3  modulo  4. 

Zero itself is not a Gaussian prime.

P congrunet 3(mod 4) menas that p mod 4 === 3 mod 4.

*/

class Main{
    


    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int t; t = sc.nextInt();
        BigInteger a,b;
        while(t-- > 0){
            a = sc.nextBigInteger(); b = sc.nextBigInteger();
           
            if(a.equals(BigInteger.ZERO) || b.equals(BigInteger.ZERO)){
               BigInteger c = a.abs().add(b.abs());
               
               if(c.isProbablePrime(20) && c.mod(BigInteger.valueOf(4)).equals(BigInteger.valueOf(3))){
                System.out.println("P");
               }
               else{
                System.out.println("C");
               }
            }
            else
            {
                BigInteger c = a.pow(2).add(b.pow(2));
                if(c.isProbablePrime(10)){
                    System.out.println("P");
                }
                else
                {
                    System.out.println("C");
                }
            }
        }

    // System.out.println(BigInteger.valueOf(3).isProbablePrime(10));

    }
}