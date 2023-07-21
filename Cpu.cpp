#include "Cpu.h"


Cpu::Cpu(Baraja& b, int n, string nom) : Mano(b, n)
{
	nombre = nom;
}

void Cpu::posicionarCartas(sf::RenderWindow& window)
{

	for (int i = 0; i < mano.size(); i++)
	{
		sprites[i].setColor(sf::Color(0, 0, 0, 50));
		sprites[i].setScale(0.4 * (1.1 - (0.025 * mano.size())), 0.4 * (1.1 - (0.025 * mano.size())));
		sprites[i].setPosition(250 * 0.4 * (1.1 - (0.025 * mano.size())) * i + 15, 30);
	}

}

bool Cpu::seleccionarCarta(Pila& p, Baraja &b, sf::RenderWindow &ventana)
{
	sf::sleep(sf::seconds(1));
	for (int i = 0; i < mano.size(); i++)
	{
		if (mano[i].valida(p))
		{
			Carta c = removerCarta(i, p);
			if (c.getValor() == 8)
			{
				random_device rd;
				mt19937 generador(rd());
				uniform_int_distribution<> rango(0, 3);
				int numAleatorio = rango(generador);
				cambiarPalo(numAleatorio, p);
			}
			posicionarCartas(ventana);
			return true;
		}
	}
	
	agregarCarta(b);
	posicionarCartas(ventana);
	return false;
}