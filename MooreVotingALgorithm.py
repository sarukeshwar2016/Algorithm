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
