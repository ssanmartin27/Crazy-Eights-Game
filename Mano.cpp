#include "Mano.h"


		
Mano::Mano(Baraja &b, int n)
{
	for (int i = 0; i < n; i++)
	{
		Carta carta = b.sacarCarta();
		mano.push_back(carta);
		sprites.push_back(carta.getSprite());
	}
}

void Mano::agregarCarta(Baraja& b)
{
	if (b.numCartas() > 0)
	{
		Carta carta = b.sacarCarta();
		mano.push_back(carta);
		sprites.push_back(carta.getSprite());
		
	}
}

Carta Mano::removerCarta(int pos, Pila& p)
{
	if (mano[pos].valida(p))
	{
		Carta c = mano[pos];
		mano.erase(mano.begin() + pos);
		sprites.erase(sprites.begin() + pos);
		p.recibirCarta(c);
		return c;
	}


}


int Mano::tamanio() const
{
	return mano.size();
}


void Mano::mostrarCartas(sf::RenderWindow &window)
{
	for (int i = 0; i < mano.size(); i++)
	{
		window.draw(sprites[i]);
	}
}


void Mano::cambiarPalo(int i, Pila &p)
{
	switch (i)
	{
	case 0:
		p.setPaloActual(Carta::Palo::TREBOLES);
		break;
	case 1:
		p.setPaloActual(Carta::Palo::DIAMANTES);
		break;
	case 2:
		p.setPaloActual(Carta::Palo::PICAS);
		break;
	case 3:
		p.setPaloActual(Carta::Palo::CORAZONES);
		break;
	}
}

string Mano::getNombre() const
{
	return nombre;
}

