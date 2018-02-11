try:
    while True:
        nm=list(map(int,input().split(' ')))
        num=list(map(int,input().split(' ')))
        dic={}
        for i in range(nm[0]):
            if num[i] in dic:
                dic[num[i]].append(i+1)
            else:
                dic[num[i]]=[i+1]
        for j in range(nm[1]):
            tmp=list(map(int,input().split(' ')))
            haveans=False
            if len(dic[tmp[1]])>=tmp[0]:
                print(dic[tmp[1]][tmp[0]-1])
            else:
                print('0')
except EOFError:
    pass

