#include<bits/stdc++.h>
using namespace std;
#define M 100100
#define lli long long int

struct node
{
    int left,right;
    node *l_child,*r_child;
    node(){
        left=0;
        right=0;
        l_child=NULL; r_child=NULL;
    }
}*root;

void Insert(int N)
{
    node *cur=root;
    for(int i=20;i>=0;i--){
        int id=(N>>i)&1;
        if(id==1) {
            cur->right++;
            if(cur->r_child==NULL) cur->r_child=new node();
            cur=cur->r_child;
        }
        else{
            cur->left++;
            if(cur->l_child==NULL) cur->l_child=new node();
            cur=cur->l_child;
        }
    }
}

int k;

lli Search(int N,int K)
{
    node *cur=root;
    if(cur==NULL) return 0;
    int i,id1,id2;
    lli ret=0;
    for(i=20;i>=0;i--){
        id1=(K>>i) & 1;
        id2=(N>>i) & 1;
        if(id1){
            if(id2){
                ret+=cur->right;
                if(cur->l_child==NULL) {
                    //cout<<"11----------------->"<<ret<<endl;
                    return ret;
                }
                cur=cur->l_child;
            }
            else{
                ret+=cur->left;
                if(cur->r_child==NULL) {
                    //cout<<"10----------------->"<<ret<<endl;
                    return ret;
                }
                cur=cur->r_child;
            }
        }
        else{
            if(id2){
                if(cur->r_child==NULL) {
                    //cout<<"01----------------->"<<ret<<endl;
                    return ret;
                }
                cur=cur->r_child;
            }
            else{
                if(cur->l_child==NULL) {
                    //cout<<"00----------------->"<<ret<<endl;
                    return ret;
                }
                cur=cur->l_child;
            }
        }
    }
    return ret;
}

void del(node *cur)
{
    if(cur->l_child!=NULL) del(cur->l_child);;
    if(cur->r_child!=NULL) del(cur->r_child);;
    delete (cur);
}

int main()
{
    int t,n,sum[M],a,i;
    scanf("%d",&t);
    lli ans;
    string B,A;
    while(t--){
        scanf("%d%d",&n,&k);
        sum[0]=0;
        root=new node();
        Insert(0);
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            sum[i]=(sum[i-1]^a);
        }
        ans=0;
        for(i=1;i<=n;i++){
            ans+=Search(sum[i],k);
            Insert(sum[i]);
        }
        cout<<"------------->";
        printf("%lld\n",ans);
        del(root);
    }
    return 0;
}

