from math import ceil, log2
from secrets import randbelow

def generate_bottles(n, k):
    bottles = list(False for _ in range(n))

    impure_bottles = set()
    while len(impure_bottles) != k:
        x = randbelow(n)
        bottles[x] = True
        impure_bottles.add(x)

    return bottles

def propose(n, m, k):
    b = ceil(log2(n))
    test_tubes = list(list(False for _ in range(n)) for _ in range(m))

    def binary_sum(of, equals):
        return bin(of).count('1') == equals

    groups = list(range(b + 1))
    assert len(groups) <= m, 'You made too many groupings!'

    group = dict((label, set()) for label in groups)
    for i in range(n):
        for j in range(b + 1):
            if binary_sum(of=i, equals=j):
                group[j].add(i)
    for index, value in enumerate(groups):
        for bottle in group[value]:
            test_tubes[index][bottle] = True

    return test_tubes

def machine(bottles, test_tubes):
    results = list()
    for test_tube in test_tubes:
        results.append(any(bottles[index] for index, sample in enumerate(test_tube) if sample))
    
    return results

def analyze(n, test_tubes, results):
    suspects = set(range(n))
    for index, result in enumerate(results):
        if not result and any(test_tubes[index]):
            suspects.difference_update(i for i in range(n) if test_tubes[index][i])
    
    print(f'{len(suspects)} were found.')
    print(f'\t{" ".join(map(str, suspects))}')

if __name__ == '__main__':
    k = 2
    m = 60

    n = int(1e3)

    bottles = generate_bottles(n, k)

    test_tubes = propose(n, m, k)

    results = machine(bottles, test_tubes)

    analyze(n, test_tubes, results)
