#include "Juego.h"

Juego::Juego() : ventana(sf::VideoMode(1152, 648), "Ocho loco", sf::Style::Close), baraja(), jugador(baraja, 7), cpu(baraja, 7), pila(baraja)
{
	texturaBaraja.loadFromFile("card_back.png");
	texturaPalos.loadFromFile("palos.png");
	texturaIconos.loadFromFile("si_no.png");
	sf::Sprite sprite;
	sprite.setTexture(texturaPalos);

	for (int i = 0; i < 4; i++)
	{
		sprite.setTextureRect(sf::IntRect(230*i, 0, 230, 300));
		sprite.setScale(0.8, 0.8);
		sprite.setPosition(150 + 240 * i, 220);
		spritesPalos[i] = sprite;
	}
	spriteContinuar.setTexture(texturaIconos);
	spriteContinuar.setTextureRect(sf::IntRect(0, 0, 151, 150));
	spriteContinuar.setPosition(350, 400);

	spriteSalir.setTexture(texturaIconos);
	spriteSalir.setTextureRect(sf::IntRect(151, 0, 151, 150));
	spriteSalir.setPosition(700, 400);

	spriteBaraja.setTexture(texturaBaraja);
	spriteBaraja.scale(0.3, 0.3);
	spriteBaraja.setPosition(1000, 270);
	jugador.posicionarCartas(ventana);
	cpu.posicionarCartas(ventana);
	mostrarPalos = false;
	continuar = false;
	turnoJugador = true;
	juegoTermino = false;
	fuente.loadFromFile("arial.ttf");
	
	
}

void Juego::empezarJuego()
{
	while (ventana.isOpen())
	{
		procesarEventos();
		actualizar();
		renderizar();
		if (juegoTermino)
			break;
	}
}

void Juego::procesarEventos()
{
	sf::Event evento;
	while(ventana.pollEvent(evento))
	{
		if (evento.type == sf::Event::Closed)
			ventana.close();
		else if (evento.type == sf::Event::MouseButtonPressed)
		{
			if ((evento.mouseButton.button == sf::Mouse::Left) && turnoJugador == true)
			{

				if (mostrarPalos)
				{
					if (seleccionarPalo(evento.mouseButton.x, evento.mouseButton.y, pila))
						turnoJugador = false;
				}

				else if (spriteBaraja.getGlobalBounds().contains(evento.mouseButton.x, evento.mouseButton.y))
				{
					
					jugador.agregarCarta(baraja);
					jugador.posicionarCartas(ventana);

					
				}

				else if (jugador.detectaClickCartas(evento.mouseButton.x, evento.mouseButton.y, pila))
				{
					Carta c = jugador.seleccionarCarta(evento.mouseButton.x, evento.mouseButton.y, pila, ventana);
					if (c.getValor() == 8)
					{
						mostrarPalos = true;
					}
					else {
						turnoJugador = false;
					}
				}
				
			}
		}
	}
}

void Juego::actualizar()
{
	spritePila = pila.getCartaActual().getSprite();
	spritePila.setOrigin(230 * 0.4, 230 * 0.4);
	spritePila.setPosition(576, 324);
	if (baraja.numCartas() <= 0) {
		baraja.remezclarCartas(pila);
	}
	
}

void Juego::renderizar()
{
	ventana.clear(sf::Color(0,204,102));
	jugador.mostrarCartas(ventana);
	cpu.mostrarCartas(ventana);
	ventana.draw(spritePila);
	ventana.draw(spriteBaraja);

	if (pila.getCartaActual().getValor() == 8 && !mostrarPalos)
	{
		
		mostrarTexto(palos[pila.getPaloActual()], ventana);
	}
	if (mostrarPalos)
	{
		for (int i = 0; i < 4; i++)
		{
			ventana.draw(spritesPalos[i]);
		}
	}
	
	ventana.display();
	if (!turnoJugador)
	{
		if (cpu.seleccionarCarta(pila, baraja, ventana))
		{

			turnoJugador = true;
		}
		
	}
	
	if (jugador.tamanio() <= 0)
	{
		terminarJuego(jugador.getNombre());
	}
	else if (cpu.tamanio() <= 0)
	{
		terminarJuego(cpu.getNombre());
	}
	
}
	

bool Juego::seleccionarPalo(int x, int y, Pila &p)
{
	for (int i = 0; i< 4; i++)
	{
		if (spritesPalos[i].getGlobalBounds().contains(x, y))
		{
			mostrarPalos = false;
			jugador.cambiarPalo(i, pila);
			return true;
			
		}
	}
	return false;
}

void Juego::mostrarTexto(string mensaje, sf::RenderWindow &ventana, int tamanio, int x, int y)
{ 
	sf::Text texto;
	texto.setFont(fuente); 
	texto.setPosition(x, y);
	texto.setString(mensaje);
	texto.setCharacterSize(tamanio); 
	texto.setFillColor(sf::Color::Blue);
	texto.setStyle(sf::Text::Bold);
	ventana.draw(texto);
}


void Juego::terminarJuego(string nombre)
{
	juegoTermino = true;
	while (ventana.isOpen())
	{


		sf::sleep(sf::seconds(1));
		sf::Event evento2;
		while (ventana.pollEvent(evento2))
		{
			if (evento2.type == sf::Event::Closed)
				ventana.close();
			else if (evento2.type == sf::Event::MouseButtonPressed)
			{
				if (evento2.mouseButton.button == sf::Mouse::Left)
				{
					if (spriteContinuar.getGlobalBounds().contains(evento2.mouseButton.x, evento2.mouseButton.y))
					{
						continuar = true;
						return;
					}
					else if (spriteSalir.getGlobalBounds().contains(evento2.mouseButton.x, evento2.mouseButton.y))
					{
						continuar = false;
						return;
					}
						
				}
			}
		}
		ventana.clear(sf::Color(29, 128, 59));
		string mensaje = nombre + " gana";
		mostrarTexto(mensaje, ventana, 80, 420, 140);
		mostrarTexto("¿Intentar nuevamente?", ventana, 50, 330, 240);
		ventana.draw(spriteContinuar);
		ventana.draw(spriteSalir);
		ventana.display();
		
	}

}

bool Juego::continuar_() const
{
	return continuar;
}

