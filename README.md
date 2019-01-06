# Algorithm Think...

알고리즘 문제를 풀면서 깨달은 것들을 적어보자. 나중에 코딩테스트를 보러 갈 일이 있다면 한번씩 봐보도록. 다른사람들도 도움이 됬으면 좋겠다.

## 19.1.7. 월요일
1. BOJ 13171 **
- Alogirithm : Moduler 연산. 너무 어렵게 생각하려고 하였나? 싶지만, 내가 그냥 못한거 같다. 이 문제 다시 한번 봐봐야 겠다. 


## 19.1.6. 일요일
1. BOJ 1946
- Alogirithm : sorting 문제를 너무 구데기처럼 푼 경향이 없잖아 있다. 흠... 리뷰를 다시한번 해볼 필요가 있다.

## 19.1.4. 금요일
1. BOJ 1049
- Alogirithm : sorting.. 이 필요하나 싶다 최고값만 있으면 된다.

## 19.1.3. 목요일
1. BOJ 4307
- Alogirithm : sorting.. 살짝 생각이 필요하다. 개미가 부딫히면 서로 다시 반대방향으로 가게 되는데, 개미에 대한 구분이 없으면 이말은 통과하여 간다는것과 똑같다. 생각해보면 안다. 그러니 개미마다 짧은 구간과 긴 구간을 나누어 짧은 구간이 가장큰 개미의 값과 긴 구간이 가장 큰 개미의 값을 구하여 나타내었다.
- 잡담 : 그림첨부 하고 싶은데...

## 19.1.3. 목요일
1. BOJ 11399
- Alogirithm : sort... 

## 19.1.2. 수요일
1. BOJ 1931
- Algorithm : greedy algorithm
- 잡담
sort 하는 기존을 다르게 생각해보면 되게 빠른 시간에 해답을 추출 해 낼 수 있다. 처음에는 회의 시작시간을 기준으로 sort를 하였는데 참고 자료를 찾아보니 회의 종료 시간을 기준으로 sort를 하면 greedy Algorithm 을 쉽게 돌려서 해답을 찾을 수 있다.
- Ref. http://red-pulse.tistory.com/94

## 18.12.30. 일요일
1. BOJ 11047
- Algorithm : greedy algorithm (쉬움)

## 18.12.30. 일요일
1. BOJ 10773
- Algorithm : stack (쉬움)

## 18.12.30. 일요일
1. BOJ 9020
- Algorithm : 소수찾기 (쉬움)

## 18.12.30. 일요일
1. BOJ 9020
- Algorithm : 소수찾기 (에라토스테네스의 체)

## 18.12.29. 토요일
1. BOJ 2960
- Algorithm : 소수찾기 (에라토스테네스의 체)

## 18.12.29. 토요일
1. BOJ 4948
- Algorithm : 소수찾기

## 18.12.29. 토요일
1. BOJ 11650
- Algorithm : Sorting...
- Ref. https://dongyeollee.github.io/2018/03/04/Al/11650/
- Ref. https://www.acmicpc.net/blog/view/22
- 잡담
흠흠.. x 좌표를 비교하고~ y 좌표를 비교해서 두번 하려고 했었는데? STL 을 이용하면 쉽지 않을까 해서 찾아보았떠니 역시나 STL 짱


## 18.12.21. 금요일
1. BOJ 1181
- Algorithm : Linked list 를 만들었다. 좀 머리 쓰긴 했는데 STL 을 사용하는 방법을 익혀볼까 했는데 필요 없을듯 싶다. 

## 18.12.21. 금요일
1. BOJ 2108
- Algorithm : Count Sort 비스무리하게 사용하였다.
이 문제는 피드백이 필요할 거 같다.

## 18.12.21. 금요일
1. BOJ 10989
- Algorithm : Count Sort 라는 새로운 sort 방법이었다.
- 잡담 : 메모리초과가 계속 떳다. 이유는 쓸대없는 배열을 선언했기 때문이다. 고쳐서, 카운트 갯수만 저장한 다음에 그 저장된 갯수만큼 출력해주기만 하면 그런건 메모리초과는 뜨지 않았다.
- Ref. http://www.cs.miami.edu/home/burt/learning/Csc517.091/workbook/countingsort.html

