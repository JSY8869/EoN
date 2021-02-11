import java.util.*;
public class Second {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int Input_Number = sc.nextInt();
        System.out.println((Input_Number % 2 == 0) ? "짝수" : "홀수");
        sc.close();
    }
}
