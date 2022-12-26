lines= []
with open('data.txt') as f:
    lines = f.readlines()

pairs = []
for line in lines:
    if line[-1] == '\n':
        line = line[:-1] 
    pair = line.split(",")
    new_pair = []
    for item in pair:      
        new_pair.append(item.split("-"))

    part1 = []
    part2 = []
    for i in range(0,len(new_pair)):
        for j in new_pair[i]:
            if i ==0:
                part1.append(int(j))
            else:
                part2.append(int(j))
    final = []
    final.append(part1)
    final.append(part2)
    pairs.append(final)

def inside(pair1, pair2):
    if pair1[0] <= pair2[1] and pair1[1] <= pair2[1] and pair1[0] >= pair2[0] and pair1[1] >= pair2[0]:
        return True
    if pair2[0] <= pair1[1] and pair2[1] <= pair1[1] and pair2[0] >= pair1[0] and pair2[1] >= pair1[0]:
        return True

def overlapPart2(pair1, pair2):
    if (pair1[0] <= pair2[1] and pair1[0] >= pair2[0]) or (pair1[1] <= pair2[1] and pair1[1] >= pair2[0]):
        return True
    if (pair2[0] <= pair1[1] and pair2[0] >= pair1[0]) or (pair2[1] <= pair1[1] and pair2[1] >= pair1[0]):
        return True

count = 0
for pair in pairs:
    if (overlapPart2(pair[0], pair[1])):
        count += 1
  
    print(pair[0], pair[1], "----", overlapPart2(pair[0], pair[1]))

print(count)