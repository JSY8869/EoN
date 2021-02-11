'''
조건
*기차정보( 출발시간, 출발역, 도착역, 열차종류, 잔여석 수)
1. 메뉴는 다음과 같이 한다.
    1) 빠른시간 기차 검색 및 예매
      -입력 : 원하는시간, 출발역, 도착역, 열차종류 입력
      -출력 : 입력한 시간대와 가장 가까운 시간의 열차 정보 및 잔여석 수 출력
      -예매 여부 판단.
   2) 전체 기차 리스트 출력 및 
   3) 나의 예매 현황 출력 및 예매 취소
   4) 프로그램 종료
2. 전체 기차 리스트(총 기차정보) 입력은 TrainList.txt 파일로 프로그램이 시작할 때 로드한다.
3. 예매 완료 시 해당기차의 잔여석 수 차감할 것.
4. 잔여석 수가 0인 경우 매진으로 표기
5. 모든 메뉴의 뒤로가기 기능 포함할것.
6. 모든 에러의 대하여 예외처리 할 것.
7. 객체지향언어로 코딩할것.
'''
import os
import train_menu1
import train_menu3

class main:
    def __init__(self):
        self.menu1 = train_menu1.menu1()
        self.menu3 = train_menu3.menu3()

    def menu(self, TR_List, ticket_index):
        selected_menu = int(input("메뉴를 입력해수세요(1:예약, 2:기차정보, 3:예매현황 및 취소, 4:프로그램 종료): "))
        if selected_menu == 1:
            TR_List, ticket_index = self.menu1.input_time(TR_List, ticket_index)
            self.menu(TR_List, ticket_index)
        elif selected_menu == 2:
            for i in range(0, len(TR_List), 1):
                print(TR_List[i])
            self.menu(TR_List, ticket_index)
        elif selected_menu == 3:
            TR_List, ticket_index = self.menu3.check_menu(TR_List, ticket_index)
            self.menu(TR_List, ticket_index)
        elif selected_menu == 4:
            print("프로그램 종료")
        else:
            print("1~4 사이의 값을 입력하여 주세요.^^")
            self.menu(TR_List, ticket_index)
                    
if __name__ == '__main__':
    THIS_FOLDER = os.path.dirname(os.path.abspath(__file__))
    my_file = os.path.join(THIS_FOLDER, 'TrainList.txt')
    f = open(my_file,'r')
    trainList = f.readlines()
    ticket_index = []
    a = main()
    a.menu(trainList, ticket_index)