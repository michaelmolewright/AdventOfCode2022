lines= []
with open('data.txt') as f:
    lines = f.readlines()

point_lookup = {
    'X':1,
    'Y':2,
    'Z':3,
    'A':1,
    'B':2,
    'C':3
}

char_lookup = {
    'X':'A',
    'Y':'B',
    'Z':'C'
}

loss_lookup = {
    'A':'C',
    'B':'A',
    'C':'B'
}

win_lookup = {
    'A':'B',
    'B':'C',
    'C':'A'
}


def result(elf, me):
    if elf == char_lookup[me]:
        return 3 + point_lookup[me]
    
    if elf == 'A':
        if me == 'Y':
            return 6 + point_lookup[me]
        else:
            return 0 + point_lookup[me]

    if elf == 'B':
        if me == 'Z':
            return 6 + point_lookup[me]
        else:
            return 0 + point_lookup[me]

    if elf == 'C':
        if me == 'X':
            return 6 + point_lookup[me]
        else:
            return 0 + point_lookup[me]

def resultpart2(elf, me):
    if me == 'X':
        return 0 + point_lookup[loss_lookup[elf]]
    if me == 'Y':
        return 3 + point_lookup[elf]
    if me == 'Z':
        return 6 + point_lookup[win_lookup[elf]]


final_result = 0
for line in lines:
    chars = line.split(" ")
    if(len(chars[1]) > 1):
        chars[1] = chars[1][:-1]
    print(chars)
    final_result += resultpart2(chars[0], chars[1])

print(final_result)