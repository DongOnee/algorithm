# Algorithm Think...

알고리즘 문제를 풀면서 깨달은 것들을 적어보자. 나중에 코딩테스트를 보러 갈 일이 있다면 한번씩 봐보도록. 다른사람들도 도움이 됬으면 좋겠다.

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
