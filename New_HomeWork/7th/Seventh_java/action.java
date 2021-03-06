package Seventh_java;
import java.io.*;
import java.util.*;

class action{
    Scanner sc = new Scanner(System.in, "UTF8");
    public static ArrayList<DB> Library = new ArrayList<DB>();
    static int Len = 0;
    // 파일 불러오기
    public action(){
        File file = new File("New_HomeWork/7th/Seventh_java/input.txt");
        try {
            BufferedReader inFiles
            = new BufferedReader(new InputStreamReader(new FileInputStream(file.getAbsolutePath()), "UTF8"));
            String line = "";
            String[] line_temp = {};
            int tt = 0;
            while((line = inFiles.readLine()) != null) {
                if(line.trim().length() > 0) {
                    line_temp = line.split(" ");
                    Library.add(new DB(line_temp[0], line_temp[1], line_temp[2], line_temp[3], line_temp[4]));
                    tt += 1;
                }
            }
            Len = tt;
                inFiles.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
    }
    // menu 1
    public void add_book(){
        System.out.print("도서명 : ");
        String new_title = sc.nextLine();
        System.out.print("저자 : ");
        String new_author = sc.nextLine();
        System.out.print("출판연도 : ");
        String new_year = sc.nextLine();
        System.out.print("출판사명 : ");
        String new_company = sc.nextLine();
        System.out.print("장르 : ");
        String new_genre = sc.nextLine();
        Library.add(new DB(new_title, new_author, new_year, new_company, new_genre));
        Len += 1;
        System.out.println("add_book");
    }
    public void find_book(){
        String find_name = "";
        System.out.println("1. 제목으로 찾기" + "\n" + "2. 저자로 찾기" + "\n" + "3. 출판연도로 찾기" + "\n" + "4. 출판사로 찾기" + "\n" + "5. 장르로 찾기");
        System.out.print("메뉴를 선택하세요 : ");
        int Selected_Menu = sc.nextInt();
        System.out.println(Selected_Menu);
        sc.nextLine();
        switch(Selected_Menu){
            case 0:
                System.out.println("종료");
                break;
            case 1:
                System.out.print("찾을 제목을 입력하세요 : ");
                find_name = sc.nextLine();
                for(int i = 0; i < Len; i++){
                    String title = Library.get(i).getTitle();
                    if(title.equals(find_name)){
                        Library.get(i).show();
                    }
                }
                break;
            case 2:
                System.out.print("찾을 저자를 입력하세요 : ");
                find_name = sc.nextLine();
                for(int i = 0; i < Len; i++){
                    String title = Library.get(i).getAuthor();
                    if(title.equals(find_name)){
                        Library.get(i).show();
                    }
                }
                break;
            case 3:
                System.out.print("찾을 출판연도 입력하세요 : ");
                find_name = sc.nextLine();
                for(int i = 0; i < Len; i++){
                    String title = Library.get(i).getYear();
                    if(title.equals(find_name)){
                        Library.get(i).show();
                    }
                }
                break;
            case 4:
                System.out.print("찾을 출판사를 입력하세요 : ");
                find_name = sc.nextLine();
                for(int i = 0; i < Len; i++){
                    String title = Library.get(i).getCompany();
                    if(title.equals(find_name)){
                        Library.get(i).show();
                    }
                }
                break;
            case 5:
                System.out.print("찾을 장르를 입력하세요 : ");
                find_name = sc.nextLine();
                for(int i = 0; i < Len; i++){
                    String title = Library.get(i).getGenre();
                    if(title.equals(find_name)){
                        Library.get(i).show();
                    }
                }
                break;
            default:
                System.out.println("오류 발생");
                break;
        }
    }
    public void revise_book(){
        show_book();
        System.out.print("수정할 책을 고르세요 : ");
        int revise_number = sc.nextInt();
        sc.nextLine();
        System.out.print("도서명 : ");
        String new_title = sc.nextLine();
        System.out.print("저자 : ");
        String new_author = sc.nextLine();
        System.out.print("출판연도 : ");
        String new_year = sc.nextLine();
        System.out.print("출판사명 : ");
        String new_company = sc.nextLine();
        System.out.print("장르 : ");
        String new_genre = sc.nextLine();
        Library.get(revise_number).setter(new_title, new_author, new_year, new_company, new_genre);
    }
    public void delete_book(){
        show_book();
        System.out.println("삭제할 책의 번호를 입력하세요 : ");
        int delete_number = sc.nextInt();
        Library.remove(delete_number);
        Len -= 1;
        System.out.println("delete_book");
    }
    public void show_book(){
        for(int i = 0; i < Len; i++){
            System.out.print(i + " ");
            Library.get(i).show();
        }
    }
    public void save_book(){
        File file = new File("New_HomeWork/7th/Seventh_java/input.txt");
        String jump2 = " ";
        byte[] jump = jump2.getBytes();
        String br2 = "\r\n";
        byte[] br = br2.getBytes();
            try {
                FileOutputStream outputStream = new FileOutputStream(file);
                for(int i = 0; i < Len; i++){
                    String Title = Library.get(i).getTitle();
                    String Author = Library.get(i).getAuthor();
                    String Year = Library.get(i).getYear();
                    String Company = Library.get(i).getCompany();
                    String Genre = Library.get(i).getGenre();
                    byte[] bytes = Title.getBytes();
                    byte[] bytes2 = Author.getBytes();
                    byte[] bytes3 = Year.getBytes();
                    byte[] bytes4 = Company.getBytes();
                    byte[] bytes5 = Genre.getBytes();
                    outputStream.write(bytes);
                    outputStream.write(jump);
                    outputStream.write(bytes2);
                    outputStream.write(jump);
                    outputStream.write(bytes3);
                    outputStream.write(jump);
                    outputStream.write(bytes4);
                    outputStream.write(jump);
                    outputStream.write(bytes5);
                    outputStream.write(br);
                }
            outputStream.close();
            System.out.println("저장 완료");
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}