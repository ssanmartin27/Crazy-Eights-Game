#ifndef PILA_H
#define PILA_H
#include "Baraja.h"
#include <vector>


class Carta;
class Baraja;
class Pila
{
	
public:
	Pila(Baraja&);
	Carta getCartaActual() const;
	void recibirCarta(Carta&);
	Carta::Palo getPaloActual() const;
	void setPaloActual(Carta::Palo);
	vector<Carta> getHistorial() const;
	
private:
	vector<Carta> historial;
	Carta cartaActual;
	Carta::Palo paloActual;

};
#endif

