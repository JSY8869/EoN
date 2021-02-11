import java.util.*;
class Bubble_sort{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int[] Sort_List = new int[6];
        for(int k = 0; k < Sort_List.length; k++){
            Sort_List[k] = sc.nextInt();
        }
		int temp;
		for(int i = 0 ; i < Sort_List.length ; i ++) {
			for(int j = 0 ; j < Sort_List.length -i -1; j ++) {
				if(Sort_List[j]>Sort_List[j+1]) {
					temp = Sort_List[j];
					Sort_List[j] = Sort_List[j+1];
					Sort_List[j+1] = temp;
				}
			}
		}
		for(int i = 0 ; i < Sort_List.length ; i ++) {
			System.out.print(Sort_List[i] + " ");
		}
		sc.close();
    }
}