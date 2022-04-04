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

bool zad2plsHelp(string linia, string nowy_wzorzec, int x){


}

bool czyPusty(string co){
    for(int i = 0; i < co.length(); i++){
        cout << "Is this even necesery?" << endl;
        

    }
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


            }
            if(nowy_wzorzec == NULL){
                wynik++ ;
            }






            // for(int i = 0; i < linia.length(); i++){
            //     bool popsuta_linia = false;
            //     for(int j = 0; j < wzorzec.length(); j++){
            //         if(linia[i] == wzorzec[j]){
            //             if(linia[i] == nowy_wzorzec[j]){
            //                 ile_znakow++;
            //                 nowy_wzorzec[j] = NULL;
            //                 popsuta_linia = false;
            //             }else{
            //                 popsuta_linia = true;
            //             }                       
            //         }
            //     }
            //     bool popsuty_wrzozec = false;
            //     for(int n = 0; n < nowy_wzorzec.length(); n++){
            //          if(nowy_wzorzec[n] != NULL){
            //             popsuty_wzorzec = true;
            //          }
            //     }
                
            //     if(!popsuta_linia && !popsuty_wzorzec){
            //         wynik++ ;
            //     }
            }
        }
        nr_linii++ ; 
    }

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
    }

    plik.close();
    return wynik;
}

int main(int argc, char const *argv[])
{
 
    cout << "Zad1: " << zad1() << endl;
    // cout << "Zad2: " << zad2() << endl;
    cout << "Zad3: " << zad3 << endl;
    


   
    return 0;
}
