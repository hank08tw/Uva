try:
    #space:o(min(n,m)),time:o(n*m)
    while True:
        s1=str(input())
        s2=str(input())
        array=[0 for i in range(len(s2)+1)]
        for i in range(1,len(s1)+1):
            pre=0
            for j in range(1,len(s2)+1):
                oldpre=array[j]
                if s1[i-1]==s2[j-1]:
                    array[j]=pre+1
                elif array[j-1]>=array[j]:
                    array[j]=array[j-1]
                pre=oldpre
        print(array[len(s2)])
except EOFError:
    pass