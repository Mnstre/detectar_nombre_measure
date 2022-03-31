//#include "stdafx.h"
#include <iostream>
#include <string.h>
#include <set>
using namespace std;

class Component {
private:
	char* nombre;
	double vNominal;
	int tolerancia;
	char unidad;
	char* tipo;
public:
	Component(char*, double, int, char, char*);
	char*getName();
    double getValor();
    int getTolerancia();
    char getUnidad();
    char*getTipo();
};

Component::Component(char *nom, double vNo, int tol, char uni, char *tip) {
	nombre = nom;
	vNominal = vNo;
	tolerancia = tol;
	unidad = uni;
	tipo = tip;
}
char* Component::getName() { return nombre; }
double Component::getValor() { return vNominal; }
int Component::getTolerancia() { return tolerancia; }
char Component::getUnidad() { return unidad; }
char* Component::getTipo() { return tipo; }

int getPromedios(set<Component*> lista, int tipo) {
    int suma = 0, count = 0;
    for(auto comp : lista) {
        char* nombre = comp->getName();
        switch(tipo) {
            case 0: if(nombre[0] == 'D')
                        suma += comp->getValor();
                        count++;
                    break;
            case 1: if(nombre[0] == 'R')
                        suma += comp->getValor();
                        count++;
                    break;
            case 2: if(nombre[0] == 'C')
                        suma += comp->getValor();
                        count++;
                    break;
            case 3: if(nombre[0] == 'I')
                        suma += comp->getValor();
                        count++;
                    break;
        }
    }
    return (suma/count);
}

set<Component*> rerolling(set<Component*>listaNueva, Component* comp, int lugares, int posicion) {
    set<Component*> listTemporal;
    int iter = 0;
    for(auto N : listaNueva) {
        if(posicion == iter)
            listTemporal.insert(comp);
        else
            listTemporal.insert(N);
        iter++;
    }
    return listTemporal;
}

set<Component*> ordenComponente(set<Component*> lista) {
	set<Component*> listaNueva;
    int onList = 0;
	for (auto E : lista) {
		if (!listaNueva.empty()) {
            int posicion = 0;
			for (auto A : listaNueva) { //Iteración por componente
				bool reroll = false;
				char* nNuevo = A->getName();
				char* nLista = E->getName();
				for (int i = 0; i < strlen(nNuevo) ; i++) { //Iteración por caractér del nombre del Componente
					if (nLista[i] < nNuevo[i]) { //Si se detecta que el nombre es menor al actual iterado
                        listaNueva = rerolling(listaNueva, A, onList, posicion);
                        reroll = true;
                        onList++;
                        break;
					} else if(nLista[i] > nNuevo[i]) { //Si se detecta que el nombre es mayor, pasa al siguiente Componente
                        break;
                    }
 			    }
                posicion++;
                if(reroll) break;
			}
		} else {
			listaNueva.insert(E);
            onList++;
		}
	}
    return listaNueva;
}

int main() {
	//Componentes: Diodo-Resistencia-Capacitor-Inductor
	//Unidades:	   volts-ohms-faradios-henry
	set<Component*> listaComponentes;
	listaComponentes.insert(new Component("C901", 0.001, 5, 'F', "Capacitor"));
	listaComponentes.insert(new Component("D503", 13, 5, 'V', "Diodo"));
	listaComponentes.insert(new Component("C111", 0.07, 7, 'F', "Capacitor"));
	listaComponentes.insert(new Component("I23", 5, 9, 'H', "Inductor"));
	listaComponentes.insert(new Component("C999", 0.0201, 6, 'F', "Capacitor"));
	listaComponentes.insert(new Component("D321", 25, 12, 'V', "Diodo"));
	listaComponentes.insert(new Component("R404", 10000, 10, 'O', "Resistencia"));
	listaComponentes.insert(new Component("R403", 150000, 15, 'O', "Resistencia"));
	listaComponentes.insert(new Component("D121", 20.3, 13, 'V', "Diodo"));
	listaComponentes.insert(new Component("I700", 2, 7, 'H', "Inductor"));

	listaComponentes = ordenComponente(listaComponentes);

    for(auto E : listaComponentes)
        cout << "Componente: " << E->getName() << ", Valor: " << E->getValor() << ", Tolerancia: " << E->getTolerancia() << "Unidad: " << E->getUnidad() << ", Tipo: " << E->getTipo() << endl;
    

    for(int i=0 ; i<4 ; i++) {
        cout << "Promedios." << endl;
        int promedios = getPromedios(listaComponentes, i);
        switch(i) {
            case 0: cout << "Diodos: " << promedios << "Volts" << endl;
            case 1: cout << "Resistencias: " << promedios << "Ohms" << endl;
            case 2: cout << "Capacitores: " << promedios << "Faradios" << endl;
            case 3: cout << "Inductor: " << promedios << "Henry" << endl;
        }
    }

    return 0;
}
