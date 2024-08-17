#pragma once

#include <iostream>

using namespace std;

class Rubik {
public:
	int top[3][3];
	int bottom[3][3];
	int front[3][3];
	int left[3][3];
	int right[3][3];
	int back[3][3];
	
	Rubik() {
		inicializarCaras(0, top);
		inicializarCaras(5, bottom);
		inicializarCaras(2, front);
		inicializarCaras(1, left);
		inicializarCaras(3, right);
		inicializarCaras(4, back);
	}

	~Rubik() {};

	void inicializarCaras(int color, int cara[][3]) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cara[i][j] = color;
			}
		}
	}

	void rotarTop() {
		int* linea = new int[3];
		linea = intercambiar(left[0], front[0]);
		linea = intercambiar(linea, right[0]);
		linea = intercambiar(linea, back[0]);
		linea = intercambiar(linea, left[0]);
	}

	void rotarMed() {
		int* linea = new int[3];
		linea = intercambiar(left[1], front[1]);
		linea = intercambiar(linea, right[1]);
		linea = intercambiar(linea, back[1]);
		linea = intercambiar(linea, left[1]);
	}

	void rotarBottom() {
		int* linea = new int[3];
		linea = intercambiar(left[2], front[2]);
		linea = intercambiar(linea, right[2]);
		linea = intercambiar(linea, back[2]);
		linea = intercambiar(linea, left[2]);
	}

	void rotarIzquierda() {
		rotarCara(left);
		int temp[3];
		for (int i = 0; i < 3; i++) {
			temp[i] = top[i][0];
			top[i][0] = front[i][0];
			front[i][0] = bottom[i][0];
			bottom[i][0] = back[2 - i][2];
			back[2 - i][2] = temp[i];
		}
	}

	void rotarDerecha() {
		rotarCara(right);
		int temp[3];
		for (int i = 0; i < 3; i++) {
			temp[i] = top[i][2];
			top[i][2] = back[i][0];
			back[i][0] = bottom[i][2];
			bottom[i][2] = front[2 - i][2];
			front[2 - i][2] = temp[i];
		}
	}

	void rotarArriba() {
		rotarCara(top);
		int temp[3];
		for (int i = 0; i < 3; i++) {
			temp[i] = front[0][i];
			front[0][i] = left[0][i];
			left[0][i] = back[0][i];
			back[0][i] = right[0][i];
			right[0][i] = temp[i];
		}
	}

	void rotarAbajo() {
		rotarCara(bottom);
		int temp[3];
		for (int i = 0; i < 3; i++) {
			temp[i] = front[2][i];
			front[2][i] = right[2][i];
			right[2][i] = back[2][i];
			back[2][i] = left[2][i];
			left[2][i] = temp[i];
		}
	}

	void rotarCara(int cara[][3]) {
		int temp[3][3];
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				temp[i][j] = cara[2 - j][i];
			}
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cara[i][j] = temp[i][j];
			}
		}
	}

	int* intercambiar(int lineaPre[3], int lineaPos[3]) {
		int* lineaAux = new int[3];
		for (int i = 0; i < 3; i++) {
			lineaAux[i] = lineaPos[i];
		}
		for (int i = 0; i < 3; i++) {
			lineaPos[i] = lineaPre[i];
		}
		return lineaAux;
	}

	//temp

	void imprimiRubik() {

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << " ";
			}
			cout<<"\t";
			for (int j = 0; j < 3; j++) {
				cout << top[i][j] << " ";
			}
			cout<<endl;
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cout << left[i][j] << " ";
			}
			cout << "\t";
			for (int j = 0; j < 3; j++) {
				cout << front[i][j] << " ";
			}
			cout << "\t";
			for (int j = 0; j < 3; j++) {
				cout << right[i][j] << " ";
			}
			cout << "\t";

			for (int j = 0; j < 3; j++) {
				cout << back[i][j] << " ";
			}
			cout << endl;
		}
			for (int i = 0; i < 3; i++) {


			for (int j = 0; j < 3; j++) {
				cout << " ";
			}
			cout<<"\t";

			for (int j = 0; j < 3; j++) {
				cout << bottom[i][j] << " ";
			}
			cout << endl;
		}
	}

};
