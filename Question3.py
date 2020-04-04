In=input
for n in range(int(In())):
    inp=int(input())
    q=[]
    s=[]
    for i in range(inp):
        s.append('C')
   
    for i in range(inp):
        li=list(map(int,input().split()))
        li.append(i)
        q.append(li)

    q=sorted(q)
    c,j,flag=0,0,0
    for i in range(0,inp):
        if(q[i][0]>=j):
            s[q[i][2]]='J'
            j=q[i][1]
            
        elif(q[i][0]>=c):
            s[q[i][2]]='C'
            c=q[i][1]
        else:
            flag=1
            break
    if(flag==1):
        print("Case #"+str(n+1)+": "+"IMPOSSIBLE")
    else:
        print("Case #" + str(n + 1) + ": " , ''.join(s))
