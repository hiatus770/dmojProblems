i = input() 
i = i.replace("+ ", "", -1) 
i = i.replace("(", "", -1) 
i = i.replace(")", "", -1) 
num = i.split(" ") 
s = 0
for z in num:
    s = s + int(z)
print(s)            