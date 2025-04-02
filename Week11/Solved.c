#include <stdio.h>

int a[4][4] = {
    {0, 3, 0, 2},
    {3, 0, 1, 0},
    {0, 1, 0, 5},
    {2, 0, 5, 0}
};
int t[4][4], root[4], parent[4], n = 4, i, j, value, e = 4, k = 0;
int ivalue, jvalue, cost = 0, mincost = 0, TV[4], count = 0, present = 0;

int check_reach(int v) {
    int p;
    for (p = 1; p <= count; p++)
        if (TV[p] == v)
            return 1;
    return 0;
}

void prims() {
    while (e && k < n - 1) {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                if (a[i][j] != 0) {
                    int x, y;
                    x = check_reach(i);
                    y = check_reach(j);
                    if ((x == 1) && (y == 0)) {
                        present = 1;
                        if ((a[i][j] < cost) || (cost == 0)) {
                            cost = a[i][j];
                            ivalue = i;
                            jvalue = j;
                        }
                    }
                }
            }
        if (present == 0)
            break;
        a[ivalue][jvalue] = 0;
        a[jvalue][ivalue] = 0;
        e--;
        TV[++count] = jvalue;
        t[ivalue][jvalue] = cost;
        k++;
        present = cost = 0;
    }
}

void display() {
    if (k == n - 1) {
        printf("\nMin. cost:");
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) {
                if (t[i][j] != 0)
                    printf("\n(%d, %d): %d", i, j, t[i][j]);
                mincost += t[i][j];
            }
        printf("\nTotal: %d\n", mincost);
    }
    else
        printf("\nGraph is not connected\n");
}

void main() {
    TV[++count] = 1;
    prims();
    display();
}