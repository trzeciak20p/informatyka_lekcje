#include <iostream>

using namespace std;

struct IP{
    string Ip;
    int bin;
    int bint[4];
};

bool czyLiczbyMaSame(string ip){
    for(int i = 0; i < ip.length(); i++){
        if(ip[i] < 48 && ip[i] > 57 || ip[i] != '.'){        //sprawdza czy ma same cyfry lub kropke
            return false;
        }
    }
    cout << "Git cyferki" << endl;
    return true;
}

bool czyIpZgodne(string ip, string maska){
    if(!czyLiczbyMaSame(ip)){
        return false;
    }


    else return true;
}

void wczytywanieIp(){
    // IP yo;
    string ip, maska;

    do{
        cout << "Podaj adres IP: ";
        cin >> ip;
        cout << "Podaj maskę: ";
        cin >> maska;
    }while(!czyIpZgodne(ip, maska));


    // yo -> ip = ip;
    // yo -> maska = maska;

    // for(int i = 0; i < ip.length(); i++ ){


    // }
    

    

    return;
}

int main(int argc, char const *argv[])
{

    wczytywanieIp();
 
 
    return 0;
}
