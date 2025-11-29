#include<bits/stdc++.h>
using namespace std;

int add(int a[2][2],int b[2][2],int c[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j]=a[i][j]+b[i][j];
        }
    }
}
int sub(int a[2][2],int b[2][2],int c[2][2]){
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j]=a[i][j]-b[i][j];
        }
    }
}

int mul(int a[2][2],int b[2][2],int c[2][2]){
    c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
    c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
    c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
    c[1][1]=b[1][0]*b[0][1]+a[1][1]*b[1][1];
}

int main(){
    int a[4][4],b[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>b[i][j];
        }
    }

    int a11[2][2],a12[2][2],a21[2][2],a22[2][2];
    int b11[2][2],b12[2][2],b21[2][2],b22[2][2];

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            a11[i][j]=a[i][j];
            a12[i][j]=a[i+2][j];
            a21[i][j]=a[i][j+2];
            a22[i][j]=a[i+2][j+2];

            b11[i][j]=b[i][j];
            b12[i][j]=b[i+2][j];
            b21[i][j]=b[i][j+2];
            b22[i][j]=b[i+2][j+2];
        }
    }

    int p[2][2],q[2][2],r[2][2],s[2][2],t[2][2],u[2][2],v[2][2];
    int t1[2][2],t2[2][2];

    add(a11,a22,t1);
    add(b11,b22,t2);
    mul(t1,t2,p);

    add(a21,a22,t1);
    mul(t1,b11,q);

    sub(b12,b22,t2);
    mul(a11,t2,r);

    sub(b21,b11,t2);
    mul(a22,t2,s);

    add(a11,a12,t1);
    mul(t1,b22,t);

    sub(a21,a11,t1);
    add(b11,b12,t2);
    mul(t1,t2,u);

    sub(a21,a22,t1);
    add(b21,b22,t2);
    mul(t1,t2,v);

    int c[4][4];
    int c11[2][2],c12[2][2],c21[2][2],c22[2][2];

    add(p,s,t1);
    sub(t1,t,t2);
    add(t2,v,c11);

}