## 18.12.17. 월요일
1. BOJ 1074
- Algorithm : 재귀, 분할 정복 문제 였다. 규칙을 찾는게 주 알고리즘 인거 같다. 어찌어찌 잘해서 잘되었다. 집중하고 햇으면 더 빨리 풀 수 있었을거 같다.


## 18.12.17. 월요일
1. BOJ 1436
- Algorithm : Brute force 문제이다. 숫자를 1씩 증가하며 조건에 만족하면 카운트를 하는 방법으로 실행해 보았다.
- 잡담
또또ㅗ또또또또또ㅗㅗ또또ㄸ 어렵게 생각하고 그른다... 그냥 바로 부루트 포스로 풀면 될텐데 규칙을 찾으려고 한다. 어? 좀 찾은거 같기도 하고 좀 그른다.
- ref. http://sunrinnote.tistory.com/96


## 18.12.17. 월요일
1. BOJ 1018
- Algorithm : Brute force 시뮬레이션 문제이다.
- Mistake : 문제에서 map 을 char[][] 로 받아 왔다. 최대 길이가 50 이라고 하여서 char[50][50] 을 하였으나... string 성격상 size 를 **51** 을 해야지 오버플로우 관련 문제가 발생하지 않는다.


## 18.12.10. 월요일
1. BOJ 2981
- Algorithm : 최대공약수(GCD) 를 이용하여 풀기. 수학문제.

- 할말
수학문제이다. GCD 의 성질을 이용한 문제였다. 문제에 대한 이해는 어느정도 된거 같다. 솔루션을 검색해보았는데 vector 과 interator 를 이용하는 방법에 대해서 공부해 볼 필요가 있다고 생각한다. 몇 가지 메소드를 이용한다면 굉장히 쉽게 문제를 풀 수 있었다. 하지만... 코딩테스트에서 STL 를 사용 못하게 한다면...? sort 같은거 불편해서 어떻게 행 ㅜㅜ

## 18.12.10. 월요일
1. BOJ 15686
- Algorithm
또 시뮬레이션 문제이다. 삼성은 시뮬레이션 문제를 좋아하나 부다. DFS + Back Tracking 문제이다. 이거 비슷한 문제가... 있었는데, 이 문제 역시 애먹었다.
    1. 경우를 추출
    M개의 가게이 선택되는 **경우** 알고리즘을 돌려야 된다. 이 경우를 만들기 위해선 DFS 를 이용하여 모든 index 의 가게을 순서대로 순회 하면서 선택 -> DFS Func / 비선택 -> DFS Func 를 하는 방법을 이용하였다. 처음엔 BFS 를 이용하여 각 가정마다 가장 가까운 가계를 찾는 방법에 대해서 초점을 맞춰 문제를 풀어 보았는데 너무... 돌아갔나 싶다. 만약 시간이 있따면 이 방법을 이용해서 푸는것도 좋을거라 생각된다.

- Ref. http://wjdgus2951.tistory.com/99

## 18.12.10. 월요일
1. BOJ 15685
- Algorithm
시뮬레이션 문제이다. map 배열이 포에서 주어진거랑 다른개념으로 생각하여야 된다... 안그래서 엄청 오래 걸렸다.

- Talk...
이거 저번에 인턴 시험갔을 때 풀었떤 문제이댜.. 그땐 잘풀었는데 왜 못하겠지?? ㅜㅜㅜㅜ


## 18.12.07. 금요일
1. BOJ 15684
- Algorithm
시뮬레이션 문제 답게 Brute Force 문제이다. DFS 를 이용하여 시뮬레이션을 돌려 보았다.

- Incorrect
    1. Time complexity
    사실 ~~시간 초과~~ 가 나왓다는게 아니다. 문제에 부합하는 조건에 맞는지 틀리는지 확인하는 알고리즘을 짜는데 너무 Time complexity 를 고려하다보니 간단한 문제를 어렵게 생각하는 경향이 있다. 그 부분에서 시간이 많이 잡아 먹었다. **일단 하자!**
    2. Map define
    주어진 사다리를 2차원 배열에 넣고, 초기화 하는 과정에서 몇가지 생각을 해보았다. 가로선 을 기준으로 H 개 행과 N-1 개의 열이 있는 2차원 bool 배열을 만들어서 연결되어 있으면 (실선) True, 연결되어 있지 않으면(점선) False 로 표기하는게 첫번째 방법이고, 두번째 방법은 H행, N열로 각열은 세로선을 타나내며 i 행, j 열의 값이 1이면 오른쪽으로 실선, -1 이면 왼쪽으로 실선, 0이면 선이 없다는 배열을 만들었다. chk 함수를 돌리기에 편했다. 하지만 그냥 문제에 주어진대로 간단하게 생각하는게 좋았다. 검사할대 if 문 한번만 더쓰기만 하면된다.

