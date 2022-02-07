import os

from book import book

class service:
    def __init__(self):
        THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
        my_file = os.path.join(THIS_FOLDER, 'input.txt')
        f = open(my_file, 'r')
        book_List = f.readlines()
        self.book_List = []
        for i in range(0, len(book_List)):
            self.book_List.append(book(book_List[i].split()[0],
                                       book_List[i].split()[1],
                                       book_List[i].split()[2],
                                       book_List[i].split()[3],
                                       book_List[i].split()[4]))

    def getAll(self, i):
        try:
            return self.book_List[i].getBook()
        except:
            print("오류 발생")
            return ""

    def printAll(self):
        try:
            print("=====================================")
            for i in range(len(self.book_List)):
                print(i + 1, end=". ")
                print(" ".join(self.getAll(i)))
            print("=====================================")
        except:
            print("오류 발생")

    def save(self):
        try:
            new_Book_List = []
            for i in range(len(self.book_List)):
                new_Book_List.append(" ".join(self.book_List[i].getBook()))

            THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
            my_file = os.path.join(THIS_FOLDER, 'input.txt')
            f = open(my_file, 'w')
            f.write("\n".join(new_Book_List))
            f.close()
            print("=== 저장 완료 ===")
        except:
            print("오류 발생")

    def addBook(self):
        try:
            name = input("추가할 책 제목을 입력 하세요: ")
            year = input("추가할 책의 출판 연도를 입력 하세요: ")
            author = input("추가할 책 저자를 입력 하세요: ")
            company = input("추가할 책의 출판사 명을 입력 하세요: ")
            genre = input("추가할 책의 장르를 입력 하세요: ")
            self.book_List.append(book(name, year, author, company, genre))
            print("=== 추가 완료 ===")
        except:
            print("오류 발생")

    def delete(self):
        try:
            self.printAll()
            delete_select = int(input("삭제할 책의 번호를 입력 하세요: ")) - 1
            if 0 < delete_select < len(self.book_List):
                self.book_List.pop(delete_select)
                print("=== 삭제 완료 ===")
            else:
                print("오류 발생")
        except:
            print("오류 발생")

    def findBook(self):
        try:
            find_select = int(input("1. 종합 검색\n"
                                    "2. 도서 명으로 검색\n"
                                    "3. 저자 명으로 검색\n"
                                    "4. 출판 연도로 검색\n"
                                    "5. 출판사 명으로 검색\n"
                                    "6. 장르로 검색\n"
                                    "입력 : "))
            if find_select == 1:
                Comprehensive = input("검색어를 입력하세요: ")
                for i in range(len(self.book_List)):
                    now = " ".join(self.getAll(i))
                    if Comprehensive in now:
                        print(now)

            elif find_select == 2:
                find_name = input("검색할 도서 명을 입력 하세요: ")
                for i in range(len(self.book_List)):
                    if find_name in self.book_List[i].name:
                        print(" ".join(self.book_List[i].getBook()))

            elif find_select == 3:
                find_author = input("검색할 저자 명을 입력 하세요: ")
                for i in range(len(self.book_List)):
                    if find_author in self.book_List[i].author:
                        print(" ".join(self.book_List[i].getBook()))

            elif find_select == 4:
                find_year = input("검색할 출판 연도를 입력 하세요: ")
                for i in range(len(self.book_List)):
                    if find_year in self.book_List[i].year:
                        print(" ".join(self.book_List[i].getBook()))

            elif find_select == 5:
                find_company = input("검색할 출판사 명을 입력 하세요: ")
                for i in range(len(self.book_List)):
                    if find_company in self.book_List[i].company:
                        print(" ".join(self.book_List[i].getBook()))

            elif find_select == 6:
                find_genre = input("검색할 장르 명을 입력 하세요: ")
                for i in range(len(self.book_List)):
                    if find_genre in self.book_List[i].genre:
                        print(" ".join(self.book_List[i].getBook()))

            else:
                print("오류 발생")
        except:
            print("오류 발생")

    def update(self):
        try:
            self.printAll()
            update_select = int(input("수정할 책을 선택하세요 : ")) -1
            name = input("제목을 입력 하세요: ")
            year = input("출판 연도를 입력 하세요: ")
            author = input("저자를 입력 하세요: ")
            company = input("출판사 명을 입력 하세요: ")
            genre = input("장르를 입력 하세요: ")
            self.book_List[update_select] = book(name,year,author,company,genre)
            print("=== 수정 완료 ===")
        except:
            print("오류 발생")