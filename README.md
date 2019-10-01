# Algorithm Think...

알고리즘 문제를 풀면서 깨달은 것들을 적어보자. 나중에 코딩테스트를 보러 갈 일이 있다면 한번씩 봐보도록. 다른사람들도 도움이 됬으면 좋겠다. 코드에 관한 소통은 얼마든지 환영합니다. 제발요

## 19.10.1.
1. BOJ 9372
    - Algorithm : Union-Find
    - Talk : 문제를 잘 보면 ~~비행기 이용횟수~~ 가 아니라 **이용한 비행기 종류 수** 로 되어있다. 비행기가 아무리 싫어도 A-B 왕복 1000000만번 해도 구하고자 하는 값은 +1 밖에 되지 않는다. 왜냐하면 이용한 비행기가 한 종류이기 때문이다. 이 점을 생각해서 Union-Find 알고리즘을 이용해서 풀 수 있었다.

## 19.10.1.
1. BOJ 1197
    - Algorithm : 신장트리 / Spanning Tree / Minimum Spanning Tree
    - Talk : 스패닝 트리에 대해서 생소했는데 좀 알거 같기도 하고 아직 부족한것 같기도 하고 애매하다. 애매할때 가장 어려운 상태니까 이참에 한번 정리하고 문제 풀기로 해보자. 먼저 github 위키를 작성하고, 문제를 여러개 풀어보도록하자.
    - ISSUE
        - 문제를 푸는 두가지 방법이 있다는것을 알았다.
        - Prim Algorithm :  스스로 생각해서 푼 방법과 프림 알고리즘과 굉장히 유사하다. 하나의 시작 정점으로부터 시작되는 간선을 모두 우선순위 큐에 넣고 뻗어 나가며 도착한 정점에서의 연결 간선들을 우선순위 큐에 넣는 방식이다.
        - Kruskal Algorithm : 모든 간선들을 정렬하여 가장 작은것부터 하나씩 활성화 시키면서 트리를 만들어 가는 식이다. Union-Find 알고리즘을 이용한다. Kruscal 과 Union-find 알고리즘의 포함범위가 어떻게 되는지 궁금하다.
        - 1197_kruskal.cpp 와 1197_kruskal_2.cpp 코드의 차이는 거의 없다. vector 을 이용하였는지 아니면 전역 변수에 미리 할당 시켜놓는지 차이이다.

## 19.9.30.
1. BOJ 2589
    - Algorithm : BFS
    - Talk : BFS 를 이용하는것은 이해하였다. 하지만 모든점에서 BFS 를 하게되면 너무 필요없는 일이 일어나지 않지 않나? 예를 들어보자
        - `LLLLL` 같은 맵이 있으면 `{0, 0}` 에서 `{0, 4}` 가 답이라 `{0, 0}` 에서 BFS 를 하면 답을 구할 수 있다. 하지만 모든 점에서 BFS 를 하게 되면 `{0, 1}, {0, 2}, {0, 3}, {0, 4}`모든 점에서 BFS를 하게 되니까 시간이 오래 걸릴거라 생각을 했다.
        - fail/2589.cpp 코드를 보면 BFS 를 두번 사용함을 알 수있다. 처음엔 아무점에서 BFS 를 한다음에 가장 멀리 떨어져 있는 점들에서 BFS 함수를 하는 식이다. 위의 예를 들면 `{0, 0}`에서 BFS 를 하면 `{0, 4}` 가 가장 멀리 떨어져 있는 점이라는걸 알 수 있다. 그 이후 `{0, 4}` 에서  BFS 를 하면 가장 먼점을 구할 수 있지 않을까.... 생각을 했다. 왜 틀렸는지는 반례를 못찾겠다.
        

## 19.9.29.
1. BOJ 2644
    - Algorithm : BFS
    - Talk : 맨처음에는 단일방향 트리를 구성해야되나 싶었는데, 그럴 필요가 없었다. 부모->자식, 자식->부모 두 경우 모두 count 를 1씩 늘리기대문에 상관이 없었다. 그래서 양방향 트리를 구성해서 풀었다.
    - EZ

