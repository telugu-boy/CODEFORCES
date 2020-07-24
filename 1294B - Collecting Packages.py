def increasingcheck(coords):
  increasingcheck = list(zip(*coords))
  for i in increasingcheck:
    for j in range(len(i)-1):
      if(i[j]>i[j+1]):
        return False
  return True
 
def getpaths(coords):
  movement = ""
  coord_cur = [0,0]
  for coord in coords:
    movementright = coord[0] - coord_cur[0]
    movementup = coord[1] - coord_cur[1]
    movement += "R"*movementright
    movement += "U"*movementup
    coord_cur = coord
  return movement
 
for _ in range(int(input())):
  coords = []
  for j in range(int(input())):
    coords.append(input())
  coords = sorted([list(map(int,x.split())) for x in coords])
  if(not increasingcheck(coords)):
    print("NO")
    continue;
  print("YES")
  print(getpaths(coords))