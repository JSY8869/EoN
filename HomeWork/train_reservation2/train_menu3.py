class menu3:
    def check_menu(self,TR_List, ticket_index):
        self.TR_List = TR_List
        self.ticket_index = ticket_index
        print("예매 현황을 출력합니다.")
        for i in range (0, len(self.ticket_index)):
            print(i + 1)
            print(self.TR_List[self.ticket_index[i]])
        self.cancel_ticket()
        return self.TR_List, self.ticket_index
    def cancel_ticket(self):
        select_cancel = int(input("취소할 표를 선택하여 주세요 (0) 선택 시 뒤로가기 : "))
        if select_cancel == 0:
            return (self.TR_List, self.ticket_index)
        else:
            try:
                if self.TR_List[self.ticket_index[select_cancel-1]].split()[5] != '매진':
                    if self.TR_List[self.ticket_index[select_cancel-1]].split()[5] == self.TR_List[self.ticket_index[select_cancel-1]].split()[0].split(':')[1]:
                        self.TR_List[self.ticket_index[select_cancel-1]] = self.TR_List[self.ticket_index[select_cancel-1]].replace(self.TR_List[self.ticket_index[select_cancel-1]].split()[5], str((int(self.TR_List[self.ticket_index[select_cancel-1]].split()[5]))+1))
                        self.TR_List[self.ticket_index[select_cancel-1]] = self.TR_List[self.ticket_index[select_cancel-1]].replace(self.TR_List[self.ticket_index[select_cancel-1]].split()[5], str((int(self.TR_List[self.ticket_index[select_cancel-1]].split()[5]))-1),1)
                        del (self.ticket_index[select_cancel-1])
                        print("취소 완료")
                    else:
                        self.TR_List[self.ticket_index[select_cancel-1]] = self.TR_List[self.ticket_index[select_cancel-1]].replace(self.TR_List[self.ticket_index[select_cancel-1]].split()[5], str((int(self.TR_List[self.ticket_index[select_cancel-1]].split()[5]))+1))
                        del (self.ticket_index[select_cancel-1])
                        print("취소 완료")
                else:
                    self.TR_List[self.ticket_index[select_cancel-1]] = self.TR_List[self.ticket_index[select_cancel-1]].replace(self.TR_List[self.ticket_index[select_cancel-1]].split()[5], str(1))
                    del (self.ticket_index[select_cancel-1])
                    print("취소 완료")
            except:
                print("오류 발생 다시 시도해주세요")
                self.check_menu(self.TR_List, self.ticket_index)