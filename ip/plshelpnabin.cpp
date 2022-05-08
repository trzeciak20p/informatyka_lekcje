#include <iostream>
#include <string>

using namespace std;


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
    return bin;
}
int naHex(string bin){
    int hex = 0;
    int a = 1;
    for(int i = bin.length() - 1; i >= 0; i--){
        hex += (bin[i] - 48) * a;
        a *= 2;
        
    }

    return hex;
}

int main(int argc, char const *argv[])
{
    cout << naHex("1000101") << endl;
    return 0;
}
