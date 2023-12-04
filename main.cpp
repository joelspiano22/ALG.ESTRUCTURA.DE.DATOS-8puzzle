#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include "Nodo4.h"

using namespace std;

enum Color {
    NEGRO = 0,
    AZUL = 1,
    VERDE = 2,
    CIAN = 3,
    ROJO = 4,
    MAGENTA = 5,
    AMARILLO = 6,
    BLANCO = 7,
    GRIS = 8
};

void setColor(Color texto, Color fondo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), fondo * 16 + texto);
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void centrarTexto(int longitudTexto) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

    int x = (csbi.dwSize.X - longitudTexto) / 2;
    int y = csbi.dwCursorPosition.Y;

    gotoxy(x, y);
}

void resetColor() {
    setColor(BLANCO, NEGRO);
}

void cambiarTamanoFuente(int size) {
    CONSOLE_FONT_INFOEX info = { sizeof(info) };
    GetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &info);
    info.dwFontSize = { 0, size };
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &info);
}

void cambiarTamanioConsola(int ancho, int alto) {
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Cambiar el tamaño del búfer de pantalla
    COORD tamanoBuffer = { static_cast<short>(ancho), static_cast<short>(alto) };
    SetConsoleScreenBufferSize(hConsola, tamanoBuffer);

    // Cambiar el tamaño de la ventana de la consola
    SMALL_RECT rect;
    rect.Left = 0;
    rect.Top = 0;
    rect.Right = static_cast<short>(ancho - 1);
    rect.Bottom = static_cast<short>(alto - 1);
    SetConsoleWindowInfo(hConsola, TRUE, &rect);
}

