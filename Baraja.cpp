#include "Baraja.h"
#include <random>


Baraja::Baraja()
{
	siguienteCarta = 0;
	textura.loadFromFile("cartas.png");
	sf::Sprite sprite;
	sprite.setTexture(textura);
	int i = 0;
	for (int palo = 0; palo < 4; palo++)
	{
		for (int valor = 1; valor <= 13; valor++)
		{	
			sprite.setTextureRect(sf::IntRect(230*(valor-1),300*palo,230,300));
			sprite.setScale(0.4, 0.4);
			Carta aux(sprite, Carta::Palo(palo), valor);
			cartas[i++] = aux;
		}
	}
	mezclarBaraja();
}

Carta Baraja::sacarCarta()
{
	if (numCartas() > 0)
	{
		return cartas[siguienteCarta++];
	}
}

int Baraja::numCartas()
{
	return 52 - siguienteCarta;
}

void Baraja::mezclarBaraja()
{
	random_device rd;
	mt19937 generador(rd());
	int n = 52;
	int az;
	Carta tmp;
	for (int i = n-1; i > siguienteCarta; i--)
	{
		uniform_int_distribution<> rango(siguienteCarta, i);
		az = rango(generador);
		tmp = cartas[az];
		cartas[az] = cartas[i];
		cartas[i] = tmp;
	}
}

void Baraja::remezclarCartas(Pila p)
{	
	int i = 52 - p.getHistorial().size();
	int j = 0;
	siguienteCarta = i;
	for (i, j; i < 52; i++, j++)
	{
		cartas[i] = (p.getHistorial())[j];
	}
	mezclarBaraja();



}