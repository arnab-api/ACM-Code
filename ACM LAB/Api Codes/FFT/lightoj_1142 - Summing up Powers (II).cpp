#include<bits/stdc++.h>
using namespace std;
#define dim 35
#define lli long long int
#define mod 10

int d;
struct Matrix{
    int mat[dim][dim];
    Matrix operator*(const Matrix &m)const{
        Matrix tmp;
        for(int i = 0 ; i < d ; i++){
            for(int j = 0 ; j < d ; j++){
                tmp.mat[i][j] = 0;
                for(int t = 0 ; t < d ; t++){
                    tmp.mat[i][j] += mat[i][t]*m.mat[t][j];
                    tmp.mat[i][j] = (tmp.mat[i][j]+mod)%mod;
                }
            }
        }
        return tmp;
    }
    Matrix operator+(const Matrix &m)const{
        Matrix tmp;
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++) {
                tmp.mat[i][j] = mat[i][j] + m.mat[i][j];
                tmp.mat[i][j] = (tmp.mat[i][j]+mod)%mod;
            }
        }
        return tmp;
    }
};

Matrix Arr[2];

Matrix Identity()
{
    Matrix tmp;
    memset(tmp.mat,0,sizeof(tmp));
    for(int i=0;i<d;i++) tmp.mat[i][i] = 1;
    return tmp;
}

Matrix Zero()
{
    Matrix tmp;
    memset(tmp.mat,0,sizeof(tmp));
    return tmp;
}




struct SuperMatrix{
    Matrix mat[2][2];
    SuperMatrix operator*(const SuperMatrix &m)const{
        SuperMatrix tmp;
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                tmp.mat[i][j] = Zero();
                for(int t = 0 ; t < 2 ; t++)
                    tmp.mat[i][j] = tmp.mat[i][j] + mat[i][t]*m.mat[t][j];
            }
        }
        return tmp;
    }
};

SuperMatrix M,F;
Matrix A;

void init()
{
    F.mat[0][0] = M.mat[0][0] = Identity();
    F.mat[0][1] = M.mat[0][1] = Identity();
    F.mat[1][0] = M.mat[1][0] = Zero();
    F.mat[1][1] = M.mat[1][1] = A;
    Arr[1] = Zero();
    Arr[0] = A;
}

void get_pow(int power)
{
    if(power==1) return;
    get_pow(power/2);
    F = F*F;
    if(power & 1) F = F*M;
}

Matrix MatExpo(int n)
{
    if(n==0) return Identity();
    if(n==1) return A;
    Matrix ans;
    init();
    ans=Zero();
    get_pow(n);
    for(int i=0; i<2; i++)
    {
        ans = ans + (F.mat[0][i]*Arr[2-1-i]);
    }
    return ans;
}

void printMat(Matrix M)
{
    cerr<<"\n=====>\n";
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++) printf("%d ",M.mat[i][j]);
        printf("\n");
    }
    cerr<<"\n=====>\n";
}

int main()
{
    int t,kase=0,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&d,&n);
        memset(A.mat,0,sizeof(A.mat));
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++) scanf("%d",&A.mat[i][j]);
        }
        //cerr<<"\n=====>\n";
        printf("Case %d:\n",++kase);
        Matrix ans = MatExpo(n);
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++) printf("%d",ans.mat[i][j]);
            printf("\n");
        }
        //cerr<<"\n=====>\n";
    }
    return 0;
}
/**
2
3 2
1 4 6
6 5 2
1 2 3
*/
