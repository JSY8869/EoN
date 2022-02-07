# 배열 array를 2차원 배열 command의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구한다.

array = list(map(int,input ("array를 입력하세요 (쉼표로 구분) :").split(",")))
while not (1 <= len(array) <= 100) :
  array = list(map(int,input ("array 요소를 100개 이하로 입력하세요 (쉼표로 구분) :").split(",")))
for i in range (0,len(array)) :
  while (array[i] < 1 or 100 < array[i]) :
    array = list(map(int,input ("array 요소값을 100 이하로 입력하세요 (쉼표로 구분) :").split(",")))
# list의 요소 개수와 각 요소 값이 모두 1이상 100이하인 배열 array를 입력받음

q = int(input ("몇개의 [i,j,k]배열을 입력하시겠습니까? :"))
while not (1 <= q <= 50) :
  q = int (input ("[i,j,k]배열 개수를 다시 입력하세요 :"))
commands=[[None]*3 for i in range (q)]
for i in range (0,q) :
  c = list(map(int,input ("[i,j,k]를 입력하세요 (쉼표로 구분) :").split(",")))
  while (len(c) != 3) :
    c = ( input ("[i,j,k]를 다시 입력하세요 (쉼표로 구분) :").split(","))
  commands[i]=c
# list의 길이가 1이상 50이하, 각 요소의 길이가 3인 2차원 배열 commands를 입력받음


def solution (array, commands) :
  for i in range (len(commands)):
    x = array [int(commands[i][0])-1 : int(commands[i][1])]
    x.sort()
    answer = x[int(commands[i][2])-1]
    print (f"{array}를 {int(commands[i][0])}번째부터 {int(commands[i][1])}번째까지 자른 후 정렬합니다. {x}의 {int(commands[i][2])}번째 숫자는 {answer}입니다.")

solution(array,commands)
#array와 commands를 입력변수로 하는 solution함수, answer을 배열로하여 출력변수로 삼고자 하였으나 코드를 짜지 못함