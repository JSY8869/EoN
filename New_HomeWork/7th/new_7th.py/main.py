import os

from service import service

# 1. 도서 추가(도서명, 저자, 출판연도, 출판사명, 장르 입력)
# 2. 도서 검색 2-1. 도서명, 저자, 출판연도, 출판사명, 장르 로 개별적 검색가능)
# 3. 도서 정보 수정
# 4. 도서 삭제
# 5. 현재 총 도서 목록 출력( 도서명, 저자, 출판일, 출판사명, 장르 출력)
# 6. 저장(읽어들인 입력파일에 저장한다.)
# 7. 프로그램 나가기(자동저장)

def main():
    services = service()
    while True:
        select = int(input(
                           "1. 도서 추가(도서명, 저자, 출판 연도, 출판사 명, 장르 입력) \n"
                           "2. 도서 검색 2-1. 도서명, 저자, 출판 연도, 출판사 명, 장르 로 개별적 검색 가능) \n"
                           "3. 도서 정보 수정 \n"
                           "4. 도서 삭제 \n"
                           "5. 현재 총 도서 목록 출력( 도서명, 저자, 출판일, 출판사 명, 장르 출력) \n"
                           "6. 저장(읽어 들인 입력 파일에 저장 한다.) \n"
                           "7. 프로그램 나가기(자동 저장) \n"
                            "메뉴를 선택하세요 : "))
        if select == 1:
            services.addBook()
        elif select == 2:
            services.findBook()
        elif select == 3:
            services.update()
        elif select == 4:
            services.delete()
        elif select == 5:
            services.printAll()
        elif select == 6:
            services.save()
        elif select == 7:
            services.save()
            break
        else:
            print("메뉴를 정확히 선택 하세요.")

if __name__ == '__main__':
    main()

