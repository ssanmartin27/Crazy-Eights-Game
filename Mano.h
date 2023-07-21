#ifndef MANO_H
#define MANO_H
#include "Baraja.h"
#include "Pila.h"
#include <vector>
class Juego;
class Mano
{
public:
	Mano(Baraja&, int = 7);
	void agregarCarta(Baraja&);
	Carta removerCarta(int, Pila &);
	int tamanio() const;
	virtual void posicionarCartas(sf::RenderWindow &) = 0;
	void mostrarCartas(sf::RenderWindow&);
	void cambiarPalo(int, Pila&);
	string getNombre() const;

protected:
	vector<Carta> mano;
	vector<sf::Sprite> sprites;
	string nombre;
};
#endif
