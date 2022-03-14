# 버전1
input_list = list(map(int,input().split(",")))
for i in range(1,len(input_list)): input_list[i] += input_list[i-1]
print(input_list[-1])

# 버전2
sum = 0
for value in list(map(int,input().split(","))):
    sum += value
print(sum)


# sum 사용 버전
print(sum(list(map(int,input().split(",")))))