# Algorithm Think...

알고리즘 문제를 풀면서 깨달은 것들을 적어보자. 나중에 코딩테스트를 보러 갈 일이 있다면 한번씩 봐보도록. 다른사람들도 도움이 됬으면 좋겠다.

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