- Ref. http://mini-ko.tistory.com/11

## 18.12.05. 수요일
1. BOJ 15683
- Algorithm
brute force 방법을 이용한 문제이다. 모든 CCTV 방향의 가능성을 모두 시뮬레이션 해봐야 되는 문제이다. 이 부분을 해결 하기 위해서 DFS 를 이용하여 풀어 보았다. 각 CCTV 5개 종류마다 감시하는 방향에 차이가 있고 회전할때마다 감시하는 방향 변화도 다르다. 이 부분은 if 문을 통해서 처리 하였다.

- 실수
    1. 두번의 **틀렸습니다.** 가 있었다. 첫 번째는 3번 CCTV 의 회전할때마다 감시방향의 변화를 잘못 하였다. 몫과 나머지 연산을 통해서 해결 하였다.
    2. Data 입력 후 분류 하는 부분에서 실수가 있었다. 쉽게쉽게 if, else 문을 이용하였는데, **벽의 경우인 6** 에 예외처리를 잘못 하여서 else if 추가후 해결 하였다.

## 18.12.05. 수요일
1. BOJ 14501
- Algorithm
DP 를 이용한 문제였다. 난이도는 매우 쉬움. DP 입문정도로 생각하면 될거 같다. index 일에 상담을 안한다/한다 를 배열에 넣어서 문제를 풀었다. 상담을 한다면 index+t[index] 이후 날짜부터 다시 상담을 할 수 있고 안한다면 index+1 이후 날짜부터 상담을 진행 할 수 있다. 마지막날 부터 상담을 안할때와 할때 최대값을 각각 d 배열에 저장하면서 DP 를 적용시켰다.

## 18.12.04. 화요일
1. BOJ 14500
- Algorithm
브루트 포스 문제? DFS 문제?? 두개 섞어 놓은 문제이다. 어떻게든 DFS 를 이용하여 중복없이 깔끔하게 코드를 하려 하다 보니 하루가 훌쩍 넘겼다. 그래서 검색을 해봤더니... DFS 를 쓰되, ㅗ 모양의 도형은 부루트 포스 방법을 이용하였다. 하지만 **맞았습니다** 를 받고도 의문이 생기는데 ... 분명히 중복이 있다. 이 부분때문에 시간초과가 나올거라 생각했는데 시간초과가 안나오니 참... 그래도 풀었다.

## 18.12.02. 일요일
1. BOJ 14499
- Algorithm
시뮬레이션 문제였다. 세번의 실패가 있었는데 초기 주사위의 위치에서 막힌 문제였다. 문제를 잘 읽어보면.. x, y 로써 주사위의 초기 좌표를 주어졌었는데 이를 사용하지 않아서 생긴 문제가 이쪽저쪽 건들어 보면서 쓸데없는 시간 버렸다. 

- something new
    1. 주사위 를 어떤식으로 저장해야되나? 그냥 2차원 배열에 저장한 후 주사위 이동( 동, 서, 남, 북 )에 따른 변화를 함수로 만들어 주었다. 완전 부루트 포스방법. 

## 18.11.29. 목요일
1. BOJ 13458
- Algorithm
매우 쉬운 문제였다. 하지만 몇번의 **실패** 가 있었다. 원인을 곰곰히 생각해 보니 출력값이 매우 클 수 있다고 생각하였다. 그래서 출력값의 변수를 ~~int~~ 에서 **long long** 으로 바꾸어 주었더니 실행이 되었다.

- Trap
문제의 함정이 있었다. 테스트 케이스는 위에서 언급한 부분을 테스트 해보지 못하였다. 만약 이러한 문제가 나왔을때 불 친절한 테스트 케이스들이 위와 같이 존재한다면 나는 쉬운문제 하나를 틀리게 되버린다. 그러니 한번쯤 생각해 보도록 하자.

