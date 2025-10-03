n=int(input("enter the number to check the power"))
if n==1:
   return True
if n<=0:
   return False
for i in range(31):
        if pow(3,i)==n://4,2 any power
           return True
  return False
  
