#include <iostream>
using namespace std;
int main() {

    cout<<"з додатковою змінною"<<endl;
    //з додатковою змінною
    int a,b,c;
    cout<<"a="; cin>>a;
    cout<<"b="; cin>>b;
    c=a; a=b; b=c;
    cout<<"new a="<<a<<" new b="<<b<<endl;

    cout<<"операції додавання та віднімання"<<endl;
    //операції додавання та віднімання
    int d,e;
    cout<<"d="; cin>>d;
    cout<<"e="; cin>>e;
    d=d+e; e=d-e; d=d-e;
    cout<<"new d="<<d<<" new e="<<e<<endl;

    cout<<"операції ділення та множення"<<endl;
    //операції ділення та множення
    int f,g;
    cout<<"f="; cin>>f;
    cout<<"g="; cin>>g;
    g=g*f; f=g/f; g=g/f;
    cout<<"new f="<<f<<" new g="<<g<<endl;

    cout<<"операції кон'юнкції та диз'юнкції"<<endl;
    //операції кон'юнкції та диз'юнкції
    int h,i;
    cout<<"h="; cin>>h;
    cout<<"i="; cin>>i;
    h=(h&~i)|(~h&i);
    i=(h&~i)|(~h&i);
    h=(h&~i)|(~h&i);
    cout<<"new h="<<h<<" new i="<<i<<endl;

    cout<<"операції зсуву"<<endl;
    //операції зсуву
    long long int j,k;
    long long int l;
    cout<<"j="; cin>>j;
    cout<<"k="; cin>>k;
    l=(j<<32)|k;
    k=l>>32;
    j=(l<<32)>>32;
    cout<<"new j="<<j<<" new k="<<k<<endl;

    cout<<"додавання по модулю 2"<<endl;
    //додавання по модулю 2
    int m,n;
    cout<<"m="; cin>>m;
    cout<<"n="; cin>>n;
    m=m^n; n=m^n; m=m^n;
    cout<<"new m="<<m<<" new n="<<n<<endl;

    return 0;
}