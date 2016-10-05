#include<bits/stdc++.h>
using namespace std;
#define M 500100
#define PI acos(-1)

typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;

	vector<base> a0 (n/2),  a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
		a0[j] = a[i];
		a1[j] = a[i+1];
	}
	fft (a0, invert);
	fft (a1, invert);

	double ang = 2*PI/n * (invert ? -1 : 1);
	base w (1),  wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
		a[i] = a0[i] + w * a1[i];
		a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
			a[i] /= 2,  a[i+n/2] /= 2;
		w *= wn;
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size()))  n <<= 1;
	n <<= 1;
	fa.resize (n),  fb.resize (n);

	fft (fa, false),  fft (fb, false);
	for (size_t i=0; i<n; ++i)
		fa[i] *= fb[i];
	fft (fa, true);

	res.resize (n);
	for (size_t i=0; i<n; ++i)
		res[i] = int (fa[i].real() + 0.5);
}

void find_submask(vector<int> &line,vector<int> &word,vector<int> &res)
{
    reverse(word.begin(),word.end());
    multiply(line,word,res);
    //reverse(res.begin(),res.end());
    /// returned vector must be iterated reversely
}

char s[M],t[M];
char dna[] = {'A','T','C','G'};
vector<int>a,b,c,res;

int main()
{
    int n,m,k,l,r,i,j;
    while(scanf("%d%d%d",&n,&m,&k)==3){
        scanf(" %s",&s);
        scanf(" %s",&t);
        c.resize(n,0);
        for(int i=0;i<4;i++){
            a.clear();
            b.clear();
            res.clear();

            a.resize(n,0);
            for(j=0;j<n;j++){
                if(s[j] == dna[i]){
                    l = max(0,j-k);
                    a[l]++;
                    r = j+k;
                    if(r+1 < n) a[r+1]--;
                }
            }
            for(j=1;j<n;j++) a[j] += a[j-1];
            for(j=0;j<n;j++) a[j] = (a[j]>0);
            for(j=0;j<n;j++) cerr<<a[j];
            cout<<endl;

            b.resize(m,0);
            for(j=0;j<m;j++) b[j] = (t[j] == dna[i]);
            for(j=0;j<m;j++) cout<<b[j];
            cout<<endl;

            find_submask(a,b,res);
            for(j=0;j<n;j++) cout<<res[j];
            cout<<"===================>"<<endl;
            for(j=0;j<n;j++) c[j] += res[n-j-1];
            for(j=0;j<n;j++) cout<<c[j];
            cout<<"------------>>>"<<endl;
        }
        int ans = 0;
        for(int i=0;i<n;i++) if(c[i]==m) ans++;
        cerr<<"===>>>====>>>>======>>>>";
        printf("%d\n",ans);
    }
    return 0;
}

/**

10 4 1
AGCAATTCAT
ACAT
*/
