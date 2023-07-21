
#ifndef CPU_H
#define CPU_H
#include "Mano.h"
#include <random>
class Cpu : public Mano
{
public:
	Cpu(Baraja&, int = 7, string = "Cpu");
	virtual void posicionarCartas(sf::RenderWindow&);
	bool seleccionarCarta(Pila &, Baraja &, sf::RenderWindow&);
};
#endif

