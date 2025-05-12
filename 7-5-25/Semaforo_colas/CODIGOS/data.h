#ifndef DATA_H
#define DATA_H

#include <Arduino.h>
// Definimos los posibles comandos que puede ejecutar el semáforo
enum LedCommand
{
    LED_RED,    // Enciende el LED rojo
    LED_GREEN,  // Enciende el LED verde
    LED_YELLOW, // Enciende el LED amarillo
    LED_BLINK   // Parpadean los 3 LEDs
};

// Devuelve un comando LED aleatorio
LedCommand randomCommand();

#endif
