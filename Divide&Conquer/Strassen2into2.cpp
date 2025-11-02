#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[2][2], B[2][2], C[2][2];
    int P, Q, R, S, T, U, V;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    P = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    Q = (A[1][0] + A[1][1]) * B[0][0];
    R = A[0][0] * (B[0][1] - B[1][1]);
    S = A[1][1] * (B[1][0] - B[0][0]);
    T = (A[0][0] + A[0][1]) * B[1][1];
    U = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    V = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = P + S - T + V;
    C[0][1] = R + T;
    C[1][0] = Q + S;
    C[1][1] = P - Q + R + U;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            cout << C[i][j] << " ";
        cout <<endl;
    }
}
