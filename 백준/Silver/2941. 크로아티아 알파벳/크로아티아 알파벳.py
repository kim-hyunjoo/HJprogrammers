alpha = ["c=","c-","dz=", "d-", "lj", "nj", "s=", "z="]
str = input()
answer = 0
for ch in alpha:
  str = str.replace(ch, "*")
print(len(str))