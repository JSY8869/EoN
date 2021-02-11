N = int(input())
Result = [x for x in range(N+1)]
for i in range(3,N+1):
    Result[i] = Result[i-1] + Result[i-2]
print(Result[N])