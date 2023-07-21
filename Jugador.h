#ifndef JUGADOR_H
#define JUGADOR_H
#include "Mano.h"
class Jugador : public Mano
{
public:
	Jugador(Baraja&, int = 7, string = "Jugador");
	bool detectaClickCartas(int, int, Pila&);
	Carta seleccionarCarta(int, int, Pila&, sf::RenderWindow&);
	virtual void posicionarCartas(sf::RenderWindow&);
};

#endif
