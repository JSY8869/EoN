package Seventh_java;
import java.util.*;
public class menu {
    public menu(){
        System.out.println("프로그램 시작");
    }
    public void Select_Menu(){
        Scanner sc = new Scanner(System.in, "UTF8");
        int Selected_menu = -1;
        action data = new action();
        main_while : while(true){
            System.out.println("메뉴를 선택하세요");
            System.out.println("1. 도서 추가(도서명, 저자, 출판연도, 출판사명, 장르 입력)");
            System.out.println("2. 도서 검색");
            System.out.println("3. 도서 정보 수정");
            System.out.println("4. 도서 삭제");
            System.out.println("5. 현재 총 도서 목록 출력");
            System.out.println("6. 저장");
            System.out.println("7. 프로그램 나가기(자동 저장)");
            System.out.print("입력 : ");
            Selected_menu = sc.nextInt();
            switch(Selected_menu){
                case 0:
                    System.out.println("종료");
                    break main_while;
                case 1:
                    data.add_book();       // 인코딩 문제 발생
                    continue;
                case 2:
                    data.find_book();
                    continue;
                case 3:
                    data.revise_book();
                    continue;
                case 4:
                    data.delete_book();      // 구현 완료
                    continue;
                case 5:
                    data.show_book();      // 구현 완료
                    continue;
                case 6:
                    data.save_book();
                    continue;
                case 7:
                    System.out.println("프로그램 종료");
                    data.save_book();
                    break main_while;
                default:
                    System.out.println("0 ~ 7을 입력하여 주세요.");
            }
        }
        sc.close();
    }
}
