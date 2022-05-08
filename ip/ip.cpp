#include <iostream>
#include <string>

using namespace std;

// Wczytać adres IP i maskę 
// Maska Czy 4 oktety czy od zera do 255 i czy ciągłość same jedynki potem same zera 
// 1. Wyświetlić adres IP i maskę w binarce (każdy oktet na bin i połączyć)
// 2. Wyświetlić klasę IP i ilość podejść dla klasy maski (eee maska jedynki -  IP jedynki cośtam)
// 3. Wyświetlić adres sieci, ilość hostów w podsieci
// 4. sprawdzić poprawność maski oraz IP ()

struct IP{
    string ip;
    string mask;
    string ip_bin[4];
    string mask_bin[4];
};

bool czyLiczbyMaSame(IP & x){     //works
    for(int i = 0; i < x.ip.length(); i++){
        if( x.ip[i] < '0' || x.ip[i] > '9'){        //sprawdza czy ma same cyfry lub kropke
            if(x.ip[i] != '.'){
                cout << x.ip[i] << endl;
                cout << "żle cyferki i kropki" << endl;
                return false;
            }
        }
    }
    for(int i = 0; i < x.mask.length(); i++){
        if( x.mask[i] < '0' || x.mask[i] > '9'){        
            if(x.mask[i] != '.'){
                cout << "żle cyferki i kropki" << endl;
                return false;
            }
        }
    }

    cout << "Git cyferki i kropki" << endl;
    return true;
}

string naBinarke(int dec){
    string bin = ""; 
    int e;
    while (dec != 0) {
        e = dec % 2;
        bin = to_string(e) + bin  ;
        dec = dec / 2;
    }
    while(bin.length() < 8){
        bin = "0" + bin;
    }
    cout << bin << endl;
    return bin;
}

bool naPoprawnoscBin(IP & x){
    int ktory_oktet = 0, oktet;
    string oct = "";
    for(int i = 0; i < x.ip.length(); i++){
        if(x.ip[i] != '.'){
            oct += x.ip[i];
        }else{
            oktet = stoi(oct);
            if(oktet > 255){
                cout << "Jeden z oktetów w IP za duży" << endl;
                return false;
            }
    
            x.ip_bin[ktory_oktet] = naBinarke(oktet);
            oct = "";
            ktory_oktet++ ;
            
        }
    }
    oktet = stoi(oct);
    if(oktet > 255){
        cout << "Jeden z oktetów za duży" << endl;
        return false;
    }   
    x.ip_bin[ktory_oktet] = naBinarke(oktet);
    oct = "";
    ktory_oktet = 0;

    // MASKA
    
    for(int i = 0; i < x.mask.length(); i++){
        if(x.mask[i] != '.'){
            oct += x.mask[i];
        }else{
            oktet = stoi(oct);
            if(oktet > 255){
                cout << "Jeden z oktetow w masce za duzy" << endl;
                return false;
            }
    
            x.mask_bin[ktory_oktet] = naBinarke(oktet);
            oct = "";
            ktory_oktet++ ;
            
        }
    }
    oktet = stoi(oct);
    if(oktet > 255){
        cout << "Jeden z oktetow za duzy" << endl;
        return false;
    }   
    x.ip_bin[ktory_oktet] = naBinarke(oktet);
    //czy maska zgodna

    cout << "Maska binarnie: ";
    for (int i = 0; i < 4; i++){
        cout << x.maska_bin[i];
    }
    cout << endl;
    bool git = false;
    for(int i = 0; i < 4; i++){
        string oct2 = x.ip_bin[i];
        for(int j = 0; j < oct2.length(); j++){
            if(oct2[j] == '0'){
                git = true;
            }else{
                if(git){
                    cout << "Zle podana maska" << endl;
                    return false;
                }
            }
        }
    }
    
    

    
    cout << "IP binarnie: ";
    for (int i = 0; i < 4; i++){
        cout << x.ip_bin[i];
    }
    cout << endl;
    cout << "Maska binarnie: ";
    for (int i = 0; i < 4; i++){
        cout << x.ip_bin[i];
    }
    cout << endl;

    return true;
}

bool czySkladniaDobrze(IP & x){       //works
    int ae = 0;             //ilośc numerków między kropkami
    int ile_kropek = 0;
    for(int i = 0; i < x.ip.length(); i++){
        if(x.ip[i] != '.'){
            ae++ ;   
            if(ae == 4){
                cout << "Źle składnia" << endl;
                return false;
            } 
        }else{
            if(ae == 0){
                cout << "Brak znaków między kropkami" << endl;
                return false;
            }
            ae = 0;
            ile_kropek++ ;
            if(ile_kropek == 4){               
                cout << "Źle składnia (za dużo kropek)" << endl;
                return false;
            }
        }        
    }
    if(ile_kropek < 3 || ae == 0){
        cout << "Źle składnia" << endl;
        return false;
    }
    //maska
    ile_kropek = 0;
    ae = 0;
    for(int i = 0; i < x.mask.length(); i++){
        if(x.mask[i] != '.'){
            ae++ ;   
            if(ae == 4){
                cout << "Źle składnia" << endl;
                return false;
            }
        }else{
            if(ae == 0){
                cout << "Brak znaków między kropkami" << endl;
                return false;
            }
            ae = 0;
            ile_kropek++ ;
            if(ile_kropek == 4){
                cout << "Źle składnia (za dużo kropek)" << endl;
                return false;
            }
        }      
    }
    if(ile_kropek < 3 || ae == 0){
        cout << "Źle składnia" << endl;
        return false;
    }

    cout << "Git składnia" << endl;
    return true;
}

bool czyIpZgodne(IP & x){
    if(!czyLiczbyMaSame(x)){
        return false;
    }
    if(!czySkladniaDobrze(x)){
        return false;
    }
    if(!naPoprawnoscBin(x)){
        return false;
    }
    return true;
}

void wczytywanieIp(){
    IP ajpi;
    string ip, maska;

    do{
        cout << "Podaj adres IP: ";
        cin >> ip;
        cout << "Podaj maskę: ";
        cin >> maska;
        ajpi.ip = ip;
        ajpi.mask = maska;
    }while(!czyIpZgodne(ajpi));


    for(int i = 0; i < ip.length(); i++ ){


    }
    

    

    return;
}

int main(int argc, char const *argv[])
{

    wczytywanieIp();
 
 
    return 0;
}