## 19.9.29.
1. BOJ 10026
    - Algorithm : BFS
    - Talk : BFS에 약간의 아이디어를 섞어서 푸는 문제이다. 적록 색약인 경우와 아닌경우를 나눠서 완전탐색 2번을 요구하는 문제가 아니라고 생각하여 완전 탐색 한번에 두경우 모두를 해결 할 수 있는 방안을 생각해 보았다.
        1. RGB 구간단위로 BFS 하여 `ans1` 변수에 저장.
        2. 적록 색약인 경우 BFS 함수 안에서 `qu2` 에 저장하는것을 통해서 처리.
        3. `ans2` 변수를 이용하여 적록 색약인 경우 인접한 색상의 BFS 횟수를 카운트
        4. `visited` 를 활용하는건 한번의 BFS 함수 안에서 변화만 체크해야됨 -> 초기화 -> map 변수를 `0`으로 변환?
        5. 설명하기 너무 어렵다...

## 19.9.24.
1. BOJ 10775
    - Algorithm : Union-Find
    - Talk. : Union-Find 알고리즘 사용에 대해서 좋은 문제인것 같다.
    - challenge
        - 10775.cpp : 1 ~ g 까지 게이트가 준비 되어있고 (vector 에 저장) 첫 번째 비행기부터 입력 받은 숫자에 대해서 제일 큰 숫자에 해당하는 게이트에 도킹한다고 하자. 예를 들면 4가 들어오면 4에 도킹하는 식이다. 이렇게 도킹을 하게 되면 itrator 를 이용하여 vector 에서 erase 하면 도킹 가능한 게이트에서 4가 지워지는것이다. 이 다음 인풋이 들어오게 되면 4는 없으니 3에 도킹하게 만들어야된다. 이를 위해서 **역순으로 저장**하고 **lower_bound**를 이용하였다. **맞았습니다.** 는 받았지만 다른것들과 비교해보았을때 시간이 엄청 오래 걸린다.
            - `vector<int>::erase` 를 이용할때 `O(n)` 의 시간이 걸려서 그런것 같다. 인풋 사이즈가 늘어나게 되면 시간이 엄청 오래 걸리게 된다.
        - 10775_2.cpp : 위 문제를 해결하기 위해 ~~vector~~를 사용하지 않고 **list** 를 이용해 보았는데 **시간초과** 가 나온다.
            - 원인은 **lower_bound** 를 하게 되면 mid 값을 구해야되는데 Random Access 가 되지 않기 때문에 이 부분에서 시간이 오래 걸리는것 같다.
        - 10775_3.cpp : Union-Find 알고리즘을 적극 이용해 보았다. `par[100001]` 를 이용하여 0~g 까지 채워 넣는다. 만약 4가 들어오게 되면, `par[4]` 와 비교하여 `4` 이면 도킹 후 `par[par[4]] = par[par[4]-1]` 를 해주는 식으로 진행 하였다.
            - findFunc(input) : input 보다 같거나 작은 도킹되지 않은 게이트 
            - UnionFunc(input) : findFunc(input)으로 구한 게이트가 없으면(0이면) true 를 반환하고, 아니면 input의 게이트를 input-1 의 게이트와 같게 만든다.

