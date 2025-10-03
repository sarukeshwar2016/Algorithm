"""The brute-force optimal approch is used to find the maximum element in the given array its time complexity is O(n^2)"""
a=eval(input("enter the array"))
for i in a:
  count=0
  for j in a:
    if i==j:
      count+=1
  if count>len(a)//2:
    print("the majority element is:",i)
    break
else:
    print("no majority elemnet")
