import sys

def input():
    return sys.stdin.readline().rstrip()

def print(*args, sep=' '):
    sys.stdout.write(sep.join([*args, '\n']))

print('a', 'b', 'c')