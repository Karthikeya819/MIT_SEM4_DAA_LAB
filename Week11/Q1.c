#include <stdio.h>

int cost[4][4] = {
    {0, 3, 0, 2},
    {3, 0, 1, 0},
    {0, 1, 0, 5},
    {2, 0, 5, 0}
};
int  p[4] = {};

int findF(int i) {
    while(p[i])
        i = p[i];
    return i;
}

int uniF(int i,int j) {
    if(i != j) {
        p[j] = i;
        return 1;
    }
    return 0;
}

void main() {
    int a, b, u, v, n = 4, min = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (cost[i][j] == 0) {
                cost[i][j] = 999999;
            }

    printf("Min. cost:\n");
    for(int ne = 1; ne < n; ne++) {
        int minVal = 999999;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(cost[i][j] < minVal) {
                    minVal = cost[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = findF(u);
        v = findF(v);

        if(uniF(u, v)) {
            printf("(%d, %d)\n", a, b);
            min += minVal;
        }

        cost[a][b] = cost[b][a] = 999999;
    }
    printf("Total: %d\n", min);
}