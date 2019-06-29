//
// Created by utec on 28/06/19.
//

#include "Objeto.h"


Objeto::Objeto(): color{}, posX{}, posY{}  {}

Objeto::Objeto(const string& nombre, char color,
               int posX, int posY):
        nombre{nombre}, color{color},
        posX{posX}, posY{posY} {}

Objeto::~Objeto() {}

void Objeto::setNombre(const string& nombre) { this->nombre = nombre; }
void Objeto::moverse(int x, int y) {} //--  por implementar

string  Objeto::getNombre() { return nombre; }
int   Objeto::getPosX()   { return posX; }
int  Objeto::getPosY()   { return posY; }
char Objeto::getColor()  { return color; }

string Objeto::mostrarPosicion() {
    return "X = " + to_string(posX) + " Y = " + to_string(posY);
}