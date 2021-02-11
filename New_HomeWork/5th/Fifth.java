import java.util.*;
public class Fifth{
    public static int[] array = {1, 5, 2, 6, 3, 7, 4};
    public static int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    public static int[] answer = new int[3];
    public static void main(String[] args){
        Fourth temp = new Fourth();
        Fourth.solution();
        for(int j = 0; j < 3; j++){
            System.out.print(answer[j] + " ");
        }
    }
    public static void solution() {
        for(int i =0; i < commands.length; i++) {
            int[] temp = Arrays.copyOfRange(array, commands[i][0]-1,commands[i][1]);
            Arrays.sort(temp);
            answer[i]=temp[commands[i][2]-1];
        }
    }
}