## 19.9.24.
1. BOJ 4195
    - Algorithm : Union-Find
    - Talk. : **Union-Find** 알고리즘에 대해서 공부해야겠다라는 생각이 있었는데 이번 문제를 통해서 조금은 알게 되었다. 개념 설명은 나중에 시간 내서 해야겠다. 다이어리에 날짜를 잡고 GitHub에 Algorithm repository 에 WIKI 에 올려야겠다.
    - ISSUE
        - fail/4195.cpp 파일을 보면 큐를 이용하여 BFS 알고리즘을 이용한 흔적이 보일것이다. 결과는 당연히 **시간 초과**. 아마도 이전에 했던 작업을 한번더 하기 때문에 완전 탐색 NlogN 시간이 N 만큼 더걸리게 되니 당연히 시간초과가 날것이다. 그래서 방법을 바꾸어 보았다.
        - 4195.cpp 파일에서 가장큰 차이점은 `idxGroup` 과 `idxConnectedGroup` 을 두었다. 그래서 idx 에 해당하는 친구가 속한 그룹은 `idxGroup[idx]` 이고 idxGrp 에 해당하는 그룹의 부모 그룹은 `idxConnectedGroup[idxGrp]` 이 된다. 
        ```c++
        for (int i=0; i<2; i++)
            if (idxGroup[idxs[i]] != -1)
                while (idxConnectedGroup[idxGroup[idxs[i]]] != -1) 
                    idxGroup[idxs[i]] = idxConnectedGroup[idxGroup[idxs[i]]];
        ```
        - 30 ~ 33 라인을 보면 `idxConnectedGroup` 을 이용해서 `idxGroup` 을 최상위로 바꾸어 놓는다. 그렇게 하면 속한 그룹을 찾는 과정 (find) 가 쉽게 이뤄진다.
        - 하지만 계속 해서 틀렸습니다가 나오는데 문제를 찾아보니 사이클이 있으면 오류가 나온다. 코드위 59 번재 줄에 `if (idxGroup[idxs[0]] == idxGroup[idxs[1]]) return cntGroup[idxGroup[idxs[0]]];` 를 추가하여 해결 하였다.
        - 다른 솔루션들도 추가해 보았다. Union-find  알고리즘을 더욱 쉽게 구현하였다.
        - 정답자등 중 시간을 굉장히 효율적으로 사용한 사람들이 있는데 공통점은 hash_map 을 직접 구현하였다는 것이다.
        - 혹시 map 의 order 하는 것때문에 시간이 늦는거라면..? -> unordered_map 을 이용해보았더니 시간이 단축 되었다.

## 19.9.20.
1. BOJ 2523
    - Algorithm : 위상정렬
    - Talk. : 쉬운 문제... 하지만 문제 잘못읽어서 삽질...

## 19.9.20.
1. BOJ 1005
    - Algorithm : 위상정렬
    - Talk. : 비교적 쉬운 문제이다. 하지만 왜 시간이 오래 걸리는것일까...

## 19.9.19.
1. BOJ 2213
    - Algorithm : DFS
    - Talk. : 문제에 좀 뭐지...? 싶은게 있었는데 `문제는 일반적인 그래프가 아니라 트리(연결되어 있고 사이클이 없는 그래프)와 각 정점의 가중치가 양의 정수로 주어져 있을 때, 최대 독립 집합을 구하는 것이다.` 라는 말이 있어서 DFS 로 풀면 되겠구나 싶었다. DFS 로 완전 탐색을 하면서 DP 를 이용하여 방문 노드를 집합에 넣을때, 안넣을떄 를 구분하고 그때의 리프부터 path들?? 순서는 상관없이 방문한 노드, 그러니까 집합에 포함한 노드들을 담아 준다.

## 19.9.19.
1. BOJ 2252
    - Algorithm : 위상 정렬
    - Talk. : EZ

## 19.9.19.
1. BOJ 13325
    - Algorithm : Tree
    - Talk. : 저번에 풀어 본 문제 같다. 쉽게 풀었다.
        - 메모리 : 메모리를 줄일 수 있었다. 반복문 안에서 루프마다 변수 하나를 생성하는것을 반복문 밖에서 생성한 후 계산을 통해 변화주는 방식으로 바꾸니까 메모리를 절약 할 수 있엇다.
        - 시간 : 이건 왜 100ms 대가 안나오는지 모르겠다... ㅜㅜ

## 19.9.19.
1. BOJ 2263
    - Algorithm : Tree, Preorder
    - Talk. : 이 문제가 뭐라고 오래 걸렸다. 저번에 에스원에서 아르바이트 하면서 물었던 문제인거 같기도 하고... 그른데 이번엔 오전 오후 시간 다써서 풀엇으니 오래 걸렸지. 머리속이 리프레쉬가 안된당..
    - ISSUE : 두번의 **맞았습니다.** 를 받았는데 첫번째는 말도 안되게 시간이 오래 걸린다. Post-Order 의 특징을 100%활용하지 못했던 점에서 시간이 오래 걸린것이었다.
        - In-Order : `Left SubTree` `Root` `Right SubTree` 로 되어 있어, `Root` 를 구하게 되면 두개의 서브트리를 구분 지을 수 있다.
        - Post-Order : `Left SubTree` `Right SubTree` `Root` 로 되어 있어, 트리를 주어졌을때 `Root` 를 구할 수 있다.
        - 이 두가지 특성을 이용하여 post-order 를 이용해 `root`를 구하고 `root`를 이용해 두개의 `Sub Tree`를 구하여 재귀함수로 풀어서 답을 구할 수 있었다.

