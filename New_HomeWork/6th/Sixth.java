import java.util.*;
public class Sixth {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] Result = new int[N+1];
        for(int i = 0; i < N+1; i++){
            Result[i] = i;
        }
        for(int j = 3; j < N+1; j++){
            Result[j] = Result[j-1] + Result[j-2];
        }
        System.out.println(Result[N]);
        sc.close();
    }
    
}
