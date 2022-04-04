#include <iostream>
#include <fstream>
using namespace std;
fstream plik;

string wzorzec;

bool czyWzorzec(string linia, string wzorzec){
    string pozostaleZnaki = wzorzec;
    int licznikZnakow;
        for(int i=0;i<linia.length();i++){
            for(int j=0;j<wzorzec.length();j++){
                if(wzorzec[j]==linia[i]){
                    string nowyWzorzec="";
                    for(int k=0;k<j;k++){
                        nowyWzorzec+=wzorzec[k];
                    }
                    for(int k=j+1;k<wzorzec.length();k++){
                        nowyWzorzec+=wzorzec[k];
                    }
                    licznikZnakow++;
                    wzorzec=nowyWzorzec;
                }
            }
        }
        if(licznikZnakow>2){
            return true;
        }
    return false;
}

int znakZawarty(string tekst,char znak){
    for(int i=0;i<tekst.length();i++){
        if(tekst[i]==znak){
            return i;
        }
    }
    return -1;
}
bool czyZawieraZnaki(string linia,string wzorzec){
string drugiWzorzec=wzorzec;
int licznik;
for(int i=0;i<linia.length();i++){
    for(int j=0;j<wzorzec.length();j++){
        if(wzorzec[j]==linia[i]){
            if(znakZawarty(drugiWzorzec,wzorzec[j])>-1){
                    string nowyWzorzec="";
                licznik++;
                for(int k=0;k<znakZawarty(drugiWzorzec,wzorzec[j]);k++){
                    nowyWzorzec+=drugiWzorzec[k];
                }
                for(int k=znakZawarty(drugiWzorzec,wzorzec[j])+1;k<drugiWzorzec.length();k++){
                    nowyWzorzec+=drugiWzorzec[k];
                }
                drugiWzorzec=nowyWzorzec;

            }else{
                return false;
            }

        }
    }
}

if(drugiWzorzec==""){
    return true;
}
return false;

}
bool czyZawieraWzorzec(string linia, string wzorzec){
    int licznik;
for(int i=0;i<linia.length();i++){
    for(int j=0;j<wzorzec.length();j++){
        if(wzorzec[j]==linia[i+j]){
           licznik++;
        }else{
        licznik=0;}
    }
    if(licznik==wzorzec.length()){
        return true;
    }
}
return false;
}
int main()
{
    plik.open("wzorce.txt",ios::in);
    plik>>wzorzec;
    string linia;
    int licznikWzorcow=0;
    int licznikZnakow=0;
    int licznik=0;
    int liniaZWzorcem=0;
    while(plik>>linia){

        if(czyWzorzec(linia,wzorzec)){
            licznikWzorcow++;
        }
        if(czyZawieraWzorzec(linia,wzorzec)){
        liniaZWzorcem=licznik;
        }
        if(czyZawieraZnaki(linia,wzorzec)){
            licznikZnakow++;
        }
        licznik++;
    }

    cout << licznikWzorcow<< endl;
     cout << liniaZWzorcem<< endl;
     cout<<licznikZnakow<<endl;
    return 0;
}