#include <Windows.h>
#include <stdio.h>
#include <stdlib>
#include <string>
#include <set>
using namespace std;

// valor - vFlag
set valor(string &vLinea, int vFlag) {
    int pos, len;
    for(int=0 ; i<vLinea.length() ; i++) {
        if(vLinea[i] == '|') {
            if(vFlag == 1) {
                pos = i++;
                
            } else {
                flag++;
            }
        }
    }
}

int main(){
    filename = "data.txt"
    fstream in;

    in.open(filename, ios::in);
    if(!in.is_open()) return nullptr;
    
    string linea;
    in >>  linea;
    print(valor(linea, 1)); //Imprimir Nombre
    in >> linea;
    print(valor(linea, 0)); //Imprimir Resultado
}