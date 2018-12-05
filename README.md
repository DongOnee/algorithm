# Algorithm Think...

알고리즘 문제를 풀면서 깨달은 것들을 적어보자. 나중에 코딩테스트를 보러 갈 일이 있다면 한번씩 봐보도록. 다른사람들도 도움이 됬으면 좋겠다.

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
