#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;
ifstream f("intrebari.txt");
ifstream g("raspunsuri.txt");
struct camp
{
    char s[500];//intrebarea
    char a[500],b[500],c[500];//variantele de raspuns
    bool ok;//verific daca intrebarea a mai fost folosita
    int corect;//raspunsul corect al intrebarii
}v[100];
void initializare()
{
    int i;
    for(i=1;i<=36;i++)
    {
        v[i].ok=0;
        f.get(v[i].s,100);
        f.get();
        f>>v[i].corect;
        f.get();
        g.get(v[i].a,100);
        g.get();
        g.get(v[i].b,100);
        g.get();
        g.get(v[i].c,100);
        g.get();

    }
}
void instructiuni()
{
    cout<<"                       ////////////////////////////////"<<endl;
    cout<<"                      //                            //"<<endl;
    cout<<"                     //   Chestionare auto DRPCIV  //"<<endl;
    cout<<"                    //              2015          //"<<endl;
    cout<<"                   //                            //"<<endl;
    cout<<"                  ////////////////////////////////"<<endl<<endl;
    cout<<"                       Atentie! Incepe testul!"<<endl<<endl;
    cout<<"  -Testul contine 26 intrebari si se incheie la depasirea a 5 greseli."<<endl;
    cout<<"  -Pentru a fi admis, trebuie sa acumulezi 22 de raspunsuri corecte."<<endl;
    cout<<"  -Fiecare intrebare are 3 variante de raspuns."<<endl;
    cout<<"  -Variantele de raspuns corecte pot fi toate, doua sau una."<<endl;
    cout<<"  -Nu exista intrebari fara nicio varianta de raspuns corecta."<<endl<<endl;
    cout<<"     Apasati tasta Enter pentru a incepe examenul."<<endl;
}
int gr[6];
int main()
{
    int i,j,z,ra,rb,n,corecte,gresite,x=1,y,cp;
    char r[10];
    system("color 02");
    initializare();
    instructiuni();
    getch();
    system("CLS");
    z=1;
    corecte=0;
    gresite=0;
    while(gresite<5&&z<=26)
    {
        cout<<endl<<"                            Raspunsuri corecte:"<<corecte<<endl;
        cout<<"                            Raspunsuri gresite:"<<gresite<<endl;
        cout<<"                            Intrebarea "<<z<<" din 26"<<endl<<endl;

        srand((unsigned)time(0));//generarea aleatorie a intrebarii
        i=(rand()%36)+1;//generarea aleatorie a intrebarii

        while(v[i].ok==1)
            i=(rand()%36)+1;//validarea intrebarii
        if(v[i].ok==0)
            v[i].ok=1;
        cout<<z<<") "<<v[i].s<<endl<<endl;
        cout<<"a)"<<v[i].a<<endl<<"b)"<<v[i].b<<endl<<"c)"<<v[i].c<<endl<<endl;
        cout<<"       Raspuns:";
        cin.get(r,10);
        cin.get();
        ra=0;
        n=strlen(r);
        for(j=0;j<n;j++)
        {
            if(r[j]=='a')
                ra=ra*10+1;
            if(r[j]=='b')
                ra=ra*10+2;
            if(r[j]=='c')
                ra=ra*10+3;
        }
        cp=ra;
        rb=0;
        while(cp)
        {
            rb=rb*10+cp%10;
            cp=cp/10;
        }
        if((ra==v[i].corect)||(rb==v[i].corect)||((ra>100)&&(v[i].corect=123)))
            corecte++;
        else
        {
            cout<<"Raspuns gresit"<<endl;
            gresite++;
            gr[x]=i;x++;
            switch(v[i].corect)
            {
                case 1:cout<<"Raspunsul corect era:A";
                break;
                case 2:cout<<"Raspunsul corect era:B";
                break;
                case 3:cout<<"Raspunsul corect era:C";
                break;
                case 12:cout<<"Raspunsul corect era:A si B";
                break;
                case 13:cout<<"Raspunsul corect era:A si C";
                break;
                case 23:cout<<"Raspunsul corect era:B si C";
                break;
                case 123:cout<<"Raspunsul corect era:A, B si C";
                break;
            }
            cout<<endl<<"Apasati Enter pentru a continua";
            getch();
        }
        z++;
        system("CLS");
        if(gresite==5)
        {
            cout<<"Examenul a luat sfarsit, ati fost declarat RESPINS"<<endl<<"Apasati Enter pentru a continua"<<endl;
            getch();
            system("CLS");
            cout<<"Intrebari Gresite:"<<endl<<endl;
            for(y=1;y<x;y++)
            {
                cout<<v[gr[y]].s<<endl;
                cout<<"a)"<<v[gr[y]].a<<endl<<"b)"<<v[gr[y]].b<<endl<<"c)"<<v[gr[y]].c<<endl<<endl;
                cout<<"Raspuns corect:";
                if(v[gr[y]].corect==1)
                cout<<"A";
                if(v[gr[y]].corect==2)
                cout<<"B";
                if(v[gr[y]].corect==3)
                cout<<"C";
                if(v[gr[y]].corect==12)
                cout<<"A si B";
                if(v[gr[y]].corect==13)
                cout<<"A si C";
                if(v[gr[y]].corect==23)
                cout<<"B si C";
                if(v[gr[y]].corect==123)
                cout<<"A, B si C";
                cout<<endl<<"Intrebarea "<<y<<" din "<<x-1<<endl;
                getch();
                system("CLS");
            }

        }
    }
    if(gresite<5)
    {
        cout<<"Felicitari, ati fost declarat ADMIS"<<endl<<endl;
        cout<<"Raspunsuri corecte:"<<corecte<<endl;
        cout<<"Raspunsuri gresite:"<<gresite<<endl;
        getch();
        system("CLS");
        if(gresite!=0)
        {
            cout<<"Intrebari Gresite:"<<endl<<endl;
            for(y=1;y<x;y++)
            {
                cout<<v[gr[y]].s<<endl;
                cout<<"a)"<<v[gr[y]].a<<endl<<"b)"<<v[gr[y]].b<<endl<<"c)"<<v[gr[y]].c<<endl<<endl;
                cout<<"Raspuns corect:";
                if(v[gr[y]].corect==1)
                cout<<"A";
                if(v[gr[y]].corect==2)
                cout<<"B";
                if(v[gr[y]].corect==3)
                cout<<"C";
                if(v[gr[y]].corect==12)
                cout<<"A si B";
                if(v[gr[y]].corect==13)
                cout<<"A si C";
                if(v[gr[y]].corect==23)
                cout<<"B si C";
                if(v[gr[y]].corect==123)
                cout<<"A, B si C";
                cout<<endl<<"Intrebarea "<<y<<" din "<<x-1<<endl;
                getch();
                system("CLS");
            }
    }
    }
    f.close();
    g.close();
    return 0;
}
