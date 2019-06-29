//
// Created by utec on 28/06/19.
//

#include "Tierra.h"
#include <string>
#include <iomanip>
#include <algorithm>
#include <map>

map<char, sf::Color> colores = {
        {'R',sf::Color::Red},
        {'B',sf::Color::Blue},
        {'G',sf::Color::Green},
};

using namespace std;

Tierra::Tierra() {
    plano = nullptr;
}

Tierra::Tierra(int altura, int ancho) {
    plano = new sf::RenderWindow(
            sf::VideoMode(ancho, altura), "Proyecto Final");
}

Tierra::~Tierra() {
    delete plano;
    plano = nullptr;
}

void Tierra::adicionarObjeto(Objeto* objeto) {
    objetos.emplace_back(objeto);
}

Objeto* Tierra::removerObjeto(string& nombre) {
    // Buscando objeto:
    if (objetos.size() == 0)
        return nullptr;

    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto* obj){ return obj->getNombre() == nombre; });
    if (iter == end(objetos))
        return nullptr;
    // Eliminando objeto:
    objetos.erase(iter);
    //si encuentra al objeto lo separa del vector, pero no matará al objeto, esto se hará en el menu.
    return *iter;
}

void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto& item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    for (auto& item: objetos){
        sf::CircleShape shape(10);
        shape.setFillColor(colores[item->getColor()]);
        shape.setPosition(item->getPosX(),item->getPosY());
        plano->draw(shape);
    }
}

void Tierra::dibujarTierra() {
    if (plano == nullptr) return;
    while (plano->isOpen())
    {
        sf::Event event;
        while (plano->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                plano->close();
        }
        plano->clear();
        actualizarTierra();
        plano->display();
    }
}

int Tierra::getAltura() {
    return plano->getPosition().y;
}

int Tierra::getAncho(){
    return plano->getPosition().x;
}