## 19.9.19.
1. BOJ 14226
    - Algorithm : BFS
    - Talk. : 무엇을 저장할지 해놓으면 쉽게 풀 수 있었다. `{화면에 있는 이모티콘 수, 클립보드에 있는 이모티콘 수}` 를 저장해 놓고 BFS 를 돌리면 된다.
    - ISSUE : 세그먼트.... 

## 19.9.18 ~ 19.
1. BOJ 2250
    - Algorithm : DFS
    - ISSUE. : `vector<vector<int>> vt` 를 선언하고 `vt.resize(10001)` 정도의 크기로 `resize()` 하면 런타임 에러가 난다... 이유는 나도 모르겠다. `vector<int> vt[10001]`로 하고 실행 하니까 된다

## 19.9.18.
1. BOJ 1967
    - Algorithm : DFS
    - Talk. : 이전과 같은 문제이다. 하지만 다르게 풀어보았다. 힙 자료구조를 이용하는게 오버 테스크 같아서 찾아보니 DFS, BFS 같은 간단한 완전 탐색을 이용하여 해결 할 수 있었다.

## 19.9.18.
1. BOJ 1167
    - Algorithm : Dijkstra 두번!
    - Talk. : Tree 에서 지름을 구한다. 고민을 해봤는데 트리에서 각 노드들까지 가는 길은 최소밖에 없다? 그러니까 여러가지 길이 있어서 비교하는 경우가 없다는 것이다. 그 생각이 안들었어서 힙 구조 만들때 살짝 착오가 있었다. 이 문제 SWEA에서 풀었던 기억이 있는것 같다. 지름의 길이가 가장 길게 되려면 루트에서 가장 긴 노드 두개를 찾으면 된다. 그래프에서 아무점이나 잡고 가장 멀리 떨어진 노드를 구하면 그 노드는 분명 우리가 구해야될 길이를 가지고 있는 두 노드중 하나이다. 띵킹 해보면 알것이다... 그래서 아무점(나는 1번 노드를 잡았다) 이나 잡고 다익스트라 한번 돌리고 한번더 돌리면 된다.

## 19.9.18.
1. BOJ 4963
    - Algorithm : BFS
    - Talk. : 간단한 BFS 문제였다. 가로 세로 크기에 대해서 잘못 적용시켜놨어서 한번 틀렸다.
    - ISSUE : cstdio 랑 string.h 같이 쓰니까 printf 가 ambiguous 한 표현이라고 떳다. string.h 를 csting 으로 고치니까 해결되었다.

## 19.9.17.
1. BOJ 16986
    - Algorithm : BFS
    - Talk. : 문제를 잘못 이해한줄 알고 바꿨다가 잘 이해한게 맞구나 싶어서 다시 바꾸었다. 주어진 경희, 민호가 내는 손동작의 순서는 라운드별 내는게 아니라 독립적으로 순서대로 내는것이다. 예를 들어 경희가 1라운드에서 1번째 손동작을 내서 진경우 2라운드를 쉬게 된다. 이후 3라운드에서 ~3번째~ 손동작을 내는것이 아니라 **2번째** 손동작을 낸다.

