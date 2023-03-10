n, q = input().split() 

s = ""

def rm(a, b):
    global s
    err = 0
    for i  in range (a, b+1): 
        s = s[0 : i-err : ] + s[i-err + 1 : :] 
        err = err + 1

for i in range(int(n)):
    s = s + str(i+1) 

for i in range(int(q)):
    a, b, c = input().split() 

    ind1 = s.find(a)
    ind2 = s.find(b)
    if c != "0":
        ind3 = s.find(c)
    else:
        ind3 = 0


    newL = s[ind1:ind2+1]
    print(s)
    rm(ind1, ind2)
    s = s[0:ind3+1] + newL + s[ind3:len(s)-1]


    print("\n", s, "\n", newL)

# 6 3
# 4 5 1
# 5 6 0
# 2 2 3

