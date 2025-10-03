a = str(input("Enter the string: "))#getting a input
l = 0
r = len(a) - 1
"""Two pointer techniques to check whether a given alphanumeric array is palindrome or not"""
while l < r:
    if not a[l].isalnum():#if it contains a alnum value it increment
        l += 1
        continue
    elif not a[r].isalnum():
        r -= 1
        continue
    elif a[l].lower() == a[r].lower():#converting to lower case to make sure the uppercase and lowercase letter to be evaluated
        l += 1
        r -= 1
    else:
        print("Not a palindrome")
        break
else:
    print("Palindrome")
