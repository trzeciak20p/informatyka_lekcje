#include <iostream>

using namespace std;


bool czyIpZgodneZMaska(string ip, string maska){
    

}

int wczytywanieIp(){
    string ip, maska;
    do{
        cout << "Podaj adres IP: ";
        cin >> ip;
        cout << "Podaj maskę: ";
        cin >> maska;
    }while(!czyIpZgodneZMaska);


    return ip;
}

int main(int argc, char const *argv[])
{

    wczytywanieIp();
 
 
    return 0;
}