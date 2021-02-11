Sort_List = list(map(int,input().split()))
for j in range(len(Sort_List)):
    for i in range(0, len(Sort_List)-j-1):
        if(Sort_List[i] > Sort_List[i+1]):
            temp = Sort_List[i]
            Sort_List[i] = Sort_List[i+1]
            Sort_List[i+1] = temp
print(Sort_List)