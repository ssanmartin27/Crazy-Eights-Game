#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics.hpp>
#include "Baraja.h"
#include "Jugador.h"
#include "Cpu.h"

class Juego
{
	
public:
	Juego();
	void empezarJuego();
	bool seleccionarPalo(int, int, Pila &);
	void mostrarTexto(string, sf::RenderWindow&, int = 24, int = 530, int = 250);
	void terminarJuego(string);
	bool continuar_() const;
	

private:
	void procesarEventos();
	void actualizar();
	void renderizar();

	sf::RenderWindow ventana;
	sf::Sprite spriteBaraja;
	sf::Sprite spritePila;
	sf::Texture texturaBaraja;
	sf::Texture texturaPalos;
	sf::Texture texturaIconos;
	sf::Sprite spritesPalos[4];
	sf::Font fuente;
	sf::Sprite spriteContinuar;
	sf::Sprite spriteSalir;
	Baraja baraja;
	Jugador jugador;
	Cpu cpu;
	Pila pila;
	bool mostrarPalos;
	bool turnoJugador;
	string palos[4] = { "Treboles", "Diamantes", "Corazones", "Picas" };
	bool continuar;
	bool juegoTermino;
};
#endif