## 18.11.28. 수요일
1. BOJ 3190
- Algorithm
뱀의 몸통(?)을 snake 큐에 집어 넣어 이동하였을대 꼬리의 변화를 쉽게 추적할 수 있도록 하였다. 그리고 2차원 배열 map을 이용하여 뱀, 사과, 아무것도 없는 곳을 구분하여 처리하였다. 뱀의 방향 변화를 cmd 큐에 저장 하였는데... 큐를 사용하지 않아도 됬을거 같다. 하지만 큐 짱짱맨 배열에 현재 lock up 하는 index 의 정보를 저장하지 않아도, pop() 함수를 이용하여 쉽게 처리 할 수 있다.

- timeless...
%(modular) 연산을 한다고 양수가 나오는건 아니다 히히...

## 18.11.22. 목요일
1. BOJ 13460
- Algorithm
BFS 를 이용하여 문제를 풀었다. 문제를 보앗을때 느낌적으로  *뭘 써야겠다* 라는 것 보다 *이런 문제 유형에선 이런 알고리즘을써야지* 라고 생각하는 방법을 기르는게 좋을것 같다. 이번 문제도 최단 거리를 찾는다는 목표를 알아도 바로바로 BFS 알고리즘을 떠올리지 못하였다.

- something new
    1. 기존의 **map** 문제와 달리 한칸씩 이동하는 것이 아니라 한 line 에서 막히기 전까지 이동하였다.
    2. 목적지에 도착하려는 물체에 대한 위치 값 뿐만 아니라 방해 요소까지 visit 배열에 입력하여 4차원 배열을 통해 풀어 보았다.

- ref blog : http://jason9319.tistory.com/217

## 18.11.16. 금요일
1. BOJ 12781
- Algorithm
CCW 라는 특성을 이용하여 문제를 풀었다. 거의 블로그를 보고 베낀 수준... 블로그는 코드파일에 주석달아 놓았다. 하지만 블로그 코드에서 오타를 발견하여 수정 후 '맞았습니다.'를 받을 수 있었다. **CCW** 를 이용하여 푸는 문제가 다른 문제가 있는걸로 파악 되었다. 그 문제는 스스로 풀어 보도록 해야겠다.

2. BOJ 11365
- String.
String type 을 다루는 기초?? 거의 Hello world 수준의 기초를 하였다. getline 함수나 reverse 함수는 약간 쓸모가 있을거 같다. 하지만, reverse 함수는 algorithm header file 에 있어서 실제 코딩테스트에선 필요 없지 않을까 싶다.

3. BOJ 2902
- String.
쉬우니까 패스.

## 18.11.15. 목요일
1. BOJ 2206
- Algorithm
DFS 를 이용하여 풀었다. 노드를 방문할때, chance를 가지고 있는지, 아니면 사용 하였는지를 각각 계산하는 방법을 통해서 3차원 배열을 이용하여 풀 수 있었다. 

## 18.11.14. 수요일
1. BOJ 1890
- 오랜만에 문제를 보았따. ㅎㅎ. 항상 코딩할때마다 드는 생각이지만 너무 어렵게 생각한다. 문제 해결에 있어서 쉽고 간편하게 해결하는게 목적인데 그 목적에서 많이 어긋나는 모습을 보였다.
    1. 그놈의 큐를 왜 사용하려고 하는지 모르겠다. 노드를 방문한 후 가능한 경로의 노드들을 큐에 담은 후 큐에서 빼내면서 서치를 하려고 생각하였다. 그렇게 하면 방문하는 노드의 수는 확실히 감소 하겠지만 훨씬 간단히 생각해보면 모든 맵을 한번씩 방문하도록 하여도 충분히 저렴하게 할 수 있었다.
    2. http://mygumi.tistory.com/198 마이구미씨의 코드를 확인 하였다. 조건문을 이용하여 불필요한 노드의 방문을 줄이는 작업을 새로운 배열을 이용하여 하였는데 매우 심플하다고 생각한다. 이러한 테크닉들을 자연스럽게 이용할 수 있어야 된다고 생각한다.

## 18.10.29. 월요일
1. BOJ 1890
- algorithm category
백준 온라인 저지에서 dfs/bfs 분류에 속해 있는 문제이다. 그래서 dfs 를 이용해서 풀었는데 시간 초과가 나왔다. 검색 결과 DP 를 이용하여 문제를 해결해야 된다고 한다.

## 18.10.27. 토요일
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

## 18.10.23. 화요일
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
