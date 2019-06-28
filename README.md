# Algorithm Think...

알고리즘 문제를 풀면서 깨달은 것들을 적어보자. 나중에 코딩테스트를 보러 갈 일이 있다면 한번씩 봐보도록. 다른사람들도 도움이 됬으면 좋겠다.

## 19.6.28.
1. BOJ 9370
    - Algorithm : Dijkstra algorithm
    - challenge.
        1. 다익스트라 다익스트라!!! 아직 사용법이 익숙지 않다. 사용하는 상황에 대해선 어느정도 감이 잡은듯 하다. 가중치 값을 이용하고, 시작점이 특정한 점이고, 목표지점은 모르지만 가중치를 이용한 값이 최대/최소 가 되어야 할때 사용한다. 이와 유사한 알고리즘으로 벨만-포드랑 하나 뭐 있었는데... 각각의 차이점 다시 리마인드 해보자.
    - Talk. : 시간 많이 썻다. 오전 5시 20분 쯤부터 시작해서 코드 하나를 갈아 치웠다. 다익스트라 알고리즘을 프로그래밍 하는 것에 대해서 익숙해졌다고 생각했는데 살짝 문제에 MSG를 치니까 아무것도 못하죠~ 그리고 Thinking 을 잘했다고 생각한다 다른사람들은 다익스트라 알고리즘 두번 사용하는데 나는 한번 사용하는 코드로 끝냈다... 근데 소요시간은 왜 이 모양이고.. 메모리 사용은 왜 이 모양인건지 해결해야될 문제라고 생각한다.

## 19.6.26.
1. BOJ 13199
    - Algorithm : 수학
    - challenge.
        1. 반복문을 이용해서 쿠폰을 이용한 치킨 구매와 남은 쿠폰 갯수를 업데이트 하는 방식을 이용해보았는데 시간초과가 떳다.
        2. 점화식을 만들어서 풀어보려고 노력하였다.
            - <img src="https://latex.codecogs.com/gif.latex?R_n=f*A_n+B_n " /> 
            - <img src="https://latex.codecogs.com/gif.latex?R_{n+1}=c*A_n+B_n " /> 
            - <img src="https://latex.codecogs.com/gif.latex?R_n-R_{n+1}=(f-c) *A_n " />
            - <img src="https://latex.codecogs.com/gif.latex?A_k+...+A_1 = {R_1-R_{k+1} \over {f-c}}" />
            - 문제는 <img src="https://latex.codecogs.com/gif.latex?R_{k+1}" /> 을 도저히 구할 수 없었다.
        3. 결국 코드 봤는데 한번에 이해가 안되고 곰곰히 생각끝에 해내었다.
            - remain_coupon 을 한번에 최대한 많이 사용하여 치킨을 시켜먹지말고 1 치킨씩 구매해서 먹는다고 생각해보자
            - remain_coupon 중 f 개의 쿠폰을 이용하여 치킨을 한마리 시켜먹으면 remain_coupon -f 개의 쿠폰이 남고 c 개의 쿠폰을 얻을 수 있다.
            - 결국 remain_coupon -f + c 개의 쿠폰이 남는다. 같은 방식으로 진행하면 몇번을 이용할 수 있을까?
            - 최소 쿠폰이 f 개 있어야되니까 `if (remain_coupon <= f)`
            - rc , rc-f , rc-2f , rc-3f , ... 일때 총 rc/(f-c) +1 개가 나온다
            - 그 중 f 보다 작은 값의 갯수는 f/(f-c) 개가 있다.
            - 따라서 (rc-c) / (f- c) 개의 치킨을 더 먹을 수 있다.
    - Talk. : 수학문제 매우 하드한 문제인거 같다. 즐겨찾기 추가했다.

## 19.6.26.
1. BOJ 1504
    - Algorithm : DP
    - challenge.
        1. 맨 처음에 문제 잘못 이해해서 ㅋㅋㅋㅋㅋㅋ `point[0]`번 정점부터 `point[1]`번 정점까지 가는건줄 알고 잘못 계산 하였다.
        2. BFS 으로 풀어보려고 하였는데 `point[0]`, `point[1]` 을 지났다는 것을 저장히가 벅차다는 생각이 들어서 포기하였다.
        3. 디피 최고
    - Talk. : 상태를 저장하는것중 가장 좋은 방법이 디피인듯 싶다. 이번문제는 정말 오래 걸렸는데 결국 스스로 생각해서 풀었다. 이 문제를 풀고 깨달은 것은 앞서 말한것과 내가 DP를 알고 있지 않았으면 못풀었을 문제라는 점이다. 다양한 알고리즘들을 공부해보자

## 19.6.24.
1. BOJ 1655
    - Algorithm : 힙
    - challenge.
        1. single priority queue 이용해서 push 할때마다 자동 정렬이 이루어 지고 정렬된 자료형에서 중간값(pq[i/2]를 이용해서) 을 출력할 수 있을거라 생각했는데 queue 특성상 random access가 안되서 문제가 되었다. 구글에 검색해봤는데 불가능 하다고하네
        2. vector 를 이용해서 이진트리를 만들어서 root 를 기준으로 좌측은 작은것 우측은 큰것으로 하려고 했다. 근데.. 아무튼 안됫다.

