/**
 * push_front X: 정수 X를 덱의 앞에 넣는다.
 * push_back X: 정수 X를 덱의 뒤에 넣는다.
 * pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * pop_back: 덱의 가`장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 덱에 들어있는 정수의 개수를 출력한다.
 * empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
 * front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * */

#include <cstdio>

void push_front();
void push_back();
void pop_front();
void pop_back();
void size();
void empty();
void front();
void back();

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;

    for (int cmd_=0; cmd_<N; cmd_++)
    {
        String cmd, cmd2;
        cin >> cmd;

        if (cmd == "push_front")
        {
            cin >> cmd2;
        } else if (cmd == "push_back")
        {
            cin >> cmd2;
        } else if (cmd == "pop_front")
        {
            
        } else if (cmd == "pop_back")
        {
            
        } else if (cmd == "size")
        {
            
        } else if (cmd == "empty")
        {
            
        } else if (cmd == "front")
        {
            
        } else if (cmd == "back")
        {
            
        }
        
    }
    return 0;
}
