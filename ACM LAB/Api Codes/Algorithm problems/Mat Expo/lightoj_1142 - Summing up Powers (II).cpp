#include<bits/stdc++.h>
using namespace std;
#define iii long long int
#define MAX 35

int d;

struct Matrix{
    iii mat[MAX][MAX];
    Matrix operator*(const Matrix &m)const{
        Matrix tmp;
        for(int i = 0 ; i < d ; i++){
            for(int j = 0 ; j < d ; j++){
                tmp.mat[i][j] = 0;
                for(int t = 0 ; t < d ; t++)
                    tmp.mat[i][j] += mat[i][t]*m.mat[t][j];
            }
        }
        return tmp;
    }
    Matrix operator + (const Matrix & m) const{
        Matrix tmp;
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++);
            tmp.mat[i][j] = mat[i][j]+m.mat[i][j];
        }
        return tmp;
    }
};

struct SuperMatrix{
    Matrix mat[2][2];
    SuperMatrix operator*(const SuperMatrix & m)const{
        SuperMatrix tmp;
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < 2 ; j++){
                tmp.mat[i][j] = 0;
                for(int t = 0 ; t < 2 ; t++)
                    tmp.mat[i][j] += mat[i][t]*m.mat[t][j];
            }
        }
        return tmp;
    }
};

int main()
{
    return 0;
}
