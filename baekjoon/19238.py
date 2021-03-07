import sys
read = sys.stdin.readline
N,M,fuel = map(int,read().split())
mat = []
for i in range(N):
    mat.append(list(map(int,read().split())))
taxi_p = list(map(int,read().split()))

taxi = (taxi_p[0]-1,taxi_p[1]-1)

match = {}
for i in range(M):
    x,y,x_,y_ = map(int,read().split())
    match[(x-1,y-1)] = (x_-1,y_-1)
    mat[x-1][y-1] = (-1,-1) # 승객


dx, dy = [1,-1,0,0], [0,0,1,-1]
def bfs(start,end):
    q, dist = [start], 0
    check = {start:1}

    
    while q:
        Next = []
        for v in q:
            r,c = v[0],v[1]
            if v == end:
                return [v], dist, 'success'
            if mat[r][c] == end: # (-1,-1):승객 or (px,py):목적지
                ret = [(r,c)]
                if end == (-1,-1):
                    ret = []
                    for pos in q:
                        if mat[pos[0]][pos[1]] == end:
                            ret.append(pos)
                return ret, dist, 'success'


            for i in range(4):
                nx, ny = r + dx[i], c + dy[i]
                if 0<= nx < N and 0<= ny < N and mat[nx][ny] != 1 and (nx,ny) not in check:
                    check[(nx,ny)] = 1
                    Next.append((nx,ny))
                    
        q = Next
        dist += 1
    return [(r,c)], dist-1, 'fail'

x,y = taxi
fg = 0
flag = 'none'
try:
    for step in range(M):
        nomi, fuel_, flag = bfs((x,y),(-1,-1))
        if flag == 'fail':
            print(-1)
            fg = 1
            break
        fuel -= fuel_
        if len(nomi) == 1:
            x,y = nomi[0]
        else:
            nomi.sort()
            x,y = nomi[0]
        if fuel < 0:
            print(-1)
            fg = 1
            break
        mat[x][y] = 0
        nomi, fuel_, flag = bfs((x,y),match[(x,y)])
        if flag == 'fail':
            print(-1)
            fg = 1
            break
        x,y = nomi[0]
        fuel -= fuel_
        if fuel < 0:
            print(-1)
            fg = 1
            break
        else:
            fuel += (2*fuel_)
except:
    print(-1)
    fg = 1

if flag == 'success' and fg == 0:
    print(fuel)

