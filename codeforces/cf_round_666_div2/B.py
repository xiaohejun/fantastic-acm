def wrapper(func):
    def inner():
        return next(func)
    return inner
input = wrapper(open('in.txt'))

def powN(x, n):
    ret = 1
    while n:
        if (n & 1):
            ret *= x
        x *= x
        n >> 1
    return ret

n = int(input())
a = list(map(int, input().split(' ')))
a.sort()
x = a[-1]
z = int(1e5)
print(powN(2, z))
