lines= []
with open('data.txt') as f:
    lines = f.readlines()

result =[]

def getPrio(i):
    if ord(i) < 91:
        return ord(i) - 38
    else:
        return ord(i) - 96

for line in lines:
    dupe = ''
    half = int(len(line) / 2)

    if line[-1] == '\n':
        line = line[:-1] 
    for i in range(0, half):
        for j in range(half, len(line)):
            if line[i] == line[j]:
                dupe = line[i]
    
    result.append(dupe)


#part 2
newGroups = []
count = 0
group = []
for line in lines:
    
    if line[-1] == '\n':
        line = line[:-1] 

    group.append(line)
    if count % 3 == 2:
        newGroups.append(group)
        group = []

    count += 1

newDupe = ''
score = 0
for g in newGroups:
    print(g)
    for i in g[0]:
        for j in g[1]:
            for k in g[2]:
                if i == j and j == k and k == i:
                    newDupe = i

    score += getPrio(newDupe)


final_res = 0
for i in result:
    final_res += getPrio(i)

print(final_res)

print(  score)