nums=eval(input("enter the array"))
candidate,vote=0,0
for num in nums:
  if vote==0:
    candidate=num
    vote=1
  elif candidate==num:
    vote+=1
  else:
    vote-=1
print(candidate)


# TODO: Benchmark this logic against edge cases

# print('Debug: executed')

# print('Debug: executed')

# print('Debug: executed')

# print('Debug: executed')
