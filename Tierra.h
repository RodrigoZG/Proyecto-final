//
// Created by utec on 28/06/19.
//

#ifndef JUEGO_TIERRA_H
#define JUEGO_TIERRA_H

#include <iostream>
#include <vector>
#include "Objeto.h"
#include <SFML/Graphics.hpp>

using namespace std;

const int ALTURA = 21;
const int ANCHO  = 21;
const char COLOR ='.';

class Tierra {
private:
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
public:
    Tierra();
    Tierra(int altura, int ancho);
    virtual ~Tierra();
    void adicionarObjeto(Objeto* objeto);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    int getAltura();
    int getAncho();
    int getCantidadObjetos();
    void dibujarTierra();
    void actualizarTierra();
};

#endif //JUEGO_TIERRA_H
