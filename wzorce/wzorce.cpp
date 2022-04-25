#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int zad1(){
    fstream plik;
    plik.open("wzorce.txt", ios::in);
    
    int wynik = 0;
    int nr_linii = 0;
    string wzorzec, linia;

    while(getline(plik, linia)){
        int ile_znakow = 0;  
        string nowy_wzorzec = wzorzec; 
        if(nr_linii == 0){
            wzorzec = linia;
        }else{
            for(int i = 0; i < linia.length(); i++){
                for(int j = 0; j < nowy_wzorzec.length(); j++){
                    if(linia[i] == nowy_wzorzec[j]){  
                        ile_znakow++ ; 
                        for(int n = 0; n < nowy_wzorzec.length(); n++){
                            if(nowy_wzorzec[n] == nowy_wzorzec[j]){
                                nowy_wzorzec[n] = NULL;
                            }
                        }                  
                    }
                }
            }   
        }
        if(ile_znakow >= 3){
            wynik++ ;
        }
        nr_linii++ ; 
    }
    
    plik.close();
    return wynik;
}

bool zad2plsHelp(string linia, string wzorzec, string & nowy_wzorzec, int x){
    for(int i = 0; i < wzorzec.length(); i++){
        if(linia[x] == wzorzec[i]){
            nowy_wzorzec[i] = NULL;
            return true;   
        }
        for(int j = i; j < nowy_wzorzec.length(); j++){
            if(linia[x] == nowy_wzorzec[j]){
                nowy_wzorzec[j] == NULL;
                return true;
            }else{
                return false;
            }
        }
    }

    return false; 
}

int zad2(){
    fstream plik;
    plik.open("wzorce.txt", ios::in);
    
    int wynik = 0;
    int nr_linii = 0;
    string wzorzec, linia;

    while(getline(plik, linia)){
        int ile_znakow = 0;
        string nowy_wzorzec;

        if(nr_linii == 0){
            wzorzec = linia;
        }else{        
            nowy_wzorzec = wzorzec;    
            for(int i = 0; i < linia.length(); i++){
                if(zad2plsHelp(linia, wzorzec, nowy_wzorzec, i)){
                    ile_znakow++ ;
                }            
            }
            if(ile_znakow == wzorzec.length()){
                wynik++ ;
            }          
        }
        nr_linii++ ; 
    }
    plik.close();
    return wynik;
}


bool czyTeSame(string linia, string wzorzec, int x){
    for(int j = 0; j < wzorzec.length(); j++){
        if(linia[x-j] != wzorzec[wzorzec.length() - j]){
            return false;
        }
    }
    return true;
}

int zad3(){
    fstream plik;
    plik.open("wzorce.txt", ios::in);
    
    int wynik = 0;
    int nr_linii = 0;
    string wzorzec, linia;

    while(getline(plik, linia)){

        if(nr_linii == 0){
            wzorzec = linia;
        }else{
            for(int i = wzorzec.length(); i < linia.length() - wzorzec.length(); i++){
                if( czyTeSame(linia, wzorzec, i) ){
                    wynik++;
                }
            }
        }
        nr_linii++ ;
    }

    plik.close();
    return wynik;
}

int main(int argc, char const *argv[])
{
 
    cout << "Zad1: " << zad1() << endl;
    cout << "Zad2: " << zad2() << endl;
    cout << "Zad3: " << zad3() << endl;
    


   
    return 0;
}
