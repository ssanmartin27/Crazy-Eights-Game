#include "Carta.h"
#include "Pila.h"

Carta::Carta(sf::Sprite s, Palo p, int v)
{
	sprite = s;
	palo = p;
	valor = v;
}

Carta::~Carta()
{
}
Carta::Palo Carta::getPalo() const
{
	return palo;
}
int Carta::getValor() const
{
	return valor;
}
sf::Sprite Carta::getSprite() const
{
	return sprite;
}


bool Carta::valida(Pila& p) const
{
	if (  (palo == p.getPaloActual())
		|| (valor == p.getCartaActual().getValor())
		|| (valor == 8)   )
	{
		return true;
	}
	else
	{
		return false;
	}
}

