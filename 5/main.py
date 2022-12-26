lines= []
with open('data.txt') as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    if line == '\n':
        line = "-"
    elif line[-1] == '\n':
        line = line[:-1] + ' ' 
    new_lines.append(line)

step = 4
towers = []
for line in new_lines:
    if line == "-":
        break
    line_arr = []
    lineCopy = line
    while lineCopy:
        line_arr.append(lineCopy[:step].replace(" ", "").replace("[", "").replace("]", ""))
        lineCopy = lineCopy[step:]
    towers.append(line_arr)

towers = towers[::-1]

towers_dict = {}
for i in range(0,len(towers)):
    if i == 0:
        for key in towers[i]:
            towers_dict[key] = []
    else:
        for j in range(0,len(towers[i])):
            if(towers[i][j] != ''):
                towers_dict[towers[0][j]].append(towers[i][j])

start = False
for line in new_lines:
    instructions = []
    if start:
        split = line.split(" ")
        instructions.append(int(split[1]))
        instructions.append(split[3])
        instructions.append(split[5])
        temp_arr = []
        for i in range(0, int(split[1])):
            temp_arr.append(towers_dict[split[3]].pop())
        for i in temp_arr[::-1]:
            towers_dict[split[5]].append(i)



    if line == "-":
        start = True


print(towers_dict)
