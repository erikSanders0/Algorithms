h = 'red'
word = 'purple is cool'
# 'red' -> 'e'
# 'purple is cool' -> 'u p e i  o l'

print(f'Indexing example: h[0] = {h[0]}')
print(f'Indexing example: h[1] = {h[1]}')

print('---- TEST 01 ----')

for i in range(1, len(h), 2):
    print(h[i])


# Start
index_or_number = 0

# End
while index_or_number >= len(h):
    print(index_or_number)
    # Increment
    index_or_number += 1 