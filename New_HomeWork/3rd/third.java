import java.util.*;
public class third {
    public static void main(String[] args){
        int[] Input_List = new int[6];
        Scanner sc = new Scanner(System.in);
        Second temp = new Second();
        for(int i = 0; i < Input_List.length; i++){
            Input_List[i] = sc.nextInt();
        }
        int result = temp.Sum_Total(Input_List);
        System.out.println(result);
    }
    public int Sum_Total(int[] Input_List){
        int result = 0;
        for(int j = 0; j < Input_List.length; j++){
            result = result + Input_List[j];
        }
        return (result);
    }   
}