## 19.9.3.
1. BOJ 1219
    - Algorithm : Bellman-Ford & Floyd-Warshall (BFS)
    - Talk. : 이 문제도 음의 가중치를 가지고 있고, 음의 사이클을 찾는 문제이다. 다른점이라면 목표점이 주어져 그 목표점이 사이클에 영향을 받는지 안받는지 판단해야된다는 점이다.
    - Challenge.
        - 2차원 vector을 이용하지 않고 vector 안에 {{ 시작점, 목표점}, 가중치 } 를 넣어서 하니 한결 편했다. 이렇게 하는 점이 다익스트라 알고리즘과 다른점이라고 생각한다. Edge 그 자체가 중요하지 어디서 시작하는 Edge 인지는 분류할 필요가 없다. 
        - 자꾸 **틀렸습니다.** 가 나오길래... 예외 상황을 생각해보았다.
        - ![image](https://user-images.githubusercontent.com/26381225/64145163-8bd2d100-ce52-11e9-921c-00cd5c4e29e6.png)
        - 위 그림에서 **A 점을 시작점 E 점을 도착점**이라고 했을때 벨만-포드 알고리즘을 이용하면 B - C - D 에서 써클이 있다는것을 발견할 수 있지만, 그게 **E 에 영향을 주는지에 대해선 알수 없다.**
        - 따라서 플로이드-와샬 알고리즘을 이용해서 연결성에 대해 저장해놓고 서클이 일어난 점들이 E(목표점) 과 연결성이 있는지 확인해보면 E 가 무한이 변하는지 알 수 있다. (플로이드 와샬을 사용하지 않고 BFS 를 이용한 방법도 있더라.)

## 19.9.2.
1. SWEA 10217
    - Algorithm : Dijstra & DP
    - Talk. : 다익스트라 알고리즘과 다이나믹 알고리즘을 모두 이용하여 풀수 있는 문제이다. 굉장히 좋은 문제이다.
    - Challenge.
        - 문제에 대한건 아니지만.. pq 를 만들때 비교함수를 만들어서 해보았더니 시간이 굉장히 오래 걸렸다. 그 점을 보완하기 위해 다른사람의 코드를 보니 음수로 변환하여 따로 함수를 만들지 않고 구현 하였다. 그걸 참고하여 코드를 좀 바꾸니 효율성이 늘었다.
        - **요약 우선순위 큐만들때 -(마이너스)를 잘 활용하자**

## 19.9.2.
1. SWEA 1865
    - Algorithm : Bellman Ford Algorithm
    - Talk. : 음의 가중치를 가지고 있다. 딱 떠오르는 알고리즘은 벨만-포드 알고리즘이었다. 문제를 해석해보면 벨만포드를 이용하여 음의 사이클이 있는지 없는지를 찾는 문제이다. 
    - Challenge
        - 갑자기 벨만포드 알고리즘 구현 방법이 생각이 안났다. 머리속은 온통 다익스트라밖에 없어서... 결국 전에 github wiki 에 올려뒀던걸 참고하였다. 
    - Issue.
        - 문제를 해석한 결과 음의 사이클을 찾기 위해선, 모든 점에서 시작하는 경우를 모두 탐색해봐야 된다. 하지만 코드작성은 1번(index 로는 0번) 지점부터만 탐색을 하는 경우를 구현하였고 코드를 제출 하였는데 **맞았습니다** 가 나왔다.
        - ![image](https://user-images.githubusercontent.com/26381225/64095002-8913a580-cd98-11e9-8393-df3e773c81e8.png)
        - 위 사진에서 시작점이 a 인 경우는 음의 사이클을 찾을 수 있지만, f 인 경우에는 음의 사이클을 찾을 수 없다.
        - slack 에 물어봤더니 논란이 되었던 문제라더라~

## 19.8.27.
1. SWEA 2293
    - Algorithm : DP
    - Talk. : 여러개의 동전이 있다. 첫번째부터 마지막번째까지 ... 이것만 넣으면? 이라고 생각했다. 예를 들면, 1번째 동전으로만 만들수 있는 가치들의 합을 DP 에 저장 -> 기존에 있떤 DP에다가 2번째 동전을 이용하여 만들수 있는 가치들의 합 DP에저장 -> 3... ....~ 이런식으로 하면 모든 조합을 만들 수 있었다.

## 19.8.27.
1. SWEA 2163
    - Algorithm : MATH
    - Talk. : EZ

## 19.8.27.
1. SWEA 1932
    - Algorithm : DP
    - Talk. : EZ

## 19.8.26.
1. SWEA 12865
    - Algorithm : DP
    - Talk. : DP 문제에 사고를 좀 바꾸는 문제인거 같다. DP 문제중 좋다고 생각된ㄴ다. 이걸 생각하고 다른문제 풀수 있으면 좋을듯!

## 19.8.26.
1. SWEA 4112
    - Algorithm : 수학
    - Talk. : 좀 집중해서 수식구하고 조건문 쓰면 금방끝났을텐데....

## 19.8.25.
1. SWEA 7730
    - Algorithm : 이분탐색
    - Talk. : 이전에 백준에서 풀어본 문제이다. 그땐 굉장히 많이 헤메고 변수설정에 어려움이 있었는데 지금은 좀 수훨히 풀었따.

## 19.8.12.
1. SWEA 7991
    - Algorithm : 시뮬레이션..
    - 너무 어려웠따. 규칙을 잘생각하면 묶음으로 이동할 필요가 없다.
    - 예를 들면 `1 2 2 4 4` 일때 ~~`1 4 4 2 2`~~ 로 이동하는게 아닌 `1 4 2 2 4` 로 만들 어야된다.
    - 그리고 `1 1 1 2 2 2` 이런경우.. 1차이가 나고 마지막에 열린결말일때 컨트롤 하는게 뇌를좀 써야된다!

## 19.8.10.
1. Samsung Advenced
    - Algorithm : BFS
    - Talk. : 문제는 잘 기억안나지만... 7자리 숫자, 각 자릿수들은 서로 다름, A 구역 B 구역 나눠서 (몫, 나머지) A-B 값이 K 가 되게 만들어야됨. 초기 값 N 과 K 는 주어짐, 규칙 이 주어지는데 서로 붙어 있는 2수를 빼서 원하는 곳에 꼽아 넣을 수 있음. 규칙 한번 실행하면 count +1 시킴.
    - 문제풀때 수학문제인줄알고 접근했으나.. 사람들이 많이들 나가시는것을 보고 BFS 로 바꿔풀었다.
    - 실수는 역시 큐를 비워주지 않아서 문제가 되었따..

## 19.8.8.
1. BOJ 2133
    - Algorithm : DP
    - Talk. : 규칙을찾았따!
      - dp[i].first  : 길이가 i*2 이고 오른쪽 끝이 세로 블럭으로 막혀 있는 갯수
      - dp[i].second : 길이가 i*2 이고 오른쪽 끝이 가로블록 3개 쌓은것으로 막혀 있는 갯수
      - 로 정의 할 수 있다. 오른쪽 끝이 세로 블럭으로 막혀 있는 상황이라면 dp[i+1] 을 구할때 그 세로 블럭을 가로블럭 2개로 바꾼 다음에 남은 곳을 채울수 있다. 그럼 만들어진 모양에서도 오른쪽 끝이 세로블럭으로 막혀 있게 된다.
      - ||  이라고 한다면   |==| 으로 만들수 있다는 말이다~
      - ㅡ                 ㅡㅡ 
      - 결국 점화식을 세우면
      - dp[i+1].first  = 2 * (dp[i].first + dp[i].second) + dp[i.first]
      - dp[i+1].second = dp[i].first + dp[i].second
      - 가 된다!

## 19.8.8.
1. BOJ 2896
    - Algorithm : math
    - EZ

## 19.8.8.
1. BOJ 1002
    - Algorithm : math
    - EZ

## 19.8.8.
1. BOJ 1934
    - Algorithm : GCD
    - EZ

## 19.8.8.
1. BOJ 5639
    - Algorithm : Binary Tree
    - Talk.
      - index 접근으로 left, right, parent 노드에 접근 할 수 있다. root node 를 인덱스 1이라고 하였을때, i 인덱스의 노드의 left 는 `2*i` 인덱스고 right 는 `2*i+1` 인덱스고 parent 노드의 인덱스는 `|n/2|` 이다. 이 방법으로 한다면 문제가 생긴다. 극단적으로 한방향으로 기울어져 있는 트리가 온다면 전역변수에 만들어 놓을 배열의 크기가 엄청 커야된다.
      - 또한 tree 에  insert node 할때도 문제가 된다. 현재 부모노드를 저장해 놓은다음 생성한 노드를 트리에 저장할때 까다롭다. 관련 코드는 fail 폴더에 만들었다.
      - 결국 root 부터 삽입하는 방법을 선택하였다. 

## 19.8.8.
1. BOJ 1991
    - Algorithm : Tree
    - EZ
    
## 19.8.8.
1. BOJ 1016
    - Algorithm : 에라토스테네스의 체
    - Talk. : 7일 저녁부터 풀었는데 못푼 문제이다. 문제 딱봐도 에라토스테네스의 체를 써야되는걸 느꼈다. 소수 찾기 문제와 굉장히 유사함을 느꼈기 때문이다.
      - 수가 굉장히 커서 1~max 값까지 제곱의 배수인지를 확인 할 수 있는 bool 배열을 만들 수가 없다. 하지만 max 의 범위를 [min, min+1000000]로 주었기 때문에 bool 배열을 1000000만큼만 만들어 놓을수 있었다.
      - [치킨먹고싶다](https://www.acmicpc.net/problem/13199) 문제와 비슷한 부분에서 시간초과가 나왔다. 24Line 보면 comp3 을 초기화 하는것을 보면 가장 작은 수부터 시작하는게 아닌 **min 보다 큰 제곱수의 배수 중 가장 작은수** 부터 시작할 수 있게 된다. 이 점을 알아차리고 시간초과를 해결 할 수 있었다.

## 19.8.7.
1. BOJ 1912
    - Algorithm : DP
    - Talk. : fail 한번 하였다. 전체를 놓고 보았을때 전체 더한 값에서 (왼쪽부터 시작하여 더한 값중에 가장 작은값) + (오른쪽부터 시작하여 더한 값중에 가장 작은 값) 을 빼면 가장 큰값이 나오겠구나 싶어서 풀어보았으나 문제에 있는 예제만 가지고 시뮬레이션 해보아도 틀렸다는걸 알 수 있다. 결국 DP 를 사용하는게 가장큰 관건인데 `dp[i] = max(dp[i-1]+arr[i], arr[i])` 이게 맞나... 싶은데 결국 맞다. 사실 이해가 잘 안되지만 ㅋㅋㅋ

## 19.8.7.
1. BOJ 1915
    - Algorithm : DP
    - Talk. : S-1 교육시간에 풀었던 문제(fail 폴더에 넣어놨음)이다. map 이 주어지는 문제는 완전탐색을 최소화로 하는방법을 모색하는걸 습관들여놓으면 좋을것 같다. 틀린 풀이를 보면 완전 탐색을 하지 않기 위해 vector 에 1인 값들의 위치를 저장하는데 이거 또한 완전탐색을 여러번 하는 효과를 낼 수 있어서 시간 초과가 뜬다. 정답 풀이는 완탐 한번이면 끝나기때문에 빠른 시간에 풀수가 있게 된다.
    - Talk. : <cstdio> 와 <iostream> 을 비교해 보았다. 기존에 <cstdio> 를 사용하였는데 정답 결과를 보니 나보다 4배 정도 빠른 사람이 있었다. 그래서 차이점을 보니 입출력을 다르게 하여서 관련 자료를 찾아 보았다. 그냥 <iostream> 은 사실상 더 느리지만 `ios::sync_with_stdio(false);`을 사용하니 더 빠른 속도가 나오게 되었다. [참고.](https://stackoverflow.com/questions/1042110/using-scanf-in-c-programs-is-faster-than-using-cin) 그리고 캐릭터를 받을때 개행문자에 대해서 `cin.tie(NULL);` 를 사용하게되면 개행 문자를 받지 않게 된다. 참 쉽쥬

## 19.7.16.
1. BOJ 5719
    - Algorithm : Dikstra
    - Talk. : 한번 최단거리 찾고 거리 지우고 다시 최단거리를 찾는 방법을 통해 "거의 최단거리"를 구한다. 이걸 구상하는건 쉬워서 다익스트라 알고리즘을 2번 사용하면 되겠구나 싶었다. 첫번째 다익스트라 알고리즘을 사용할땐 경로들을 저장해줘서 (pair <int, vector<int>> 방법을 이용하여) 도착할 시 저장된 경로들을 따라서 map 을 갈수 없는길(MAX 값으로 )변환시켜 준다. 이때 주의 해야될 점이 같은 cost 를 필요로하는 경우가 있을 수 있기 때문에 하나의 경로를 지우고 한번더 탐색해줘야 된다. `if (ans < cost) break;` 를 사용하여 같을경우 break 안걸리게 하였다. 그 다음 한번더 다익스트라 알고리즘을 사용하여 최단거리를 구하였다. `dikstra2 function` 에서 75 번째 줄에 `if (dst[next_] <= next_cost) continue;` 조건에서 `<=`를 `<`로 하면 틀렸다는 결과가 나온다. 틀린 이유에 대해서 졸면서 생각했는데 갑자기 생각안난다. 집에서 다시 해보겠다.

## 19.7.10.
1. BOJ 11657
    - Algorithm : SPFA
    - Talk. : 문제를 보니 음의 가중치가 있었다. bellman-ford 아니면 spfa 를 사용해야겠다는 생각이 들었다. 그래서 spfa 를 사용했는데 조금 컨닝하면서 풀었다 ㅎㅎㅎ. 다음문제는 잘 풀 수 있 겠 지.

## 19.7.9.
1. SWEA 7812
    - Algorithm : SPFA
    - Talk. : SPFA 라는 알고리즘에 대해서 공부하면서 최소 가중치 알고리즘에 대해서 정리해 보는게 좋겠다. Wiki에다가 정리해야겠지?

## 19.7.4.
1. SWEA 1795
    - Algorithm : Dijkstra
    - Talk. : 스터디 문제인데 재밌다. SPFA라는 알고리즘을 알게되었는데 분석을 해봐야 겠다.

## 19.7.3.
1. SWEA 7812
    - Algorithm : Queue
    - Talk. : difficult 5 는 쉽다.

## 19.7.1. ~ 3.
1. SWEA 7905
    - Algorithm : Divide & Conquer, Floyd - Warshall.
    - Challenge.
        1. Only Floyd - Warshall 을 사용했는데 메모리 초과가 뜬다. 확인해보니 어마어마어마하게 많은 메모리를 차지한다. mmap 설정을 int[10000][3][10000][3] 으로 잡았는데 계산해보면 무튼 엄청 크다. 7,031,776 kb 차지 한다. ㅋㅋㅋㅋㅋ. 그래서 그런지 런타임에러가 난다.
        2. Dijkstra 를 사용하면 q 값이 엄청나게 크다면 시간이 오래 걸리는단점이 있다. 그래서 시도도 안해봤다.
    - Talk. : 결국 다른사람의 풀이를 보았다. 갓갓 문제인 만큼 1명만 풀었더라 ㅋㅋㅋㅋ;; 분할정복을 완전히 이해하고 머리속에 있는것을 코딩할 줄 아는 사람인것 같았다. 거의 신의 경지랄까? 완전히 흡수하고 유사문제 풀어 내것으로 만들어야겠따.

## 19.6.28.
1. BOJ 9370
    - Algorithm : Dijkstra algorithm
    - challenge.
        1. 다익스트라 다익스트라!!! 아직 사용법이 익숙지 않다. 사용하는 상황에 대해선 어느정도 감이 잡은듯 하다. 가중치 값을 이용하고, 시작점이 특정한 점이고, 목표지점은 모르지만 가중치를 이용한 값이 최대/최소 가 되어야 할때 사용한다. 이와 유사한 알고리즘으로 벨만-포드랑 하나 뭐 있었는데... 각각의 차이점 다시 리마인드 해보자.
    - Talk. : 시간 많이 썻다. 오전 5시 20분 쯤부터 시작해서 코드 하나를 갈아 치웠다. 다익스트라 알고리즘을 프로그래밍 하는 것에 대해서 익숙해졌다고 생각했는데 살짝 문제에 MSG를 치니까 아무것도 못하죠~ 그리고 Thinking 을 잘했다고 생각한다 다른사람들은 다익스트라 알고리즘 두번 사용하는데 나는 한번 사용하는 코드로 끝냈다... 근데 소요시간은 왜 이 모양이고.. 메모리 사용은 왜 이 모양인건지 해결해야될 문제라고 생각한다.

## 19.6.27.
1. BOJ 1261
    - Algorithm : dijkstra algorithm
    - challenge.
        1. DFS 방법으로 풀었는데 시간 초과가 났다. 생각해보면 완전 탐색을 하면가지 않아도될 곳까지 간다? 잘모르겠다.
    - Talk. : 다익스트라를 사용하는것에 대해서 다시 생각해 봐야되나 싶다. [link](https://namu.wiki/w/%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC%20%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98#toc) 가중치, 간선?

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
