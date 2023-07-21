#include "Pila.h"

Pila::Pila(Baraja& b)
{
	Carta inicial = b.sacarCarta();
	cartaActual = inicial;
	paloActual = inicial.getPalo();
}


Carta Pila::getCartaActual() const
{
	return cartaActual;
}

void Pila::recibirCarta(Carta &c) 
{
	historial.push_back(cartaActual);
	cartaActual = c;
	paloActual = c.getPalo();
}

Carta::Palo Pila::getPaloActual() const
{
	return paloActual;
}

void Pila::setPaloActual(Carta::Palo palo)
{
	paloActual = palo;
}

vector<Carta> Pila::getHistorial() const
{
	return historial;
}