## 19.6.19.
1. BOJ 2512
    - Algorithm : 이분탐색
    - Talk. : 초기에 값에 대한 체크를 해야된다. 각 지방의 예산 요청 값을 모두 더한다음 그 값이 budget 과 비교 하였을때 작으면 모든 지방에 요청 금액을 주면된다. **문제를 잘읽자** 1번 조건에 대해서 생각안하고 지나가서 오랜 시간 걸린것이다. 

## 19.6.18.
1. BOJ 1041
    - Algorithm : 수학
    - Talk. : 자료형 때문에 마지막 제출 몇분 날려먹었땅~~

## 19.6.13.
1. BOJ 1654
    - Algorithm : 이분탐색
    - Talk. : 이제 이런 기본적인 문제는 쉽다.!! 좀 어려운 문제를 풀어보자.

## 19.6.13.
1. BOJ 2805
    - Algorithm : 이분탐색
    - Talk. : 이런이런... 변수 설정을 잘못했다... scope 에 문제가 생기지 않을까?? 
    - Think. : ```int : –2,147,483,648 ~ 2,147,483,647 ``` ```long long : –9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 ```

## 19.6.12.
1. BOJ 10815
    - Algorithm : 이분탐색
    - Talk. : 이분탐색 다시 공부해보기로 했다. 간단한 문제도 너무 오래 걸린거 보면.. 좀 못한다.ㅎㅎㅎㅎㅎ 한 문제 더 풀어보자.

## 19.6.10.
1. BOJ 17142
    - Algorithm : 시뮬레이션 & 완전탐색(DFS/BFS)
    - Talk. : 속도조금 찾은거 같다. 좀더 분발해서 1시간 이내로 클리어 해봐야겠다. 확실히 메모리 효율 생각 잘 안하고 막하니까 어찌어찌 된다.

## 19.6.9.
1. BOJ 17143
    - Algorithm : 시뮬레이션 & 완전탐색
    - Talk. : 또 실수... 습관이 나왔다. map 의 자료형을 shark 로 하면되었는데 그놈의 메모리 효율 생각하며 자료구조 써보려다가 시간만 엄청 날렸따. 그리고 XOR  을 잘사용하였다고 생각한다. 1 이면 toggle, 0 이면 그대로

## 19.6.7.
1. BOJ 17144
    - Algorithm : 시뮬레이션
    - Talk. : 아 어렵고 쉽고 문제가 아니라... 너무 감떨어졌다. 역시 하다가 안하니까 너무 못하게 되었다.

## 19.4.12.
1. BOJ 9019
    - Algorithm : DFS & 시뮬레이션
    - Talk. : visited 배열을 잘못 이해해서 시간 엄청 소모 했다.

## 19.4.12.
1. BOJ 9019
    - Algorithm : BFS
    - Talk.
        - 문자를 vector 에 넣어 하나씩 출력하는 방법을 이용 하였는데, 시간초과가 나오는 것이었다. BFS 알고리즘에 문제인가 싶어서 바꿔보기도 하였는데 해결 하지 못하였다. vector 를 사용하지 않고 string 자료형으로 바꿔서 출력 해 보았떠니 쉽게 처리 할 수 있었다.

1. BOJ 1697
    - Algorithm : BFS.

1. BOJ 7453 *****
    - Algorithm : BS.
    - talk : 꼭 다시 풀어보자 꼬오오오옥

1. BOJ 2309
    - Algorithm : 쉬운거

## 19.4.8~11.
1. Samsung 역량 테스트 기출문제
    - 다 풀었다.
    - 링크 https://www.acmicpc.net/workbook/view/1152

## 19.4.5.
1. BOJ 1325
    - Algorithm : 그냥 쉽다. DFS 이용해서 풀면 된당.

## 19.4.5.
1. BOJ 1837
    - Algorithm : 그냥쉽다.

1. BOJ 1837 **
    - Algorithm : 소수찾는 문제, 에라토스테네스의 체 를 이용해서 풀었다. 근데... 이거 문제를 꼼꼼히 읽어서 확인해야되겟다. k 값을 포함시켜서 서치하면 안되는데 포함시켜 버리니까 오류가 났다.
    - Error Detect
        ```
        ./a.out
        77 7
        BAD 7
        ```
        위의 결과가 나오면 틀렸다. 왜냐하면 k =7 인데 **K보다 작은 암호는 좋지않다.** 라는 말이 있으니 7 은 포함되면 안된다. 코드 수정 결과
        ```
        ./a.out
        77 7
        GOOD
        ```

## 19.4.3.
1. BOJ 2904 **
    - Algorithm : 소수찾는 문제, 에라토스테네스의 체 를 이용해서 푼후 나머진 논리 문제였다.

## 19.3.29.
1. BOJ 1126 **
    - Alogirithm : DP 를 이용한 방법인데! 오래오래 풀었다. 26일에 살짝 맛좀 보게 만들었다가 29일에 풀었다.
    - Talk : 맨처음엔 memorize 하지 않는 방법으로 1차원 배열만 만들었는데 그렇게 하면 이 전 과정의 기록이 지워지기때문에 정답을 받을 수 없다. 즉 이전 기록이 두번이상 사용된다. 그래서 2차원 배열을 만들어야 된다.(xx) ㅇㅋ? 그리고 max 메소드를 사용하여 최대값을 항상 저장해두면 정답에 가깝다. (xxx)

