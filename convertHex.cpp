#include <iostream>
#include <string>
#include <cmath>

int getDecimal(string &hexa) {
    int power = hexa.length() - 1;
    for(char E : hexa) {
        switch(E) {
            case A: return 
        }
    }
}

string* getByte(string hexa) {
    string* bytes = new String[2];
    bytes[0] = hexa.substr(0, 2);
    bytes[1] = hexa.substr(2, 2);
    return bytes;
}

int main() {
    string hexa;
    cout << "Número hexadecimal a procesar:" << endl;
    cin >> hexa;
    
    //Hexadecimal a 2 Bytes
    string bytes[2] = getByte(hexa);
    cout << "[" << bytes[0] << ", " << bytes[1] << "]" << endl;
    
    //Hexadecimal a Decimal
    int decimales = getDecimal(hexa);
    cout << decimales << endl;
    
    return 0;
}
