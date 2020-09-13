List_number = int(input("수를 입력하세요 : "))
data = [[0] * List_number for i in range(List_number)]  # 2차원 리스트
number = 0 # 입력되는 숫자
way_number = 1 # 방향 지시 +1일 때 오른쪽, 아래, -1일 때 왼쪽, 위
height_number = 0 # 세로 위치
width_number = -1 # 가로 위치
# 달팽이 배열에서 세로는 2번째 줄부터 입력됨
def snail_List(number,way_number,height_number,width_number,List_number): # 함수
    for p in range(1, List_number + 1): # 가로줄 입력
        number = number + 1
        width_number = width_number + way_number
        data[height_number][width_number] = number
    List_number = List_number - 1
    for p in range(1, List_number + 1): # 세로줄 입력
        number = number + 1
        height_number = height_number + way_number
        data[height_number][width_number] = number        
    way_number = way_number * -1 # 입력 방향 바꾸기
    if List_number == 0: # 더이상 입력할 공간이 없을 시 종료 및 프린트
        for height_number in range(len(data)):
            print(data[height_number])
        return 0
    snail_List(number,way_number,height_number,width_number,List_number) # 재귀!!
        
snail_List(number,way_number,height_number,width_number,List_number) # 함수 호출
