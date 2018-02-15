#理解錯題意
try:
    while True:
        s=str(input())
        for i in range(len(s)):
            if s[i]!='[' and s[i]!=']':
                print(s[i],end="")
        print()
except EOFError:
    pass