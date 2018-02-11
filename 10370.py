n=int(input())
for i in range(n):
    tmp=list(map(int,input().split(' ')))
    #print(tmp)
    avg=0
    for j in range(1,len(tmp)):
        avg+=tmp[j]
    avg=avg/(len(tmp)-1)
    #print(avg)

    ans=0
    for j in range(1,len(tmp)):
        if tmp[j]>int(avg):
            ans+=1
    #print(ans)
    finalans=("%.3f"%(ans*100/(len(tmp)-1)))
    print("{}%".format(finalans))
