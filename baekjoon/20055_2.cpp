#include <iostream>

using namespace std;

const int MAXCONTAINERCOUNT = 100;

int containerCount, maxError;
int lifeCell[2 * MAXCONTAINERCOUNT];
bool isRobot[2 * MAXCONTAINERCOUNT];

#define nextIndex(idx) ((idx + 1) % (2 * containerCount))
#define prevIndex(idx) ((idx + 2 * containerCount - 1) % (2 * containerCount))
#define tailIndex(idx) ((idx + containerCount - 1) % (2 * containerCount))

int run() {
    int ret = 0;
    int start = 0;
    while (true) {
        ++ret;
        start = prevIndex(start);
        isRobot[tailIndex(start)] = false;

        for (int i=0, ii = tailIndex(start); i<containerCount; ++i) {
            if (isRobot[ii] && !isRobot[nextIndex(ii)] && lifeCell[nextIndex(ii)] > 0) {
                isRobot[ii] = false;
                isRobot[nextIndex(ii)] = true;
                --lifeCell[nextIndex(ii)];
            }

            ii = prevIndex(ii);
        }
        isRobot[tailIndex(start)] = false;

        if (!isRobot[start] && lifeCell[start] > 0) {
            isRobot[start] = true;
            --lifeCell[start];
        }

        for (int cellIndex = 0, limit = 0; cellIndex < 2 * containerCount; ++cellIndex) {
            if (lifeCell[cellIndex] == 0)
                if (++limit == maxError) return ret;
        }
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> containerCount >> maxError;

    for (int i = 0; i < 2 * containerCount; ++i) {
        cin >> lifeCell[i];
    }

    cout << run() << '\n';
    return 0;
}
