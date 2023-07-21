#include "Jugador.h"

Jugador::Jugador(Baraja& b, int n, string nom) : Mano(b, n)
{
	nombre = nom;
}

bool Jugador::detectaClickCartas(int x, int y, Pila &p)
{
	for (int i = 0; i < mano.size(); i++)
	{
		if (sprites[i].getGlobalBounds().contains(x, y) && mano[i].valida(p))
		{
			return true;
		}
	}
	return false;
}

Carta Jugador::seleccionarCarta(int x, int y, Pila& p, sf::RenderWindow& ventana)
{
	for (int i = 0; i < mano.size(); i++)
	{
		if (sprites[i].getGlobalBounds().contains(x, y))
		{
			Carta c = removerCarta(i, p);
			posicionarCartas(ventana);
			return c;
		}

	}
}

void Jugador::posicionarCartas(sf::RenderWindow& window)
{

	for (int i = 0; i < mano.size(); i++)
	{
		
		sprites[i].setScale(0.4 * (1.1 - (0.025 * mano.size())), 0.4 * (1.1 - (0.025 * mano.size())));
		sprites[i].setPosition(250 * 0.4 * (1.1 - (0.025 * mano.size())) * i + 15, 500);
	}

}