int main() {
    srand(time(NULL));
    int n;
    n = 1 + rand() % (6 - 1);
    Nodo4* nodo1;
    Nodo4* nodo2;
    Nodo4* nodo3;
    Nodo4* nodo4;
    Nodo4* nodo5;
    Nodo4* nodo6;
    Nodo4* nodo7;
    Nodo4* nodo8;
    Nodo4* nodo9;
    Nodo4* posicionActual;
    switch (n) {
    case 1:
        nodo1 = crearNodo(6);
        nodo2 = crearNodo(3);
        nodo3 = crearNodo(1);
        nodo4 = crearNodo(5);
        nodo5 = crearNodo(4);
        nodo6 = crearNodo(7);
        nodo7 = crearNodo(8);
        nodo8 = crearNodo(2);
        nodo9 = crearNodo(9);
        posicionActual = nodo9;
        break;
    case 2:
        nodo1 = crearNodo(7);
        nodo2 = crearNodo(5);
        nodo3 = crearNodo(9);
        nodo4 = crearNodo(3);
        nodo5 = crearNodo(2);
        nodo6 = crearNodo(6);
        nodo7 = crearNodo(1);
        nodo8 = crearNodo(8);
        nodo9 = crearNodo(4);
        posicionActual = nodo3;
        break;
    case 3:
        nodo1 = crearNodo(8);
        nodo2 = crearNodo(4);
        nodo3 = crearNodo(2);
        nodo4 = crearNodo(7);
        nodo5 = crearNodo(3);
        nodo6 = crearNodo(1);
        nodo7 = crearNodo(9);
        nodo8 = crearNodo(5);
        nodo9 = crearNodo(6);
        posicionActual = nodo7;
        break;
    case 4:
        nodo1 = crearNodo(7);
        nodo2 = crearNodo(8);
        nodo3 = crearNodo(6);
        nodo4 = crearNodo(5);
        nodo5 = crearNodo(4);
        nodo6 = crearNodo(2);
        nodo7 = crearNodo(9);
        nodo8 = crearNodo(3);
        nodo9 = crearNodo(1);
        posicionActual = nodo7;
        break;
    case 5:
        nodo1 = crearNodo(8);
        nodo2 = crearNodo(6);
        nodo3 = crearNodo(5);
        nodo4 = crearNodo(7);
        nodo5 = crearNodo(2);
        nodo6 = crearNodo(3);
        nodo7 = crearNodo(1);
        nodo8 = crearNodo(9);
        nodo9 = crearNodo(4);
        posicionActual = nodo8;
        break;
    }

    nodo1->set_derecha(nodo2);
    nodo2->set_izquierda(nodo1);
    nodo2->set_derecha(nodo3);
    nodo3->set_izquierda(nodo2);
    nodo4->set_derecha(nodo5);
    nodo5->set_izquierda(nodo4);
    nodo5->set_derecha(nodo6);
    nodo6->set_izquierda(nodo5);
    nodo7->set_derecha(nodo8);
    nodo8->set_izquierda(nodo7);
    nodo8->set_derecha(nodo9);
    nodo9->set_izquierda(nodo8);

    nodo1->set_abajo(nodo4);
    nodo2->set_abajo(nodo5);
    nodo3->set_abajo(nodo6);
    nodo4->set_arriba(nodo1);
    nodo5->set_arriba(nodo2);
    nodo6->set_arriba(nodo3);
    nodo4->set_abajo(nodo7);
    nodo5->set_abajo(nodo8);
    nodo6->set_abajo(nodo9);
    nodo7->set_arriba(nodo4);
    nodo8->set_arriba(nodo5);
    nodo9->set_arriba(nodo6);
    int intentos = 0;
    int sumaNodosVisitados = 0;

    while (true) {
        system("cls");
        cambiarTamanoFuente(50); 
        setColor(BLANCO, NEGRO);
         int anchoConsola = 80; 
    int centrarX = (anchoConsola - 35) / 2;
    centrarTexto(73);
    
	gotoxy(centrarX, 0);
    setColor(CIAN, NEGRO);
        cout << "-----------------------------------------------------------------------------" << endl;
		cout << endl;
        centrarTexto(75);
    setColor(AMARILLO, NEGRO);
        cout << "--------------------------JUEGO DE 8 PUZZLE----------------------------------" << endl;
        cout << endl;
        resetColor();
        centrarTexto(75);
        setColor(CIAN, NEGRO);
        cout << "-----------------------------------------------------------------------------" << endl;
        centrarTexto(0);
        cout << endl;
         centrarTexto(73);
         setColor(ROJO, NEGRO);
        cout << "Instrucciones:" << endl;
        centrarTexto(60);
        cout << "Usa las teclas (w, a, s, d) para moverte. Presiona 'q' para salir." << endl;
        cout << endl;
        centrarTexto(40);
        resetColor();
        cout << "Usted se encuentra en el valor [" << posicionActual->get_valor() << "]" << endl;
        cout << endl;
      
        centrarTexto(20);
        cout << " [" << nodo1->get_valor() << "] [" << nodo2->get_valor() << "] [" << nodo3->get_valor() << "]" << endl;
        centrarTexto(20);
        cout << " [" << nodo4->get_valor() << "] [" << nodo5->get_valor() << "] [" << nodo6->get_valor() << "]" << endl;
         centrarTexto(20);
        cout << " [" << nodo7->get_valor() << "] [" << nodo8->get_valor() << "] [" << nodo9->get_valor() << "]" << endl;
        cout << endl;
        centrarTexto(30);
        cout << "Numero de movimientos: " << intentos << endl;
        cout<<endl<<endl<<endl;
        
        centrarTexto(23);
        setColor(ROJO, ROJO);
        cout<<"|-------|";
        centrarTexto(5);
        setColor(BLANCO, BLANCO);
        cout<<"|-------|";
        centrarTexto(-13);
        setColor(ROJO, ROJO);
        cout<<"|-------|"<<endl;
        centrarTexto(23);
        setColor(ROJO, ROJO);
        cout<<"|-------|";
        centrarTexto(5);
        setColor(BLANCO, BLANCO);
        cout<<"|-------|";
        centrarTexto(-13);
        setColor(ROJO, ROJO);
        cout<<"|-------|"<<endl;
        centrarTexto(23);
        setColor(ROJO, ROJO);
        cout<<"|-------|";
        centrarTexto(5);
        setColor(BLANCO, BLANCO);
        cout<<"|-------|";
        centrarTexto(-13);
        setColor(ROJO, ROJO);
        cout<<"|-------|"<<endl;
        centrarTexto(23);
        setColor(ROJO, ROJO);
        cout<<"|-------|";
        centrarTexto(5);
        setColor(BLANCO, BLANCO);
        cout<<"|-------|";
        centrarTexto(-13);
        setColor(ROJO, ROJO);
        cout<<"|-------|"<<endl;
        centrarTexto(23);
        setColor(ROJO, ROJO);
        cout<<"|-------|";
        centrarTexto(5);
        setColor(BLANCO, BLANCO);
        cout<<"|-------|";
        centrarTexto(-13);
        setColor(ROJO, ROJO);
        cout<<"|-------|"<<endl;
        centrarTexto(23);
        setColor(ROJO, ROJO);
        cout<<"|-------|";
        centrarTexto(5);
        setColor(BLANCO, BLANCO);
        cout<<"|-------|";
        centrarTexto(-13);
        setColor(ROJO, ROJO);
        cout<<"|-------|"<<endl;
        centrarTexto(23);        
        resetColor();
        char tecla = _getch();

        Nodo4* nuevoPosicion = NULL;

        switch (tecla) {
        case 'w':
            nuevoPosicion = posicionActual->get_arriba();
            break;
        case 's':
            nuevoPosicion = posicionActual->get_abajo();
            break;
        case 'a':
            nuevoPosicion = posicionActual->get_izquierda();
            break;
        case 'd':
            nuevoPosicion = posicionActual->get_derecha();
            break;
        case 'q':
            delete nodo1;
            delete nodo2;
            delete nodo3;
            delete nodo4;
            delete nodo5;
            delete nodo6;
            delete nodo7;
            delete nodo8;
            delete nodo9;
            exit(0);
        default:
            cout << "ERROR" << endl;
        }

        if (nuevoPosicion != NULL) {
            intercambiarNodos(posicionActual, nuevoPosicion);
            posicionActual = nuevoPosicion;
            intentos++;
        }

        if (!posicionActual->get_visitado()) {
            posicionActual->set_visitado(true);
            sumaNodosVisitados += posicionActual->get_valor();
        }

        if (esMatrizFinal(nodo1, nodo2, nodo3, nodo4, nodo5, nodo6, nodo7, nodo8, nodo9)) {
            cout << "Felicidades. Has resuelto el puzzle." << endl;
            break; // Salir del bucle
        }
    }

    return 0;
}

