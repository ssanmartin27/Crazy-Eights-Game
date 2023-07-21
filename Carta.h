#ifndef CARTA_H
#define CARTA_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
class Pila;
class Carta
{
	public:
		enum Palo {TREBOLES, DIAMANTES, CORAZONES, PICAS};
		Carta(sf::Sprite = sf::Sprite(), Palo = TREBOLES, int= 1);
		~Carta();
		sf::Sprite getSprite() const;
		Palo getPalo() const;
		int getValor() const;
		bool valida(Pila &) const;

	private:
		Palo palo;
		int valor;
		sf::Sprite sprite;
		

};
#endif
