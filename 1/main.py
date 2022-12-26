

lines= []
with open('data.txt') as f:
    lines = f.readlines()


elfs = []
elfTotal = 0
elfCount = 1
for line in lines:
    if line != '\n':
        elfTotal += int(line)
        
    else:
        elfs.append([elfTotal, elfCount])
        elfTotal = 0
        elfCount += 1

final_list =[]
for elf in elfs:
    final_list.append(elf[0])

final_list.sort()
print(final_list)
