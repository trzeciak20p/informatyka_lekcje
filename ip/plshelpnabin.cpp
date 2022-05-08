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

int main(int argc, char const *argv[])
{
    cout << naBinarke(255);
    return 0;
}
