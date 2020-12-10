#include <iostream>

using namespace std;

const int MAXCONTAINERCOUNT = 100;

int containerCount, maxError;
int lifeCell[2 * MAXCONTAINERCOUNT];
bool isRobot[MAXCONTAINERCOUNT + 1];

int run() {
    int ret = 0;
    while (true) {
        ++ret;
        for (int cellIndex = containerCount - 2; 0 <= cellIndex; --cellIndex) {
            isRobot[cellIndex + 1] = isRobot[cellIndex];
        }
        isRobot[containerCount - 1] = isRobot[0] = false;

        int temp = lifeCell[2 * containerCount - 1];
        for (int cellIndex = 2 * containerCount - 1; 0 < cellIndex; --cellIndex) {
            lifeCell[cellIndex] = lifeCell[cellIndex - 1];
        }
        lifeCell[0] = temp;

        for (int cellIndex = containerCount - 2; 0 <= cellIndex; --cellIndex) {
            if (isRobot[cellIndex] && !isRobot[cellIndex + 1] && lifeCell[cellIndex + 1] > 0) {
                isRobot[cellIndex + 1] = true;
                isRobot[cellIndex] = false;
                --lifeCell[cellIndex + 1];
            }
        }
        isRobot[containerCount - 1] = false;

        if (!isRobot[0] && lifeCell[0] > 0) {
            isRobot[0] = true;
            --lifeCell[0];
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
