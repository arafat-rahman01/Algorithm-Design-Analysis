#include<bits/stdc++.h>
using namespace std;

void add2(int A[2][2],int B[2][2],int C[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}

void sub2(int A[2][2],int B[2][2],int C[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j]=A[i][j]-B[i][j];
        }
    }
}

void mul2(int A[2][2],int B[2][2],int C[2][2]){
    C[0][0]=A[0][0]*B[0][0]+A[0][1]*B[1][0];
    C[0][1]=A[0][0]*B[0][1]+A[0][1]*B[1][1];
    C[1][0]=A[1][0]*B[0][0]+A[1][1]*B[1][0];
    C[1][1]=A[1][0]*B[0][1]+A[1][1]*B[1][1];
}

int main(){
    int A[4][4],B[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>A[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>B[i][j];
        }
    }

    int A11[2][2],A12[2][2],A21[2][2],A22[2][2];
    int B11[2][2],B12[2][2],B21[2][2],B22[2][2];

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+2];
            A21[i][j]=A[i+2][j];
            A22[i][j]=A[i+2][j+2];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i+2][j];
            B21[i][j]=B[i][j+2];
            B22[i][j]=B[i+2][j+2];
        }
    }
    int P[2][2],Q[2][2],R[2][2],S[2][2],T[2][2],U[2][2],V[2][2];
    int t1[2][2],t2[2][2];

    add2(A11,A22,t1);
    add2(B11,B22,t2);
    mul2(t1,t2,P);

    add2(A21,A22,t1);
    mul2(t1,B11,Q);

    sub2(B12,B22,t2);
    mul2(A11,t2,R);

    sub2(B21,B11,t2);
    mul2(A22,t2,S);

    add2(A11,A22,t1);
    mul2(t1,B22,T);

    sub2(A21,A11,t1);
    add2(B11,B22,t2);
    mul2(t1,t2,U);

    sub2(A21,A11,t1);
    add2(B21,B22,t2);
    mul2(t1,t2,V);

    int C[4][4];
    int C11[2][2],C12[2][2],C21[2][2],C22[2][2];

    add2(P,S,t1);
    sub2(t1,T,t2);
    add2(t2,U,C11);

    add2(R,T,C12);

    add2(Q,S,C21);

    add2(P,R,t1);
    sub2(t1,Q,t2);
    add2(t2,U,C22);

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j]=C11[i][j];
            C[i][j+2]=C12[i][j];
            C[i+2][j]=C21[i][j];
            C[i+2][j+2]=C22[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}