n = 10**5
s = []
for i in range(n):
    s.append(chr((i % 26) + ord('a')))
print("".join(str(i) for i in s))
print("".join(str(i) for i in s))
print(n)
print(" ".join(str(i) for i in range(n)))