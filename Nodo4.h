#pragma once
#include<cstdlib>
#include<iostream>
class Nodo4 {
private:
	int valor;
	Nodo4* arriba;
	Nodo4* abajo;
	Nodo4* izquierda;
	Nodo4* derecha;
	bool visitado;

public:
	Nodo4(int x) : valor(x), arriba(NULL), abajo(NULL), izquierda(NULL), derecha(NULL), visitado(false) {}
	Nodo4() {}

	int get_valor() {
		return valor;
	}

	void set_valor(int e) {
		valor = e;
	}

	Nodo4* get_arriba() {
		return arriba;
	}

	void set_arriba(Nodo4* p) {
		arriba = p;
	}

	Nodo4* get_abajo() {
		return abajo;
	}

	void set_abajo(Nodo4* p) {
		abajo = p;
	}

	Nodo4* get_izquierda() {
		return izquierda;
	}

	void set_izquierda(Nodo4* p) {
		izquierda = p;
	}

	Nodo4* get_derecha() {
		return derecha;
	}

	void set_derecha(Nodo4* p) {
		derecha = p;
	}

	bool get_visitado() {
		return visitado;
	}

	void set_visitado(bool v) {
		visitado = v;
	}
};

Nodo4* crearNodo(int valor) {
	return new Nodo4(valor);
}

// Función para intercambiar dos nodos
void intercambiarNodos(Nodo4* nodo9, Nodo4* nodo8) {
	int temp = nodo9->get_valor();
	nodo9->set_valor(nodo8->get_valor());
	nodo8->set_valor(temp);

}

void permutarNodos(Nodo4* nodos[], int tam) {
	for (int i = tam - 1; i > 0; --i) {
		int j = rand() % (i + 1);
		intercambiarNodos(nodos[i], nodos[j]);
	}
}

bool esMatrizFinal(Nodo4* nodo1, Nodo4* nodo2, Nodo4* nodo3,
	Nodo4* nodo4, Nodo4* nodo5, Nodo4* nodo6,
	Nodo4* nodo7, Nodo4* nodo8, Nodo4* nodo9) {
	// Definir la matriz final
	int matrizFinal[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

	// Crear una matriz temporal para comparar
	int matrizActual[3][3] = {
		{nodo1->get_valor(), nodo2->get_valor(), nodo3->get_valor()},
		{nodo4->get_valor(), nodo5->get_valor(), nodo6->get_valor()},
		{nodo7->get_valor(), nodo8->get_valor(), nodo9->get_valor()}
	};

	// Comparar cada elemento de ambas matrices
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (matrizFinal[i][j] != matrizActual[i][j]) {
				return false; // Las matrices no coinciden
			}
		}
	}

	return true; // Las matrices coinciden
}