## 19.3.21.
1. SWEA 1242 **
    - Alogirithm : 졸라 어렵다... 후 24시간 걸렸다 더욱 쉽게 푸는방법 있지 않을까?

## 19.3.20.
1. SWEA 2047
    - Alogirithm : 쉽다.

1. SWEA 1224
    - Alogirithm : 계산기 같은거? char 를 입력 받는데서 실수가 있을 수 있다.

1. SWEA 1233 **
    - Alogirithm : ?
    - Talk : 진짜 쉬운문제인데.. 너무 너무 멍청하게 돌아갔다. string 처리하는것을 배울수 있으니 나중에 코드 한번 확인하는게 좋다.

1. SWEA 1240
    - Alogirithm : 브루트 포스
    - Talk : 진짜 쉬운뎅.... 좀 그렇다.... 8을 찾기 전에 0을 찾아버리고 6을 찾기 전에 8를 찾아 버린다. 예외 처리를 좀 드릅게 했다 ^^

## 19.3.14.
1. BOJ 1010
    - Alogirithm : 쉽다.

1. BOJ 1012
    - Alogirithm : queue 와 DFS 를 이용한 쉬운 문제.

## 19.3.3.
1. BOJ 1238
    - Alogirithm : 다익스트라 알고리즘
    - Talk : 다익스트라 알고리즘을 두가지 사용해서 푸는 것이다... 저먼에 한번 못풀어서 다시 시도 해쓴데 3시간이나 걸리는 기적ㅇ!! ㅋㅋㅋㅋ 대충 힌트 아는데도 오래 걸렸다. a->a 초기값을 ~~1e9~~ 가 아닌 *0* 로 했더니 풀렸다. 이유는 곰곰히 생각해보도록 하자.

## 19.2.27.
1. BOJ 11403
    - Alogirithm : 폴로이드 와샬 알고리즘
    - Talk : 이 알고리즘은 그냥 복붙 수준이다. DFS/BFS 를 이용한 방법으로 풀어보도록 하자. 나중에.

1. BOJ 1238
    - Alogirithm : 다익스트라, 폴로이드 와샬 알고리즘
    - Talk : 플로이드 와샬 알고리즘 카테고리에서 봤는데 다익스트라 알고리즘 문제라고 한다.? 플로이드 와샬로도 풀어볼 수 있지 않을까?

1. BOJ 10159
    - Alogirithm : 폴로이드 와샬 알고리즘
    - Talk : 순수 플로이드 와샬 알고리즘이다. 다익스트라랑 플로이드 와샬 알고리즘의 차이점?? 어떨때 사용하는지에 대해서 알아봐야 겠다.
        - **플로이드 알고리즘** 소스가 훨씬 더 간결하다.
        - **플로이드 알고리즘**은 *간선 수*가 많으면 다익스트라 알고리즘보다 빠를 수가 있음.
        - *시작점으로부터 각 정점까지 최단거리*만 구해도 될 때, 보통 **다익스트라 알고리즘**이 압도적으로 빠름.
        - 그래프에 *음의 가중치* 간선이 있으면(물론 음의 싸이클은 없어야 한다) 다익스트라 알고리즘은 못 쓰지만 **플로이드 알고리즘**은 사용할 수 있다.
        - ref. https://codedoc.tistory.com/95

1. BOJ 1753
    - Alogirithm : dijkstra 알고리즘
    - Talk : 다익스트라 알고리즘 공부하기용으로 적합하다. 굉장히 기초적인 문제인데 다른 문제들을 풀어보는게 좋을듯 싶다.


## 19.2.26.
1. BOJ 6549 **
    - Alogirithm : 이분탐색, 세그먼트 트리
    - Talk : 다시 풀어보기... 못풀었으니까

1. BOJ 2261 **
    - Alogirithm : ?????
    - Talk : 다시 풀어보기... 못풀었으니까

1. BOJ 1389
    - Alogirithm : 플로이드 와샬 알고리즘
    - Talk : 저번에 같은 알고리즘 풀어 봤는데 실패가 많이 나오더라... 아직 익숙하지 않아서 인듯 싶다. 알고리즘 분류에 보면 DFS / BFS 도 있다. 다른 방법으로 푸는 것도 확인해 보자. **플로이드는 거리 초기값이 중요하다.**
    - Ref. https://barefoot-coder.tistory.com/36

## 19.2.25.
1. BOJ 2749 **
    - Alogirithm : 이분탐색, 행렬
    - Talk : 꼭 다시한번 풀어보고 이러한 방법이 있다는것을 흡수하도록 하는게 좋을거 같다. 피보나치 수열같은 시간초과가 당연히 걸리는 것을 행렬을 이용하여 풀었다.. 굉장히 놀랍다.
    - ref. https://m.blog.naver.com/PostView.nhn?blogId=jh05013&logNo=220999768783&proxyReferer=&proxyReferer=https%3A%2F%2Fwww.google.com%2F

## 19.2.22.
1. BOJ 11279
    - Alogirithm : Heap  어제푼 문제보다 쉬운거.

