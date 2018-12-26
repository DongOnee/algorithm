/**
 * 18.12.26. 목요일 
 */
#include <cstdio>
#include <string>
#include <stdlib.h>
using namespace std;

struct node {
    string s;
    struct node *next;
};

struct node begin_1={"", NULL};

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        char tmp[51];
        scanf("%s", tmp);
        struct node *tmps = (struct node*) malloc(sizeof(struct node));
        tmps->s=tmp;
        struct node *k = &begin_1;
        while (k->next!=NULL)
        {
            if (tmps->s.length()>k->next->s.length())
            {
                k=k->next;
                continue;
            }
            else if (tmps->s.length()==k->next->s.length())
            {
                if (tmps->s.compare(k->next->s)<=0) break;
                else
                {
                    k=k->next;
                    continue;
                }
            }
            else break;
        }
        tmps->next = k->next;
        k->next = tmps;
    }
    struct node *k = begin_1.next;
    while (k->next!=NULL)
    {
        if (k->s.compare(k->next->s)!=0) printf("%s\n", k->s.c_str());
        k = k->next;
    }
    printf("%s\n", k->s.c_str());
    return 0;
}
