import math
n=int(input())
for i in range(n):
    s=str(input())
    if math.sqrt(len(s))!=round(math.sqrt(len(s))):
        print("INVALID")
    else:
        interval=int(math.sqrt(len(s)))
        for j in range(0,interval):
            for k in range(j,len(s),interval):
                print(s[k],end="")
        print()