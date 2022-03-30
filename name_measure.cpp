#include <iostream>
#include <string>
using namespace std;

//Funcion obtener coordenadas
//      Se basa en la deteccion de los caracteres '|' y '{'
//      int start : indica a partir de qué caractér de la linea consultada comienza la iteracion
//      int pos : la cantidad de "bloques" a desplazarse en la linea
int getPos(int start, string &linea, int pos) {
    int nValor = 1;
    for(int i = start ; i<linea.length() ; i++) {
        char a = linea[i];
        if(linea[i] == '|' || linea[i] == '{') {
            if(nValor == pos) {
                return ++i;
            } else {
                nValor++;
            }
        }
    }
    return 0;
}

// Funcion valor : Obtiene el inicio del dato a consultar y el tamaño del nombre.
//      string linea : contiene la linea completa del .txt consultado
//          int flag : indica que se está consultado, nombre o resultado.
//                     0 - nombre
//                     1 - resultado
string getWord(string &linea, int flag) {
    int pStart, pFinal;
    pStart = getPos(0, linea, flag); //Coordenada inicial del string
    if(pStart != 0)
        pFinal = getPos(pStart, linea, 1) - pStart - 1; //Coordenada final del string
    else
        return "nodata"; //Cuando la linea evaluada no contiene informacion
    return linea.substr(pStart, pFinal);
}

int detectTipo(string &linea) {
    //devolver 1 - nombre
    //         2 - resultado
    //         0 - noData
    string pTipo = getWord(linea, 1);
    if(pTipo == "@BLOCK")
        return 1;
    else if(pTipo == "@A-JUM")
        return 2;
    return 0;
}

int main(){
    //string filename("data.txt");
    
    string linea[17] = {
            "{@BLOCK|1%l400|00",
            "{@A-JUM|0|+2.769925E+00{@LIM2|+1.000000E+01|+0.000000E+00}}",
            "}",
            "{@BLOCK|1%l401|00",
            "{@A-JUM|0|+2.293126E+00{@LIM2|+1.000000E+01|+0.000000E+00}}",
            "}",
            "{@BLOCK|1%l402%l12|00",
            "{@A-JUM|0|+2.655081E+00{@LIM2|+1.000000E+01|+0.000000E+00}}",
            "}",
            "{@BLOCK|1%l402%l34|00",
            "{@A-JUM|0|+2.615681E+00{@LIM2|+1.000000E+01|+0.000000E+00}}",
            "}",
            "{@BLOCK|1%l403%l12|00",
            "{@A-JUM|0|+2.267664E+00{@LIM2|+1.000000E+01|+0.000000E+00}}",
            "}",
            "{@BLOCK|1%l403%l34|00",
            "{@A-JUM|0|+2.637193E+00{@LIM2|+1.000000E+01|+0.000000E+00}}",
        };
    
    for(string E : linea) {
        int tipoDato = detectTipo(E);
        string data = getWord(E, ++tipoDato);
        if(tipoDato)
            cout << data << endl;
        else
            cout << endl;
    }
    return 0;
}
