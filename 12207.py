#RE
class ListNode:
    n=0
    next=None
    def __init__(self,num,node):
        self.n=num
        self.next=node
pc=[-1,-1]
flag=1
while True:
    pc=list(map(int, input().split(' ')))
    if pc[0]==0 and pc[1]==0:
        break
    print("Case {}:".format(flag))
    flag+=1
    tail=ListNode(pc[0],None)
    nexttail=tail
    for i in range(pc[0]-1,0,-1):
        tmp=ListNode(i,nexttail)
        nexttail=tmp
    head=nexttail
    for i in range(pc[1]):
        ne=list(input().split(' '))
        if ne[0]=='N':
            print(head.n)
            tail.next=head
            tail=tail.next
            head=head.next
            tail.next=None
        else:
            if head.n ==int(ne[1]):
                pass
            else:
                tmp=head
                while tmp.next.n!=int(ne[1]):
                    tmp=tmp.next
                originnext=tmp.next.next
                tmp.next.next=head
                head=tmp.next
                tmp.next=originnext