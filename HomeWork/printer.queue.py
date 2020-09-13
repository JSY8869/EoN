def printer_queue(the_num, num, priority):
    time = 0
    plist = []
    for i in range(0, the_num):
        plist.append(i)

    while True:
        while priority[0] < max(priority):  # 우선순위 높은 순으로 정렬
            priority.append(priority.pop(0))

            plist.append(plist.pop(0))

        time = time + 1

        if plist[0] == num:  # 구할 작업 번호에 도달 시 while문 종료
            break

        priority.pop(0)  # 프린트한 값 제거
        plist.pop(0)

    return time


n = int(input("작업 수 : "))
m = int(input("작업 번호 : "))
input_priority = list(map(int, input("작업 우선순위 : ").split()))

print(printer_queue(n, m, input_priority), "분")