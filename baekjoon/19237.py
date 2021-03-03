import sys
read = sys.stdin.readline
mat, smell_mat,smell_chk = [], [], {}
N,M,k = map(int,read().split())
shark_pos = {}
shark_pr_direction = {}
for i in range(N):
    a = list(map(int,read().split()))
    mat.append(a)
    smell = []
    for j in range(N):
        if a[j] != 0:
            smell.append([a[j],k])
            smell_chk[(i,j)] = 1
            shark_pos[a[j]] = (i,j)
        else:
            smell.append(0)
    smell_mat.append(smell)
shark_dir = [0] + list(map(int,read().split())) # shark_dir[shark_num] = shark_direction
for num in range(M):
    shark_pr_direction[num+1] = [[0]]
    for i in range(4):
        shark_pr_direction[num+1].append(list(map(int,read().split())))
def smell_check():
    delete = []
    for chk in smell_chk:
        cx,cy = chk[0],chk[1]
        smell_mat[cx][cy][1] -= 1
        if smell_mat[cx][cy][1] == 0:
            smell_mat[cx][cy] = 0
            delete.append(chk)
    for d in delete:
        del smell_chk[d]
def smell_dist():
    for s_num in shark_pos:
        sx,sy = shark_pos[s_num]
        smell_mat[sx][sy] = [s_num,k]
        smell_chk[(sx,sy)] = 1
dx = [0,-1,1,0,0]
dy = [0,0,0,-1,1]
def move(): # 이동순서는 상관없음
    will_move_pos = {}
    for s_num in shark_pos:
        sx,sy = shark_pos[s_num]
        mat[sx][sy] = 0
        priority_list = shark_pr_direction[s_num][shark_dir[s_num]]
        power = {}
        fg = 1
        for p in priority_list:
            nx,ny = sx+dx[p], sy+dy[p]
            if 0 <= nx < N and 0 <= ny < N and smell_mat[nx][ny] == 0:
                if (nx,ny) not in power:
                    power[(nx,ny)] = s_num
                    will_move_pos[s_num] = (nx,ny,p)
                else:
                    if power[(nx,ny)] > s_num:
                        del shark_pos[power[(nx,ny)]] 
                        power[(nx,ny)] = s_num
                        will_move_pos[s_num] = (nx,ny,p)
                fg = 0
                break
        if fg:
            for p in priority_list:
                nx,ny = sx+dx[p], sy+dy[p]
                if 0 <= nx < N and 0 <= ny < N and smell_mat[nx][ny][0] == s_num:
                    if (nx,ny) not in power:
                        power[(nx,ny)] = s_num
                        will_move_pos[s_num] = (nx,ny,p)
                    else:
                        if power[(nx,ny)] > s_num:
                            del shark_pos[power[(nx,ny)]]
                            power[(nx,ny)] = s_num
                            will_move_pos[s_num] = (nx,ny,p)
                    fg = 0
                    break
    for s_num in will_move_pos:
        wx,wy,np = will_move_pos[s_num]
        # mat[wx][wy] = s_num
        # shark_pos[s_num] = (wx,wy)
        # shark_dir[s_num] = np
        if mat[wx][wy] > s_num or mat[wx][wy] == 0:
            if mat[wx][wy] > 0:
                del shark_pos[mat[wx][wy]]
            mat[wx][wy] = s_num
            shark_pos[s_num] = (wx,wy)
            shark_dir[s_num] = np
        else:
            del shark_pos[s_num]
ffg = 1
for time in range(1000):
    move()
    smell_check()
    smell_dist()
    if len(shark_pos) == 1:
        print(time+1)
        ffg = 0
        break
if ffg:
    print(-1)
