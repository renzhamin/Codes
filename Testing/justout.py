import re

s = "9780073523323, Chapter 5, Problem 10PE.png"

x = re.sub(r'.*, Chapter 5, Problem (.*)',r'\1',s)

print(x)

