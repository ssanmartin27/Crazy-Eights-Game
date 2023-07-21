#ifndef BARAJA_H
#define BARAJA_H
#include "Carta.h"
#include "Pila.h"
#include <SFML/Graphics.hpp>
class Baraja
{
public:
	Baraja();
	void mezclarBaraja();
	Carta sacarCarta();
	int numCartas();
	void remezclarCartas(Pila);
	

private:
	Carta cartas[52];
	int siguienteCarta;
	sf::Texture textura;
	
};
#endif

