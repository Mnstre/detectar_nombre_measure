#include <Windows.h>
#include <stdio.h>
#include <stdlib>
#include <string>
#include <set>
using namespace std;

// valor - vFlag
set valor(string &linea, int flag) {
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

int getPos(int start, string linea, int pos) {
    for(int i = start ; i<linea.length() ; i++) {
        if(!pos && linea[i] == '|')
            return i;
        else if(pos && linea[i] == '|' || linea[i] == '}') {
            return i;
        }
    } else {
        return 0;
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