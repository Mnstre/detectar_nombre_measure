// ConsoleApplication2.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <string>
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
	//friend Component (Component);
};

Component::Component(char *nom, double vNo, int tol, char uni, char *tip) {
	nombre = nom;
	vNominal = vNo;
	tolerancia = tol;
	unidad = uni;
	tipo = tip;
}
char* Component::getName() {
	return nombre;
}

void ordenComponente(set<Component*> lista) {
	set<Component*> listaNueva;
	set<int>num;
	for (auto E : lista) {
		if (!listaNueva.empty()) {
			int onList = 0;
			for (auto A : listaNueva) { //Iteración por componente
				bool success = false;
				int actEval = 0;
				char* nNuevo = A->getName();
				char* nLista = E->getName();
				for (int i = 0; i < strlen(nNuevo) ; i++) { //Iteración por caractér del nombre del Componente
					if (nLista[i] < nNuevo[i]) { //Si se detecta que el nombre es menor al actual iterado
						set<Component*> listaTemp;
						int itTemporal = 0;
						for (auto B : listaNueva) { //Agregar el objeto a su lugar correspondiente
							if (itTemporal < onList) {
								listaTemp.insert(B);
							} else if(itTemporal == onList) {
								listaTemp.insert(E);
								listaTemp.insert(B);
							} else {
								listaTemp.insert(B);
							}
						}
						listaNueva = listaTemp;
						success = true;
						break;
					} else {
						if (nNuevo[i] != nLista[i])
							break;
					}
 				}
				if (success)
					break;
				if (actEval == onList) {
					listaNueva.insert(E);
					onList++;
					break;
				}
			}
			/*
			set<Component*> listaTemporal;
			listaTemporal.insert(E);
			for (auto T : listaNueva) {
				listaTemporal.insert(T);
			}
			listaNueva = listaTemporal;
			*/
		} else {
			listaNueva.insert(E);
		}
	}
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

	ordenComponente(listaComponentes);
}