1. BOJ 1927
    - Alogirithm : Heap  어제푼 문제보다 쉬운거.

1. BOJ 1766
    - Alogirithm : Heap + 위상정렬
    - Ref. : https://jason9319.tistory.com/92
    - Talk : 굉장히 고전한 문제이다... ```pre_solve_problem_cnt``` 를 이용하였는데 **실패 하였습니다.** 가 나왔을때 자료형을 boolean 으로 하였는데 생각해 보니 한 문제를 풀기 위해 먼저 풀어야 되는 문제가 여러개일경우 문제가 생긴다.

## 19.2.21.
1. BOJ 7562
    - Alogirithm : 전형적인 BFS 문제이다.
    - Talk : 메모리 초과가 나는 경우를 잡았다. 다른곳에서 출발하여 나이트 이동을 하였을때 같은곳에 도착하는 경우가 있다. 따라서 queue 에 push 할때 visited 체크를 해주어서 다른 곳에서 출발할때 같은곳에 도착하더라도 queue 에 push 하지 않도록 한다.

1. BOJ 11286
    - Alogirithm : Heap
    - Talk : Heap 이라고 별거 있을줄 알앗는데 그냥 ```priority_queue ``` STL 에 별게 있더라. 그냥 ```vector``` 를 이용해서 push 할때마다 sort 를 하면 시간 초과가 뜨지만 ```priority_queue``` 를 이용해서 push 를 하면 자동적으로 sort가 되느 동시에 최적의 시간으로 sort 를 하더라~

## 19.2.19.
1. BOJ 10830 **
    - Alogirithm : 오히려 매트릭스 곱 만드는게 더 어려운 문제라구

## 19.2.19.
1. BOJ 2110 **
    - Alogirithm : 이분탐색 문제의 끝판왕이라고 생각된다.
    - Think. : 이분탐색을 사용하는 문제에 대해서 생각해 볼 수 있다. 이러한 문제가 이분탐색을 사용하구나 싶은 느낌을 받았다. 대부분의 사람들(나 포함)은 이 문제를 보고, 공유기사이의 거리가 최대가 될때 부터 시작하여 감소적으로 조건을 따저볼 거라 생각된다. 삽질 오지게 한다. 몇번의 시간초과가 나올것이다.
    - mid값 주기 : ```mid = (l + r + 1) /2```로 할당 하는 방법과 ```mid = (l + r) /2```로 할당하는 방법이 있다. 그리고 조건을 확인하여 ```mid``` 값을 ```l``` 또는 ```r``` 값에 할당하는 것도 중요한 이슈가 된다. 글로 적긴 너무 어렵다.. 문제를 다시 풀어보며 느껴보도록하자.

