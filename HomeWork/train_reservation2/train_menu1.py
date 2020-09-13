class menu1:
    def input_time(self, tr_list, ticket_index):
        self.ticket_index = ticket_index
        self.trList = tr_list
        try:
            input_t, input_m = (str(input("원하는 시간대를 입력하세요(ex 09 00) : ")).split())
            input_time_temp = (int(input_t) * 60) + (int(input_m))
            input_departure = str(input("출발역을 입력하세요 : "))
            input_arrive = str(input("도착역을 입력하세요 : "))
            input_train = str(input("탑승을 원하시는 기차의 종류를 입력하세요 : "))
            input_train = input_train.upper()
            self.go_dongo(input_departure, input_arrive, input_train, input_t, input_m, input_time_temp)
            return(self.trList, self.ticket_index)
        except:
            print("형태를 맞추어 입력하여 주세요")
            self.input_time(self.trList, self.ticket_index)

    def go_dongo(self, input_departure, input_arrive, input_train, input_t, input_m, input_time_temp):
        print("{}시{}분 {} -> {} {}".format(input_t, input_m, input_departure, input_arrive, input_train))
        do_or_not = int(input("위의 입력하신 정보로 기차표 검색을 진행하시겠습니까? (예 : 1, 뒤로가기 : 2) : "))
        if do_or_not == 1:
            self.find_time(input_departure, input_arrive, input_train, input_time_temp)
        elif do_or_not == 2:
            print("처음 메뉴로 돌아갑니다.")
            return self.trList
        else:
            print("1 or 2를 입력하여 주세요.")
            self.go_dongo(input_departure, input_arrive, input_train, input_t, input_m, input_time_temp)

    def find_time(self, input_departure, input_arrive, input_train, input_time_temp):
        matching_time = []
        index_list = []
        downtime = []
        uptime = []
        for i in range (1, 21):
            if input_departure == str(self.trList[i]).split()[1] and input_arrive == str(self.trList[i]).split()[3] and input_train == str(self.trList[i]).split()[4]:  
                matching_time.append(self.trList[i].split()[0])
                index_list.append(self.trList.index(self.trList[i]))

        for s in range (0, len(matching_time)):
           matching_time[s] = (str(matching_time[s]).split(':'))
           matching_time[s] = int(matching_time[s][0])*60 + int(matching_time[s][1])

        for j in range(0,len(matching_time)):
            if matching_time[j] == int(input_time_temp):
                downtime.append(matching_time[j])
            elif matching_time[j] < int(input_time_temp):
                downtime.append(matching_time[j])
            elif matching_time[j] > int(input_time_temp):
                uptime.append(matching_time[j])
        try:
            down_time_ticket_index = index_list[matching_time.index(max(downtime))]
        except:
            down_time_ticket_index = ("없음")
        try:
            up_time_ticket_index = index_list[matching_time.index(min(uptime))]
        except:
            up_time_ticket_index = ("없음")
        self.reservation_ticket(down_time_ticket_index, up_time_ticket_index)

    def reservation_ticket(self, down_time_ticket_index, up_time_ticket_index):
        try:
            print(1)
            print(self.trList[down_time_ticket_index])
        except:
            print ("없음")
        try:
            print(2)
            print(self.trList[up_time_ticket_index])
        except:
            print("없음")
        selected_ticket = int(input("골라보시오 (다시 검색 = 3, 메뉴로 돌아가기 = 4) : "))
        try:
            if selected_ticket == 1:
                if self.trList[down_time_ticket_index].split()[5] != ("매진"):
                    if self.trList[down_time_ticket_index].split()[5] == self.trList[down_time_ticket_index].split()[0].split(':')[1]:
                        self.trList[down_time_ticket_index] = self.trList[down_time_ticket_index].replace(self.trList[down_time_ticket_index].split()[5], str((int(self.trList[down_time_ticket_index].split()[5]))-1))
                        self.trList[down_time_ticket_index] = self.trList[down_time_ticket_index].replace(self.trList[down_time_ticket_index].split()[5], str((int(self.trList[down_time_ticket_index].split()[5]))+1),1)
                        self.ticket_index.append(down_time_ticket_index)
                    else:
                        self.trList[down_time_ticket_index] = self.trList[down_time_ticket_index].replace(self.trList[down_time_ticket_index].split()[5], str((int(self.trList[down_time_ticket_index].split()[5]))-1))
                        self.ticket_index.append(down_time_ticket_index)
                    if int(self.trList[down_time_ticket_index].split()[5]) == 0:
                        self.trList[down_time_ticket_index] = self.trList[down_time_ticket_index].replace(self.trList[down_time_ticket_index].split()[5], '매진')
                        self.trList[down_time_ticket_index] = self.trList[down_time_ticket_index].replace(self.trList[down_time_ticket_index].split()[5], str(0),1)
                else:
                    print("매진이라 예약할 수 없습니다.")

            elif selected_ticket == 2:
                if self.trList[up_time_ticket_index].split()[5] != ("매진"):
                    if self.trList[up_time_ticket_index].split()[5] == self.trList[up_time_ticket_index].split()[1].split(':')[1]:
                        self.trList[up_time_ticket_index] = self.trList[up_time_ticket_index].replace((self.trList[up_time_ticket_index].split()[5]), str((int(self.trList[down_time_ticket_index].split()[5]))-1))
                        self.trList[up_time_ticket_index] = self.trList[up_time_ticket_index].replace((self.trList[up_time_ticket_index].split()[5]), str((int(self.trList[down_time_ticket_index].split()[5]))+1),1)
                        self.ticket_index.append(up_time_ticket_index)
                    else:
                        self.trList[up_time_ticket_index] = self.trList[up_time_ticket_index].replace((self.trList[up_time_ticket_index].split()[5]), str((int(self.trList[down_time_ticket_index].split()[5]))-1))
                        self.ticket_index.append(up_time_ticket_index)
                    if int(self.trList[up_time_ticket_index].split()[5]) == 0:
                        self.trList[up_time_ticket_index] = self.trList[up_time_ticket_index].replace(self.trList[up_time_ticket_index].split()[5], '매진')
                        self.trList[up_time_ticket_index] = self.trList[up_time_ticket_index].replace(self.trList[up_time_ticket_index].split()[5], str(0),1)
                else:
                    print("매진이라 예약할 수 없습니다.")

                        
            elif selected_ticket == 3:
                self.input_time(self.trList, self.ticket_index)
            elif selected_ticket == 4:
                print("메뉴로 돌아갑니다")
            else:
                print("예약 불가 다시 선택하여 주세요")
                self.reservation_ticket(down_time_ticket_index, up_time_ticket_index)
        except:
            print("오류 발생 다시 시도해주세요.")
            self.reservation_ticket(down_time_ticket_index, up_time_ticket_index)
            
