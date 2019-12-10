//
// By Nine
//

//=============
//=============
#include <iostream>
using namespace std;
#define MAXP 10
//#define MAXN 10
#define INF 0x3fffffff

struct _Person {
    int i, j;
    int dist1, dist2;
} PEOPLE[MAXP];
int CNT_pl;
struct _Stair {
    int i, j;
    int time;
    int used;
} S1, S2;
struct _Idxtbl {
    int dist;
    int k;
    int bd_time;
} ListS1[MAXP], ListS2[MAXP];

void selSort(_Idxtbl Tbl[], int sz) {
    int     minI, i, j;;
    _Idxtbl t_temp;

    for(i=0; i<sz-1; i++) {
        minI = i;
        for(j=i+1; j<sz; j++) if( Tbl[j].dist < Tbl[minI].dist ) minI=j;
        t_temp = Tbl[i], Tbl[i] = Tbl[minI], Tbl[minI] = t_temp;
    }
}

unsigned visited, visitedS2_U;
int min_sol;
void do_scheduling(int t0, int k1_0, int k2_0) {
    int i, n1, n2, n_tmp, k1=k1_0, k2=k2_0, n_t;

    if( t0>=min_sol ) return;

    for(i=k1_0-1; i>=0 and S1.used;i--) {
        if( visitedS2_U&(1<<ListS1[i].k) ) continue; // (*)
        if( !ListS1[i].bd_time ) break;
        if( t0>=ListS1[i].bd_time+S1.time ) ListS1[i].bd_time = 0, S1.used--;
    }
    for(; k1<CNT_pl and S1.used<3; k1++) {
        if( visitedS2_U&(1<<ListS1[k1].k) ) continue; // (*)
        if( t0<ListS1[k1].dist+1 )         break;
        ListS1[k1].bd_time = t0;
        S1.used++;
        visited |= (1<<ListS1[k1].k);
    }

    for(i=k2_0-1; i>=0 and S2.used;i--) {
        if( (visitedS2_U&(1<<ListS2[i].k)) == 0 ) continue;
        if( !ListS2[i].bd_time )                 break;
        if( t0>=ListS2[i].bd_time+S2.time ) ListS2[i].bd_time = 0, S2.used--;
    }
    for(; k2<CNT_pl and S2.used<3; k2++) {
        if( (visitedS2_U&(1<<ListS2[k2].k)) == 0 ) continue;
        if( t0<ListS2[k2].dist+1 )                 break;
        ListS2[k2].bd_time = t0;
        S2.used++;
        visited |= (1<<ListS2[k2].k);
    }
    
    if( visited==(1<<CNT_pl)-1 and !S1.used and !S2.used ) {
        if( t0<min_sol ) min_sol = t0; //, cout << hex << " " << visitedS2_U << dec << endl;
        return;
    }
    
    // n_t : bd_time+S.time or t0+1 vs. dist+1
// for(n1=INF, i=0; i<k1; i++) if( ListS1[i].bd_time ) { n1 = ListS1[i].bd_time + S1.time; break; }
// for(n_tmp=INF, i=k1; i<CNT_pl; i++) if( (visitedS2_U&(1<<ListS1[i].k)) == 0 ) {
//     n_tmp = t0>=ListS1[i].dist+1 ? t0+1:ListS1[i].dist+1;
//     if( n_tmp<n1 ) n1 = n_tmp;
//     break;
// } 
// for(n2=INF, i=0; i<k2; i++) if( ListS2[i].bd_time ) { n2 = ListS2[i].bd_time + S2.time; break; }
// for(n_tmp=INF, i=k2; i<CNT_pl; i++) if( (visitedS2_U&(1<<ListS2[i].k)) ) {
//     n_tmp = t0>=ListS2[i].dist+1 ? t0+1:ListS2[i].dist+1;
//     if( n_tmp<n2 ) n2 = n_tmp;
//     break;
// }
// n_t = n1<n2 ? n1:n2;
    n_t = t0+1;
    
    do_scheduling( n_t, k1, k2);     
}

int main() {
    int TC, N, i, j, k, n, pr, pc;
    _Stair s_temp;

    //freopen("./input_2383.txt","r",stdin); //
    cin >> TC;
    
    for (int tc = 1; tc <= TC; tc++){
        S1.time=S1.used=S2.time=S2.used=0;
        cin >> N;         // 4~10
        
        for(k=0,i=0; i<N; i++) for(j=0; j<N; j++) {
            cin >> n; // 0, 1(사람들), 2~10(계단길이)
            if( !n ) continue;
            if( n == 1 )
                PEOPLE[k].i = i, PEOPLE[k].j = j, k++;
            else (!S1.time ? S1.i=i, S1.j = j, S1.time = n : S2.i=i, S2.j = j, S2.time = n);
        }
        
        CNT_pl = k;
//     if( S1.time > S2.time ) s_temp = S1, S1 = S2, S2 = s_temp;
        for(k=0; k<CNT_pl; k++) {
            pr = PEOPLE[k].i; pc = PEOPLE[k].j;
            PEOPLE[k].dist1 = (pr>S1.i ? pr-S1.i:S1.i-pr) + (pc>S1.j ? pc-S1.j:S1.j-pc);
            PEOPLE[k].dist2 = (pr>S2.i ? pr-S2.i:S2.i-pr) + (pc>S2.j ? pc-S2.j:S2.j-pc);
            ListS1[k].dist = PEOPLE[k].dist1, ListS1[k].k = k;
            ListS2[k].dist = PEOPLE[k].dist2, ListS2[k].k = k;
        }
        selSort(ListS1,CNT_pl);
        selSort(ListS2,CNT_pl);

        min_sol = INF;
        n = ListS1[0].dist < ListS2[0].dist ? ListS1[0].dist : ListS2[0].dist;
        
        for(visitedS2_U=0; visitedS2_U<(1<<CNT_pl); visitedS2_U++) {
            S1.used = S2.used = 0;
            for(i=0; i<CNT_pl; i++) ListS1[i].bd_time = ListS2[i].bd_time = 0;
            visited = 0;
            
            do_scheduling(n+1,0,0);
        }
    
        cout << "#" << tc << " " << min_sol << endl;
    }
} 