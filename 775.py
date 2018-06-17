vertex=[False for _ in range(1001)]#紀錄這個點有沒有走過
ispath=[[False for a in range(1001)]for b in range(1001)]#紀錄無相圖a,b間有沒有路
sol=[]#紀錄答案
n=0#點的數目
flag=False
def dfs(tmp,sol):
    global flag
    global n
    if tmp==n+1:
        if ispath[sol[0]][sol[-1]]:
            for i in range(len(sol)):
                print(sol[i],end=" ")
            print(sol[0])
            flag=True
            return
    else:
        for i in range(1,n+1):
            if ispath[sol[-1]][i] and not vertex[i]:
                vertex[i]=True
                sol.append(i)
                dfs(tmp+1,sol)
                if flag:
                    return
                sol.pop()
                vertex[i] = False
while True:
    try:
        n=input()
    except EOFError:
        break
    n=int(n)
    while True:
        ab=str(input())
        if ab[0]=='%':
            break
        ispath[int(ab[0])][int(ab[2])]=True
        ispath[int(ab[2])][int(ab[0])]=True
    vertex[1]=True
    sol.append(1)
    dfs(2,sol)
    if not flag:
        print('N')
    flag=False
    sol.clear()
    for i in range(1001):
        vertex[i]=False
    for i in range(1001):
        for j in range(1001):
            ispath[i][j]=False
