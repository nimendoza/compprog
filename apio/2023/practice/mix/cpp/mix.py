from collections import defaultdict
from copy import deepcopy
from itertools import combinations
from math import ceil, log2
from secrets import randbelow

def selective_xor(n, against, pad='x'):
    pairs = list()
    for x, y in zip(n, against):
        if y != pad:
            pairs.append((int(x), int(y)))

    return sum(a ^ b for a, b in pairs) == 1

def selective_and(n, against, pad='x'):
    pairs = list()
    for x, y in zip(n, against):
        if y != pad:
            pairs.append((int(x), int(y)))

    return sum(a == b for a, b in pairs) == len(pairs)

def generate_array(n):
    impure = list(False for _ in range(n))
    impure[randbelow(n)] = True
    impure[randbelow(n)] = True
    
    return impure

def padleft(string, length, pad):
    while len(string) < length:
        string = pad + string
    return string

def process(bottles, test_tubes):
    results = defaultdict(bool)
    for label, indices in test_tubes.items():
        if any(bottles[i] for i in indices):
            results[label] = True
    
    return results

if __name__ == '__main__':
    n = int(1e3)
    b = ceil(log2(n))

    pairs = sorted(combinations(range(b), 2))
    pairs.extend((byte, None) for byte in range(b + 1))
    againsts = dict()
    for x, y in pairs:
        if not y:
            againsts[(x, y)] = ''
            continue
        binary = list('x' for _ in range(b))
        binary[x] = binary[y] = '1'
        againsts[(x, y)] = ''.join(binary)
    
    buckets = defaultdict(set)
    for i in range(n):
        # for j in range(b + 1):
        #     if bin(i).count('1') == j:
        #         buckets[(j, None)].add(i)
        for pair in pairs:
            if selective_xor(padleft(bin(i)[2:], b, '0'), againsts[pair]):
                buckets[pair].add(i)
        for byte in range(b):
            if (i >> byte) & 1:
                buckets[(byte, None)].add(i)

    numbers = generate_array(n)
    impure = process(numbers, buckets)

    suspects = set(range(n))
    for label in pairs:
        if not impure[label]:
            suspects.difference_update(buckets[label])
    print(*suspects)
    for suspect in suspects:
        print(padleft(bin(suspect)[2:], b, '0'))
    print(len(suspects))

    for i, v in enumerate(numbers):
        if v:
            print(i, end=' ')
    print()

    print(len(buckets))