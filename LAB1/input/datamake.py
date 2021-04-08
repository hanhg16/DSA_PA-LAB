import sys

f=open('input.txt','a')
sys.stdout = f
sys.stdder = f

n = 1024
m = 0

for _ in range(n//2):
    print('A',end='')
    print('B',end='')
for _ in range(n//2):
    print('CC',end='')
    print('DD',end='')
print('CCEF',end='')

print('')
print(m)

for _ in range(m//2):
    print('0 B')
    print('0 A')

f.close()