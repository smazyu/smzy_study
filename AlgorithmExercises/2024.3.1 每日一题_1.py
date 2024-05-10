'''
0<n,m<100,绝对值Ai <= 100,bi <= 100数组[4,5,6],b数组为,
后台程序会预先将a扩容为[4,5,6,0,0,0],b为[1,2,3,],m-3,n-3,传入到merge里面，
先完成merge函数
'''
def merge(A,B):
    c = A + B
    n = len(c)
    sorted = False
    while not sorted:
        sorted = True
        for index in range(n - 1):
            if c[index] > c[index + 1]:
                c[index], c[index + 1] = c[index + 1], c[index]
                sorted = False
    return c
# A_input = input('A: ')
# B_input = input('B: ')
# A = [int(x) for x in A_input.split(',')]
# B = [int(x) for x in B_input.split(',')]
def in_put(a):
    return [int(x) for x in a.replace('[', '').replace(']', '').replace(' ', '').split(',')]
A = in_put(input('A:'))
B = in_put(input('B:'))
c = merge(A,B)
print(c)