#include<bits/stdc++.h>
using namespace std;

struct Player
{
    string name,lang;
    int point;
    Player(){
        name = "";
        lang = "";
        point  = 0;
    }
    Player(string nam,string lan){
        name = nam;
        lang = lan;
        point = 0;
    }
    /// 0 if rock
    /// 1 if scissor
    /// 2 if paper
    int getval(string str){
        if(lang == "cs"){
            if(str == "Kamen") return 0;
            else if(str == "Nuzky") return 1;
            else return 2;
        }
        else if(lang == "en"){
            if(str == "Rock") return 0;
            else if(str == "Scissors") return 1;
            else return 2;
        }
        else if(lang == "fr"){
            if(str == "Pierre") return 0;
            else if(str == "Ciseaux") return 1;
            else return 2;
        }
        else if(lang == "de"){
            if(str == "Stein") return 0;
            else if(str == "Schere") return 1;
            else return 2;
        }
        else if(lang == "hu"){
            if(str == "Ko" || str == "Koe") return 0;
            else if(str == "Ollo" || str == "Olloo") return 1;
            else return 2;
        }
        else if(lang == "it"){
            if(str == "Sasso" || str == "Roccia") return 0;
            else if(str == "Forbice") return 1;
            else return 2;
        }
        else if(lang == "jp"){
            if(str == "Guu") return 0;
            else if(str == "Choki") return 1;
            else return 2;
        }
        else if(lang == "pl"){
            if(str == "Kamien") return 0;
            else if(str == "Nozyce") return 1;
            else return 2;
        }
        else if(lang == "es"){
            if(str == "Piedra") return 0;
            else if(str == "Tijera") return 1;
            else return 2;
        }
    }
};

Player p1,p2;
int getres(int a,int b)
{
    if(a==b) return 0;
    if(a == 0 && b == 1) return 1;
    if(a == 1 && b == 2) return 1;
    if(a == 2 && b == 0) return 1;
    return 2;
}

void init()
{
    p1 = Player();
    p2 = Player();
}

int main()
{
    string name,lang,str,m1,m2;
    int i,j,k,l,a,b,c,kase=0;
    while(cin>>name){
        if(name == ".") return 0;
        if(name == "-"){
            init();
            continue;
        }
        p1.lang = name;
        cin >> str;
        p1.name = str;
        cin>>m1>>m2;
        p2 = Player(m2,m1);
        while(cin>>m1){
            name = m1;
            if(name == "-" || name == "."){
                printf("Game #%d:\n",++kase);
                cout<<p1.name<<": ";
                if(p1.point == 1) printf("1 point\n");
                else printf("%d points\n",p1.point);
                cout<<p2.name<<": ";
                if(p2.point == 1) printf("1 point\n");
                else printf("%d points\n",p2.point);
                if(p1.point==p2.point) cout<<"TIED GAME"<<endl;
                else{
                    cout<<"WINNER: ";
                    if(p1.point>p2.point) cout<<p1.name;
                    else cout<<p2.name;
                    cout<<endl;
                }
                cout<<endl;
                if(name == "-"){
                    init();
                    break;
                }
                else return 0;
            }
            cin>>m2;
            a = p1.getval(m1);
            b = p2.getval(m2);
            c = getres(a,b);
            if(c==1) p1.point++;
            else if(c==2) p2.point++;
        }
    }
    return 0;
}
/**
cs Gertruda
de Lenka
Papir Stein
Kamen Schere
*/
