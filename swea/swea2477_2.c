//
//  2477 차량 정비소.cpp
//  
//
//  Created by Jihee Chae on 2018. 4. 3..
//

#include <stdio.h>

typedef struct tagArea {
    int cus, timeleft, ophour;
} area;

typedef struct tagcus {
    int info, center, arrival, depart;
} customer;

int main(){
    int tc;
    int n, m, k, a, b;
    
    area info[11], center[11];
    customer cus[1001];
    
    scanf("%d", &tc);
    
    for(int t=1 ; t <= tc;  t++){
        scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);
        
        for(int i=1 ; i <= n ; i++){
            scanf("%d", &info[i].ophour);
            info[i].timeleft = 0;
        }
        
        for(int i=1 ; i <= m ; i++){
            scanf("%d", ¢er[i].ophour);
            center[i].timeleft = 0;
        }
        
        for(int i=1 ; i <= k ; i++)
            scanf("%d", &cus[i].arrival);
        
        
        ////접수 창구 나열 시작
        int q[1001] = {0,}, tail = 0;
        
        int ptr = 1, time = 0;
        while(ptr <= k || tail < k ){
            //printf("time : %d\n", time);
            
            for(int i=1 ; i <= n ; i++){ //창구마다
                
                if(info[i].timeleft >= 1){
                
                    --info[i].timeleft;
                    //printf("info %d : %d timeleft\n\n",i,  info[i].timeleft);
                    if(info[i].timeleft == 0){
                        cus[info[i].cus].depart = time;
                        q[tail++] = info[i].cus;
                       
                    }
                }
                
                if(cus[ptr].arrival <= time && ptr <= k && info[i].timeleft == 0){
                    //printf("cus %d in to info %d at %d\n", ptr, i, time);
                    info[i].cus = ptr;
                    cus[ptr].info = i;
                    info[i].timeleft = info[i].ophour;
                    ptr++;
                }
            }
            time++;
        }
       
        ptr = 0; time = cus[q[0]].depart;
       
        while(ptr < tail){
            //printf("t %d\n", time);
            for(int i=1 ; i <= m ; i++){
                if(center[i].timeleft >= 1)
                     --center[i].timeleft;

                //printf("%d depart %d <= %d\n", ptr, cus[ptr].depart, time);
                if(center[i].timeleft == 0 && cus[q[ptr]].depart <= time) {
                    //printf("ptr %d - cus %d going in at %d to %d\n", ptr,q[ptr], time, i);
                    center[i].cus = q[ptr];
                    cus[q[ptr]].center = i;
                    center[i].timeleft = center[i].ophour;
                    ptr++;
                }
            }
            time++;
        }
        
        int res = 0;
        
        
        for(int i=1 ; i <= k ; i++){
            //printf("cus %d : %d - depart %d -  %d\n",i, cus[i].info,cus[i].depart, cus[i].center);
            if(cus[i].info == a && cus[i].center == b){
                res += i;
            }
        }
        if(res == 0) res = -1;
        printf("#%d %d\n",t, res);
    }
   
}