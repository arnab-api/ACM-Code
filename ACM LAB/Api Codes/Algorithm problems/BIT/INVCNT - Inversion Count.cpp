//#include<bits/stdc++.h>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<climits>
#include<cstring>
#include<cstdlib>

#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>

#include<vector>
#include<map>
#include<string>
#include<queue>
#include<set>
#include<iterator>
#include<numeric>
#include<stack>
#include<list>
using namespace std;
#define pi acos(-1)
#define M 200010
#define oo 1<<30
#define lli long long int

int arr[M],n;
int Left_arr[M],Right_arr[M];
lli cnt;

void Merge(int left,int mid,int right);
void MergeSort(int left,int right)
{
    if(left<right){
        int mid = (left+right)/2;
        MergeSort(left,mid);
        MergeSort(mid+1,right);
        Merge(left,mid,right);
    }
}

void Merge(int left,int mid,int right)
{
    int lpos = 1 , rpos = 1;
    int l_size = mid - left + 1;
    int r_size = right - mid,i;
    Left_arr[l_size+1] = oo;
    Right_arr[r_size+1] = oo;
    for(i=1;i<=l_size;i++) Left_arr[i] = arr[left+i-1];
    for(i=1;i<=r_size;i++) Right_arr[i] = arr[mid+i];

//    for(i=1;i<=l_size;i++) printf("%d-> ",Left_arr[i]);
//    printf("\n");
//    for(i=1;i<=r_size;i++) printf("%d-> ",Right_arr[i]);
//    printf("\n");

    for(i = left ; i<=right ; i++ ){
        if(Left_arr[lpos]<=Right_arr[rpos]) arr[i] = Left_arr[lpos++];
        else{
            cnt += l_size - lpos + 1;
            //printf("%d %d %d %d ===<> %d\n",l_size,lpos,r_size,rpos,l_size - lpos + 1);
            //cout<<"===>"<<cnt<<endl;
            arr[i] = Right_arr[rpos++];
        }
    }
}

int main()
{
	int i,j,k,l,t;
	scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
        for(i=1;i<=n;i++) scanf("%d",&arr[i]);
        cnt=0;
        MergeSort(1,n);
        //for(i=1;i<=n;i++) printf("%d ",arr[i]);
        //printf("\n");
        //cerr<<"------------->";
        printf("%lld\n",cnt);
	}
	return 0;
}

