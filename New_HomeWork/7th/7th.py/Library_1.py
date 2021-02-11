import os
class Library_x:   
    def delete_book(self, book_List):
        for i in range(0, len(book_List), 1):
            print(i)
            print(book_List[i])
        delete_num = int(input("삭제할 책의 번호를 고르세요(00 = 취소) : "))
        if delete_num == 00:
            print("취소")
            return book_List
        else:
            try:
                self.delete_b(book_List,delete_num)
            except:
                print("삭제 실패")
                self.delete_book(book_List)
            return book_List

    def delete_b(self,book_List,delete_num):
        book_List.pop(delete_num)
        print("삭제 완료")

    def find_book_name(self,matching_list):
        d_book_info = str(input("찾을 책의 정보를 입력하세요(아무 정보나 입력) : "))
        matching = self.find_book_book(d_book_info,matching_list)
        return matching

    def find_book_kind(self,book_List):
        d_book_info = str(input("찾을 책의 장르를 입력하세요 : "))
        matching = self.find_book_book(d_book_info,book_List)
        return matching

    def find_book_book(self, find_text, book_List):
        matching = []
        for s in book_List:
            if find_text in s:
                matching.append(s)
        if len(matching) == 0:
            print("검색 실패")
            return matching
        else:
            return matching
    
    def input_list(self,book_List):
        new_book_List = ' '.join(book_List)
        THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
        my_file = os.path.join(THIS_FOLDER, 'input.txt')
        d = open(my_file,'w')
        d.write(new_book_List)
        d.close()