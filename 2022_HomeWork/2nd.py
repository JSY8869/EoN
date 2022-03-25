input_value = list(map(int,input().split()))
for now in range(len(input_value)):
    for next in range(now,len(input_value)):
        if(input_value[now] > input_value[next]):
            input_value[now], input_value[next] = input_value[next], input_value[now]
print(input_value)