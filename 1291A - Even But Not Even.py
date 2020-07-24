for i in range(int(input())):
  numits = 0
  numdigs = int(input())
  number = input()
  sum_of_number = sum(map(int,number))
  while(sum_of_number%2==1 or int(number)%2==0):
    numits+=1
    if numits == numdigs:
      number = '-1'
      break
    number = number[:-1]
    sum_of_number = sum(map(int,number))
  if numdigs == 1:
    print("-1")
  else:
    print(number)