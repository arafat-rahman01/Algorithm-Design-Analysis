#include <bits/stdc++.h>
using namespace std;

// Add two 2x2 matrices
void add2(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Subtract two 2x2 matrices
void sub2(int A[2][2], int B[2][2], int C[2][2]) {
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Multiply two 2x2 matrices (normal multiplication)
void mul2(int A[2][2], int B[2][2], int C[2][2]) {
    C[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    C[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    C[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    C[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];
}

int main() {
    int A[4][4], B[4][4];

    cout << "Enter 4x4 Matrix A:\n";
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> A[i][j];

    cout << "Enter 4x4 Matrix B:\n";
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> B[i][j];

    // Step 1: Split A and B into 2x2 blocks
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];

    for(int i=0;i<2;i++) {
        for(int j=0;j<2;j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j+2];
            A21[i][j] = A[i+2][j];
            A22[i][j] = A[i+2][j+2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j+2];
            B21[i][j] = B[i+2][j];
            B22[i][j] = B[i+2][j+2];
        }
    }

    // Temporary matrices
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2], M5[2][2], M6[2][2], M7[2][2];
    int t1[2][2], t2[2][2];

    // M1 = (A11 + A22)(B11 + B22)
    add2(A11, A22, t1);
    add2(B11, B22, t2);
    mul2(t1, t2, M1);

    // M2 = (A21 + A22)B11
    add2(A21, A22, t1);
    mul2(t1, B11, M2);

    // M3 = A11(B12 - B22)
    sub2(B12, B22, t2);
    mul2(A11, t2, M3);

    // M4 = A22(B21 - B11)
    sub2(B21, B11, t2);
    mul2(A22, t2, M4);

    // M5 = (A11 + A12)B22
    add2(A11, A12, t1);
    mul2(t1, B22, M5);

    // M6 = (A21 - A11)(B11 + B12)
    sub2(A21, A11, t1);
    add2(B11, B12, t2);
    mul2(t1, t2, M6);

    // M7 = (A12 - A22)(B21 + B22)
    sub2(A12, A22, t1);
    add2(B21, B22, t2);
    mul2(t1, t2, M7);

    // Final result C = 4x4 matrix
    int C[4][4];
    int C11[2][2], C12[2][2], C21[2][2], C22[2][2];

    // C11 = M1 + M4 - M5 + M7
    add2(M1, M4, t1);
    sub2(t1, M5, t2);
    add2(t2, M7, C11);

    // C12 = M3 + M5
    add2(M3, M5, C12);

    // C21 = M2 + M4
    add2(M2, M4, C21);

    // C22 = M1 - M2 + M3 + M6
    sub2(M1, M2, t1);
    add2(t1, M3, t2);
    add2(t2, M6, C22);

    // Merge into C[4][4]
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++) {
            C[i][j] = C11[i][j];
            C[i][j+2] = C12[i][j];
            C[i+2][j] = C21[i][j];
            C[i+2][j+2] = C22[i][j];
        }

    cout << "\nResult (A × B) using Strassen:\n";
    for(int i=0;i<4;i++) {
        for(int j=0;j<4;j++)
            cout << C[i][j] << " ";
        cout << "\n";
    }

    return 0;
}
