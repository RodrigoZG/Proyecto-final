//
// Created by utec on 28/06/19.
//

#ifndef JUEGO_OBJETO_H
#define JUEGO_OBJETO_H

#include <iostream>
#include <string>

using namespace std;

class Objeto{;
private:
    string nombre;
    char  color;
    int    posX;
    int    posY;
public:
    Objeto();
    Objeto(const string& nombre, char color,
           int posX, int posY);
    virtual ~Objeto();
    void setNombre(const string& nombre);
    string     getNombre();
    int getPosX();
    int getPosY();
    char getColor();
    void moverse(int x, int y);
    string mostrarPosicion();
};


#endif //JUEGO_OBJETO_H