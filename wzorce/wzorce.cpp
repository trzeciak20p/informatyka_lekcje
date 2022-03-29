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

    return wynik;
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
            for(int i = 0; i < linia.length(); i++){
                bool popsuta_linia = false;
                for(int j = 0; j < wzorzec.length(); j++){
                    if(linia[i] == wzorzec[j]){
                        if(linia[i] == nowy_wzorzec[j]){
                            ile_znakow++;
                            nowy_wzorzec[j] = NULL;
                            popsuta_linia = false;
                        }else{
                            popsuta_linia = true;
                        }                       
                    }
                }
                if(!popsuta_linia && ){
                    wynik++ ;

                }
            }
        }
        nr_linii++ ; 
    }

    return wynik;
}



int zad3(){
    
}

int main(int argc, char const *argv[])
{
 
    cout << "Zad1: " << zad1() << endl;
    // cout << "Zad2: " << zad2() << endl;

    


   
    return 0;
}
