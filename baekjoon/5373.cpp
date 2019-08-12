/**
 * 18.12.12. 수요일
 * 머리속에 구상했던거 해보도록한다. 솔루션 안보고.
 */

#include <cstdio>

struct board{
    char map[3][3];
};

void init(struct board *b, char input) {for(int i=0; i<3; i++) for (int j=0; j<3; j++) b->map[i][j]=input;}

struct side{
    struct board face;
    char* u[3];
    char* r[3];
    char* d[3];
    char* l[3];
};

void turn(struct side *s, char cmd) {
    if (cmd=='+') // 시계방향으로
    {
        char tmp[3] = {*(s->u[0]), *(s->u[1]), *(s->u[2])};
        for (int i=0; i<3; i++) *(s->u[i]) = *(s->l[i]);
        for (int i=0; i<3; i++) *(s->l[i]) = *(s->d[i]);
        for (int i=0; i<3; i++) *(s->d[i]) = *(s->r[i]);
        for (int i=0; i<3; i++) *(s->r[i]) = tmp[i];
        char tmp2[2] = {s->face.map[0][0], s->face.map[0][1]};
        s->face.map[0][0] = s->face.map[2][0];
        s->face.map[0][1] = s->face.map[1][0];
        s->face.map[2][0] = s->face.map[2][2];
        s->face.map[1][0] = s->face.map[2][1];
        s->face.map[2][2] = s->face.map[0][2];
        s->face.map[2][1] = s->face.map[1][2];
        s->face.map[0][2] = tmp2[0];
        s->face.map[1][2] = tmp2[1];
    }
    else if (cmd=='-') // 시계방향으로
    {
        char tmp[3] = {*(s->u[0]), *(s->u[1]), *(s->u[2])};
        for (int i=0; i<3; i++) *(s->u[i]) = *(s->r[i]);
        for (int i=0; i<3; i++) *(s->r[i]) = *(s->d[i]);
        for (int i=0; i<3; i++) *(s->d[i]) = *(s->l[i]);
        for (int i=0; i<3; i++) *(s->l[i]) = tmp[i];
        char tmp2[2] = {s->face.map[0][0], s->face.map[0][1]};
        s->face.map[0][0] = s->face.map[0][2];
        s->face.map[0][1] = s->face.map[1][2];
        s->face.map[0][2] = s->face.map[2][2];
        s->face.map[1][2] = s->face.map[2][1];
        s->face.map[2][2] = s->face.map[2][0];
        s->face.map[2][1] = s->face.map[1][0];
        s->face.map[2][0] = tmp2[0];
        s->face.map[1][0] = tmp2[1];
    }
}

struct cube{
    struct side sides[6];
};



int main(int argc, char const *argv[])
{
    int T;
    scanf("%d", &T);
    for (int test_case=0; test_case<T; test_case++)
    {
        struct cube cubes;
        init(&(cubes.sides[0]), 'w');
        cubes.sides[0].u[0] = &(cubes.sides[3].face.map[0][2]);
        cubes.sides[0].u[1] = &(cubes.sides[3].face.map[0][1]);
        cubes.sides[0].u[2] = &(cubes.sides[3].face.map[0][0]);
        cubes.sides[0].r[0] = &(cubes.sides[5].face.map[0][2]);
        cubes.sides[0].r[1] = &(cubes.sides[5].face.map[0][1]);
        cubes.sides[0].r[2] = &(cubes.sides[5].face.map[0][0]);
        cubes.sides[0].d[0] = &(cubes.sides[2].face.map[0][2]);
        cubes.sides[0].d[1] = &(cubes.sides[2].face.map[0][1]);
        cubes.sides[0].d[2] = &(cubes.sides[2].face.map[0][0]);
        cubes.sides[0].l[0] = &(cubes.sides[4].face.map[0][2]);
        cubes.sides[0].l[1] = &(cubes.sides[4].face.map[0][1]);
        cubes.sides[0].l[2] = &(cubes.sides[4].face.map[0][0]);
        init(&(cubes.sides[1]), 'y');
        cubes.sides[0].u[0] = &(cubes.sides[3].face.map[0][2]);
        cubes.sides[0].u[1] = &(cubes.sides[3].face.map[0][1]);
        cubes.sides[0].u[2] = &(cubes.sides[3].face.map[0][0]);
        cubes.sides[0].r[0] = &(cubes.sides[5].face.map[0][2]);
        cubes.sides[0].r[1] = &(cubes.sides[5].face.map[0][1]);
        cubes.sides[0].r[2] = &(cubes.sides[5].face.map[0][0]);
        cubes.sides[0].d[0] = &(cubes.sides[2].face.map[0][2]);
        cubes.sides[0].d[1] = &(cubes.sides[2].face.map[0][1]);
        cubes.sides[0].d[2] = &(cubes.sides[2].face.map[0][0]);
        cubes.sides[0].l[0] = &(cubes.sides[4].face.map[0][2]);
        cubes.sides[0].l[1] = &(cubes.sides[4].face.map[0][1]);
        cubes.sides[0].l[2] = &(cubes.sides[4].face.map[0][0]);
        init(&(cubes.sides[2]), 'r');
        init(&(cubes.sides[3]), 'o');
        init(&(cubes.sides[4]), 'g');
        init(&(cubes.sides[5]), 'b');
        int cnt; scanf("%d", &cnt);
        while (cnt--)
        {
            char cmd, dir;
            int cmd_;
            if (cmd =='U') cmd_ = 0;
            else if (cmd =='D') cmd_ = 1;
            else if (cmd =='F') cmd_ = 2;
            else if (cmd =='B') cmd_ = 3;
            else if (cmd =='L') cmd_ = 4;
            else if (cmd =='R') cmd_ = 5;
            turn(&cubes.sides[cmd_], dir);
        }
        for (int i=0; i<3; i++) {
            for(int j=0; j<3; j++) printf("%d%d%d", cubes.sides[0].face.map[0][0], cubes.sides[0].face.map[0][1], cubes.sides[0].face.map[0][2]);
            printf("\n");
        }
    }
    return 0;
}
