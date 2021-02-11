def Sum_Total(Input_List):
    result = 0
    for i in Input_List:
        result += i
    return result
result = Sum_Total(Input_List = list(map(int,input().split())))
print(result)