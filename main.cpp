#include "Pila.h"
#include "Mano.h"
#include "Juego.h"

int main()
{
	bool continuar;
	do
	{
		Juego juego;
		juego.empezarJuego();
		continuar = juego.continuar_();
	} while (continuar);
}