## 19.2.18.
1. BOJ 11404 **
    - Alogirithm : 3중 for 문...?? **플로이드-워셜** 알고리즘??? (https://ko.wikipedia.org/wiki/%ED%94%8C%EB%A1%9C%EC%9D%B4%EB%93%9C-%EC%9B%8C%EC%85%9C_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98)
    - 잡담 : 이게 ..? 이게 시간 초과가 안뜬다구?? 그리고 예외 얼마든지 있을거 같은데?? 다시 다시다시 생각해보자

## 19.2.15.
1. BOJ 11725
    - Alogirithm : Tree 순회?? DFS 를 이용하여 인접한 노드들을 탐색하여 parant array 에 저장하는 방법을 이용하였다.
    - 잡담 : vector 를 이용하니 쉽긴하다. 너무 너무 어렵게 생각하다가. 너무너무 쉽게 생각했다가 아주 쓰레기 였다.

## 19.2.14.
1. BOJ 2252 ** 
    - Alogirithm : 난 도저히 이걸 생각해 낼 자신이 없어 ㅜㅜㅜ. vector 의 편리성이란.. 대단하다. **위상정렬** 이라는 알고리즘에 엄청난 도움이 된다. for, auto 를 이용한 방법도 디게 좋다. python 에서 ```for ELEM in LIST: ``` 을 사용하는것과 같은 상황에서 이용할 수 있다.

## 19.2.13.
1. BOJ 2661
    - Alogirithm : 이틀정도 고민하였다. 크게 두가지 방법을 생각해 보았는데 첫번째는 이진탐색을 통해서 반을 나눈 후 왼쪽 부분과 오른쪽 부분 둘다 최소가 되었을 경우 가장 최소라고 생각하고 해보았는데 ... 예외가 겁나 만았다. 예를 들면 N 이 5라고 하였을때 답은 12131이다. 하지만 이 방법대로 하면 12112 를 구하게 되는데 이건 규칙에 위배된다. 정답은 백트레킹을 이용하여 하나하나 다 비교해보는 방법이다.
    - c++ String 자료형을 이용하는 방법에 대해서 좀 익혓다. c_str() 이던지, push_back ... 등등.. 

## 19.2.11.
1. BOJ 1916
    - Alogirithm : 다익스트라 알고리즘을 공부하기 위해서 풀어본 문제였다. 생각보다 어렵진 않았찌만 생각보다 오래 걸렸다. 초반에 생각했던 예외 처리(A->B 버스가 여러대 있을 경우) 에 대해서 망각하고 있다가 계속 실패가 떠서 검색해보니 그거였다..ㅎㅎ
1. BOJ 4485
    - Alogirithm : DFS 를 이용해서 풀어봤는데... 시간 초과가 나온다. 알고리즘 분류를 보니 다익스트라 알고리즘이라고 한다. 다익스트라 알고리즘에 대해서 공부해보자


## 19.2.7.
1. BOJ 1920
    - Alogirithm : 이분탐색?? 튜토리얼 수준의 문제를 한번 풀어보았다. algorithm 라이브러리의 sort 함수를 이용하였지만 근본적으론 이분탐색을 이용한 것이었다. 이전에 c 로 짠 코드가 있길레 대충 훅 보니까 완전 이것저것 다 가져다 쓴듯한 느낌을 받았다.

## 19.2.2. ~ 7.
1. BOJ 1300 **
    - Alogirithm : 이분탐색?? 뭔지 모르겠다. + 이분탐색의 테크닉 보단 배열에서 카운트 세는 개념에 대한 이해가 더 어려운 문제라고 생각 된다. 지금도 완벽하게 이해하지 못하였다고 생각한다.

## 19.1.31.
1. BOJ 2449 **
    - Alogirithm : DP 를 이용한 문제이다. 점화식을 세우는 연습을 해야겠다. DP 인지 몰랐을 때는 완전 탐색을 이용해서 푸려고 하였지만 실패가 떳다. 도저히 반례를 찾지 못하여서 카테고리를 보고 검색하여 풀었다. 점화식을 만들 수 있다면 DP 문제는 크게 어렵지 않다고 생각한다. 하지만 다음번에도 이 문제를 풀어봐서 연습 해야겠다.

## 19.1.30.
1. BOJ 1726

## 19.1.11.
1. BOJ 11401
    - Alogirithm : 아래 유형과 비슷하다. factorial 연산을 분할 정복을 통해서 미리 계산해 두고 문제를 푸는 방식이었다. 
    - 잡담 : main 함수 안에서 long long 자료형 4000000 개를 선언하였더니 segmentation fault 가 나왔다. 그래서 전역변수로 바꾸어 보앗더니 에러가 해결 되었다. 이유가 무엇일까?

## 19.1.8.
1. BOJ 13172
    - Alogirithm : Moduler 연산. 그그그 약수분해 하는 알고리즘 뭐더라 ?
    - 잡담 : ㅋㅋㅋㅋ 그냥 해보면 되는건데 이거저거 생각하다보니 멍청해 졌다 !! 모든 지수함수는 O(log) 의 시간으로 처리 할 수 있다. 

## 19.1.7.
1. BOJ 13171 **
    - Alogirithm : Moduler 연산. 너무 어렵게 생각하려고 하였나? 싶지만, 내가 그냥 못한거 같다. 이 문제 다시 한번 봐봐야 겠다. 


## 19.1.6.
1. BOJ 1946
    - Alogirithm : sorting 문제를 너무 구데기처럼 푼 경향이 없잖아 있다. 흠... 리뷰를 다시한번 해볼 필요가 있다.

## 19.1.4.
1. BOJ 1049
    - Alogirithm : sorting.. 이 필요하나 싶다 최고값만 있으면 된다.

## 19.1.3.
1. BOJ 4307
    - Alogirithm : sorting.. 살짝 생각이 필요하다. 개미가 부딫히면 서로 다시 반대방향으로 가게 되는데, 개미에 대한 구분이 없으면 이말은 통과하여 간다는것과 똑같다. 생각해보면 안다. 그러니 개미마다 짧은 구간과 긴 구간을 나누어 짧은 구간이 가장큰 개미의 값과 긴 구간이 가장 큰 개미의 값을 구하여 나타내었다.
    - 잡담 : 그림첨부 하고 싶은데...

2. BOJ 11399
    - Alogirithm : sort... 

## 19.1.2.
1. BOJ 1931
    - Algorithm : greedy algorithm
    - 잡담
    sort 하는 기존을 다르게 생각해보면 되게 빠른 시간에 해답을 추출 해 낼 수 있다. 처음에는 회의 시작시간을 기준으로 sort를 하였는데 참고 자료를 찾아보니 회의 종료 시간을 기준으로 sort를 하면 greedy Algorithm 을 쉽게 돌려서 해답을 찾을 수 있다.
    - Ref. http://red-pulse.tistory.com/94

## 18.12.30.
1. BOJ 11047
    - Algorithm : greedy algorithm (쉬움)

2. BOJ 10773
    - Algorithm : stack (쉬움)

3. BOJ 2312
    - Algorithm

4. BOJ 9020
    - Algorithm : 소수찾기 (쉬움)

## 18.12.29.
1. BOJ 2960
    - Algorithm : 소수찾기 (에라토스테네스의 체)

2. BOJ 4948
    - Algorithm : 소수찾기

3. BOJ 11650
    - Algorithm : Sorting...
    - Ref. https://dongyeollee.github.io/2018/03/04/Al/11650/
    - Ref. https://www.acmicpc.net/blog/view/22
    - 잡담
흠흠.. x 좌표를 비교하고~ y 좌표를 비교해서 두번 하려고 했었는데? STL 을 이용하면 쉽지 않을까 해서 찾아보았떠니 역시나 STL 짱


## 18.12.26.
1. BOJ 1181
    - Algorithm : Linked list 를 만들었다. 좀 머리 쓰긴 했는데 STL 을 사용하는 방법을 익혀볼까 했는데 필요 없을듯 싶다. 

2. BOJ 2108
    - Algorithm : Count Sort 비스무리하게 사용하였다.
이 문제는 피드백이 필요할 거 같다.

## 18.12.21.
1. BOJ 10989
    - Algorithm : Count Sort 라는 새로운 sort 방법이었다.
    - 잡담 : 메모리초과가 계속 떳다. 이유는 쓸대없는 배열을 선언했기 때문이다. 고쳐서, 카운트 갯수만 저장한 다음에 그 저장된 갯수만큼 출력해주기만 하면 그런건 메모리초과는 뜨지 않았다.
    - Ref. http://www.cs.miami.edu/home/burt/learning/Csc517.091/workbook/countingsort.html

1. BOJ 1085


## 18.12.20.
1. BOJ 1074
    - Algorithm : 재귀, 분할 정복 문제 였다. 규칙을 찾는게 주 알고리즘 인거 같다. 어찌어찌 잘해서 잘되었다. 집중하고 햇으면 더 빨리 풀 수 있었을거 같다.

1. BOJ 2447



## 18.12.19.
1. BOJ 1436
    - Algorithm : Brute force 문제이다. 숫자를 1씩 증가하며 조건에 만족하면 카운트를 하는 방법으로 실행해 보았다.
    - 잡담
또또ㅗ또또또또또ㅗㅗ또또ㄸ 어렵게 생각하고 그른다... 그냥 바로 부루트 포스로 풀면 될텐데 규칙을 찾으려고 한다. 어? 좀 찾은거 같기도 하고 좀 그른다.
    - ref. http://sunrinnote.tistory.com/96

1. BOJ 1107


## 18.12.17.
1. BOJ 1018
    - Algorithm : Brute force 시뮬레이션 문제이다.
    - Mistake : 문제에서 map 을 char[][] 로 받아 왔다. 최대 길이가 50 이라고 하여서 char[50][50] 을 하였으나... string 성격상 size 를 **51** 을 해야지 오버플로우 관련 문제가 발생하지 않는다.


## 18.12.16.
1. BOJ 2981
    - Algorithm : 최대공약수(GCD) 를 이용하여 풀기. 수학문제.

    - 할말
수학문제이다. GCD 의 성질을 이용한 문제였다. 문제에 대한 이해는 어느정도 된거 같다. 솔루션을 검색해보았는데 vector 과 interator 를 이용하는 방법에 대해서 공부해 볼 필요가 있다고 생각한다. 몇 가지 메소드를 이용한다면 굉장히 쉽게 문제를 풀 수 있었다. 하지만... 코딩테스트에서 STL 를 사용 못하게 한다면...? sort 같은거 불편해서 어떻게 행 ㅜㅜ

1. BOJ 3036

## 18.12.11.
1. BOJ 15686
    - Algorithm
또 시뮬레이션 문제이다. 삼성은 시뮬레이션 문제를 좋아하나 부다. DFS + Back Tracking 문제이다. 이거 비슷한 문제가... 있었는데, 이 문제 역시 애먹었다.
    1. 경우를 추출
    M개의 가게이 선택되는 **경우** 알고리즘을 돌려야 된다. 이 경우를 만들기 위해선 DFS 를 이용하여 모든 index 의 가게을 순서대로 순회 하면서 선택 -> DFS Func / 비선택 -> DFS Func 를 하는 방법을 이용하였다. 처음엔 BFS 를 이용하여 각 가정마다 가장 가까운 가계를 찾는 방법에 대해서 초점을 맞춰 문제를 풀어 보았는데 너무... 돌아갔나 싶다. 만약 시간이 있따면 이 방법을 이용해서 푸는것도 좋을거라 생각된다.

    - Ref. http://wjdgus2951.tistory.com/99

## 18.12.10.
1. BOJ 15685
    - Algorithm
시뮬레이션 문제이다. map 배열이 포에서 주어진거랑 다른개념으로 생각하여야 된다... 안그래서 엄청 오래 걸렸다.

    - Talk...
이거 저번에 인턴 시험갔을 때 풀었떤 문제이댜.. 그땐 잘풀었는데 왜 못하겠지?? ㅜㅜㅜㅜ


## 18.12.07.
1. BOJ 15684
    - Algorithm
시뮬레이션 문제 답게 Brute Force 문제이다. DFS 를 이용하여 시뮬레이션을 돌려 보았다.

    - Incorrect
    1. Time complexity
    사실 ~~시간 초과~~ 가 나왓다는게 아니다. 문제에 부합하는 조건에 맞는지 틀리는지 확인하는 알고리즘을 짜는데 너무 Time complexity 를 고려하다보니 간단한 문제를 어렵게 생각하는 경향이 있다. 그 부분에서 시간이 많이 잡아 먹었다. **일단 하자!**
    2. Map define
    주어진 사다리를 2차원 배열에 넣고, 초기화 하는 과정에서 몇가지 생각을 해보았다. 가로선 을 기준으로 H 개 행과 N-1 개의 열이 있는 2차원 bool 배열을 만들어서 연결되어 있으면 (실선) True, 연결되어 있지 않으면(점선) False 로 표기하는게 첫번째 방법이고, 두번째 방법은 H행, N열로 각열은 세로선을 타나내며 i 행, j 열의 값이 1이면 오른쪽으로 실선, -1 이면 왼쪽으로 실선, 0이면 선이 없다는 배열을 만들었다. chk 함수를 돌리기에 편했다. 하지만 그냥 문제에 주어진대로 간단하게 생각하는게 좋았다. 검사할대 if 문 한번만 더쓰기만 하면된다.

    - Ref. http://mini-ko.tistory.com/11

## 18.12.05.
1. BOJ 15683
    - Algorithm
brute force 방법을 이용한 문제이다. 모든 CCTV 방향의 가능성을 모두 시뮬레이션 해봐야 되는 문제이다. 이 부분을 해결 하기 위해서 DFS 를 이용하여 풀어 보았다. 각 CCTV 5개 종류마다 감시하는 방향에 차이가 있고 회전할때마다 감시하는 방향 변화도 다르다. 이 부분은 if 문을 통해서 처리 하였다.

    - 실수
    1. 두번의 **틀렸습니다.** 가 있었다. 첫 번째는 3번 CCTV 의 회전할때마다 감시방향의 변화를 잘못 하였다. 몫과 나머지 연산을 통해서 해결 하였다.
    2. Data 입력 후 분류 하는 부분에서 실수가 있었다. 쉽게쉽게 if, else 문을 이용하였는데, **벽의 경우인 6** 에 예외처리를 잘못 하여서 else if 추가후 해결 하였다.

2. BOJ 14501
    - Algorithm
DP 를 이용한 문제였다. 난이도는 매우 쉬움. DP 입문정도로 생각하면 될거 같다. index 일에 상담을 안한다/한다 를 배열에 넣어서 문제를 풀었다. 상담을 한다면 index+t[index] 이후 날짜부터 다시 상담을 할 수 있고 안한다면 index+1 이후 날짜부터 상담을 진행 할 수 있다. 마지막날 부터 상담을 안할때와 할때 최대값을 각각 d 배열에 저장하면서 DP 를 적용시켰다.

## 18.12.04.
1. BOJ 14500
    - Algorithm
브루트 포스 문제? DFS 문제?? 두개 섞어 놓은 문제이다. 어떻게든 DFS 를 이용하여 중복없이 깔끔하게 코드를 하려 하다 보니 하루가 훌쩍 넘겼다. 그래서 검색을 해봤더니... DFS 를 쓰되, ㅗ 모양의 도형은 부루트 포스 방법을 이용하였다. 하지만 **맞았습니다** 를 받고도 의문이 생기는데 ... 분명히 중복이 있다. 이 부분때문에 시간초과가 나올거라 생각했는데 시간초과가 안나오니 참... 그래도 풀었다.

## 18.12.02.
1. BOJ 14499
    - Algorithm
시뮬레이션 문제였다. 세번의 실패가 있었는데 초기 주사위의 위치에서 막힌 문제였다. 문제를 잘 읽어보면.. x, y 로써 주사위의 초기 좌표를 주어졌었는데 이를 사용하지 않아서 생긴 문제가 이쪽저쪽 건들어 보면서 쓸데없는 시간 버렸다. 

    - something new
    1. 주사위 를 어떤식으로 저장해야되나? 그냥 2차원 배열에 저장한 후 주사위 이동( 동, 서, 남, 북 )에 따른 변화를 함수로 만들어 주었다. 완전 부루트 포스방법. 

## 18.11.29.
1. BOJ 13458
    - Algorithm
매우 쉬운 문제였다. 하지만 몇번의 **실패** 가 있었다. 원인을 곰곰히 생각해 보니 출력값이 매우 클 수 있다고 생각하였다. 그래서 출력값의 변수를 ~~int~~ 에서 **long long** 으로 바꾸어 주었더니 실행이 되었다.

    - Trap
문제의 함정이 있었다. 테스트 케이스는 위에서 언급한 부분을 테스트 해보지 못하였다. 만약 이러한 문제가 나왔을때 불 친절한 테스트 케이스들이 위와 같이 존재한다면 나는 쉬운문제 하나를 틀리게 되버린다. 그러니 한번쯤 생각해 보도록 하자.

## 18.11.28.
1. BOJ 3190
    - Algorithm
뱀의 몸통(?)을 snake 큐에 집어 넣어 이동하였을대 꼬리의 변화를 쉽게 추적할 수 있도록 하였다. 그리고 2차원 배열 map을 이용하여 뱀, 사과, 아무것도 없는 곳을 구분하여 처리하였다. 뱀의 방향 변화를 cmd 큐에 저장 하였는데... 큐를 사용하지 않아도 됬을거 같다. 하지만 큐 짱짱맨 배열에 현재 lock up 하는 index 의 정보를 저장하지 않아도, pop() 함수를 이용하여 쉽게 처리 할 수 있다.

    - timeless...
%(modular) 연산을 한다고 양수가 나오는건 아니다 히히...

## 18.11.22.
1. BOJ 13460
    - Algorithm
BFS 를 이용하여 문제를 풀었다. 문제를 보앗을때 느낌적으로  *뭘 써야겠다* 라는 것 보다 *이런 문제 유형에선 이런 알고리즘을써야지* 라고 생각하는 방법을 기르는게 좋을것 같다. 이번 문제도 최단 거리를 찾는다는 목표를 알아도 바로바로 BFS 알고리즘을 떠올리지 못하였다.

    - something new
    1. 기존의 **map** 문제와 달리 한칸씩 이동하는 것이 아니라 한 line 에서 막히기 전까지 이동하였다.
    2. 목적지에 도착하려는 물체에 대한 위치 값 뿐만 아니라 방해 요소까지 visit 배열에 입력하여 4차원 배열을 통해 풀어 보았다.

    - ref blog : http://jason9319.tistory.com/217

## 18.11.16.
1. BOJ 12781
    - Algorithm
CCW 라는 특성을 이용하여 문제를 풀었다. 거의 블로그를 보고 베낀 수준... 블로그는 코드파일에 주석달아 놓았다. 하지만 블로그 코드에서 오타를 발견하여 수정 후 '맞았습니다.'를 받을 수 있었다. **CCW** 를 이용하여 푸는 문제가 다른 문제가 있는걸로 파악 되었다. 그 문제는 스스로 풀어 보도록 해야겠다.

2. BOJ 11365
    - String.
String type 을 다루는 기초?? 거의 Hello world 수준의 기초를 하였다. getline 함수나 reverse 함수는 약간 쓸모가 있을거 같다. 하지만, reverse 함수는 algorithm header file 에 있어서 실제 코딩테스트에선 필요 없지 않을까 싶다.

3. BOJ 2902
    - String.
쉬우니까 패스.

## 18.11.15.
1. BOJ 2206
    - Algorithm
DFS 를 이용하여 풀었다. 노드를 방문할때, chance를 가지고 있는지, 아니면 사용 하였는지를 각각 계산하는 방법을 통해서 3차원 배열을 이용하여 풀 수 있었다. 

## 18.11.14.
1. BOJ 1890
    - 오랜만에 문제를 보았따. ㅎㅎ. 항상 코딩할때마다 드는 생각이지만 너무 어렵게 생각한다. 문제 해결에 있어서 쉽고 간편하게 해결하는게 목적인데 그 목적에서 많이 어긋나는 모습을 보였다.
    1. 그놈의 큐를 왜 사용하려고 하는지 모르겠다. 노드를 방문한 후 가능한 경로의 노드들을 큐에 담은 후 큐에서 빼내면서 서치를 하려고 생각하였다. 그렇게 하면 방문하는 노드의 수는 확실히 감소 하겠지만 훨씬 간단히 생각해보면 모든 맵을 한번씩 방문하도록 하여도 충분히 저렴하게 할 수 있었다.
    2. http://mygumi.tistory.com/198 마이구미씨의 코드를 확인 하였다. 조건문을 이용하여 불필요한 노드의 방문을 줄이는 작업을 새로운 배열을 이용하여 하였는데 매우 심플하다고 생각한다. 이러한 테크닉들을 자연스럽게 이용할 수 있어야 된다고 생각한다.

## 18.10.29.
1. BOJ 1890
    - algorithm category
백준 온라인 저지에서 dfs/bfs 분류에 속해 있는 문제이다. 그래서 dfs 를 이용해서 풀었는데 시간 초과가 나왔다. 검색 결과 DP 를 이용하여 문제를 해결해야 된다고 한다.

## 18.10.27.
1. BOJ 10216
    - data input part
초기화가 되게 오래 걸린다. map 의 사이즈를 주어주지 않기 때문에 최대값을 확인하고 그 최대값의 맵을 할당한 후 초기화를 진행 하였다.
    - my code
    ```
    int **map = new int*[5001];
        bool **visited = new bool*[5001];
        for (int i=0; i<5001; i++)
        {
            map[i] = new int[5001];
            visited[i] = new bool[5001];
            for (int j=0; j<5001; j++) 
            {
                map[i][j] = 0;
                visited[i][j] = false;
            }
        }
    ```
    - Union-Find Algorithm
처음보는 알고리즘이었다. a, b 가 있을때, a와 b 를 하나로 합치는(Union) 작업과 a를 주어졌을때, a가 속한 집단을 반환하는 작업을 할 수 있는 알고리즘이다. 이 문제를 풀때 굉장히 유용할 거라 생각된다. (참고:http://bowbowbow.tistory.com/26)
성공 하였다.

## 18.10.23.
1. BOJ 2667
    - Data input part
    - my code
    ```
    int tmp;
    cin >> tmp;
    for (int col=0; col<columns; col++)
        {
            map[row][col] = tmp % 10;
            tmp /= 10;
        }
    ...
    ```
    만약 tmp 가 int의 메모리 사이즈를 초과하였을 때를 생각보면 원하는 솔루션에 도달하지 못한다는것을 알 수 있다.

    - modified code
    ```
    for (int col=0; col<columns; col++)
    {
        scanf("%1d", &map[row][col]);
    }
    ```
    'cin' 의 편리함을 포기하고 한계점을 인정하며 더 나은 방법을 사용하였다. **cin.read** 를 사용하면 된다. 하지만 성능이 영... 안좋다는 평가가 있다.
