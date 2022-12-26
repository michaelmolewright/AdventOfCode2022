lines= []
with open('data.txt') as f:
    lines = f.readlines()

last4 = []
for line in lines:
    if line[-1] == '\n':
        line = line[:-1] + ''
    count = 0
    for c in line:
        dupe = False
        last4.append(c)
        if (len(last4) > 14):
            last4 = last4[::-1]
            last4.pop()
            last4 = last4[::-1]
        if len(last4) == 14:
            for i in range(0,14):
                for j in range(0,14):
                    if i != j and last4[i] == last4[j]:
                        dupe = True
        else:
            dupe = True
        count += 1
        if dupe == False:
            print(dupe, "--- ", c, count)
            break
                        

     

