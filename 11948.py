n=int(input())
cur_pos=-1
def dfs(string,width,x,y,graph):
    global cur_pos
    cur_pos+=1
    if string[cur_pos]=='*':
        dfs(string, width // 2, x, y,graph)
        dfs(string, width // 2, x+width//2, y,graph)
        dfs(string, width // 2, x, y+width//2, graph)
        dfs(string, width // 2, x + width // 2, y+width//2, graph)
    elif string[cur_pos]=='0':
        for i in range(y,y+width):
            for j in range(x,x+width):
                graph[i][j]=True
def powoftwo(num):
    if num>1 and num%2==0:
        return powoftwo(num/2)
    elif num>1 and num%2==1:
        return False
    else:
        return True
for i in range(n):
    tmp=input().split(' ')
    length=int(tmp[0])
    if length==0:
        continue
    if length<0 or not powoftwo(length):
        print("Invalid length")
        continue
    string=str(tmp[1])
    graph=[[False for a in range(length+1)]for b in range(length+1)]
    finalans=[]
    dfs(string,length,1,1,graph)
    for y in range(1,length+1):
        ans=[]
        for x in range(1,length+1):
            if not graph[y][x]:
                if len(ans)==3:
                    ans[1]=x
                elif len(ans)==2:
                    ans[1]=x
                    ans.append(y)
                else:
                    ans=[x,y]
            else:
                if ans:
                    finalans.append(list(ans))
                    ans.clear()
        if ans:
            finalans.append(list(ans))
    cur_pos-=cur_pos
    cur_pos-=1
    for l in range(len(finalans)):
        if len(finalans[l])==3:
            print("({}-{},{})".format(finalans[l][0],finalans[l][1],finalans[l][2]),end="")
        else:
            print("({},{})".format(finalans[l][0], finalans[l][1]),end="")
        if l < len(finalans)-1:
            print(",",end="")
    if i <n-1:
        print()
