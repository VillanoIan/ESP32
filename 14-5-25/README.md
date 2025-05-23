# AEREOPUERTO✈

Este proyecto implementa una simulación básica de un aeropuerto utilizando un ESP32 y el sistema operativo en tiempo real FreeRTOS. La simulación incluye múltiples aviones que solicitan permiso para aterrizar, una torre de control que gestiona dichas solicitudes, y varias pistas de aterrizaje gestionadas mediante semáforos.

CONEXIÓN 
Este proyecto es completamente simulado por software. No se requieren conexiones físicas externas. Toda la información se visualiza a través del Monitor Serial del IDE de Arduino.

CONFIGURACIÓN
Abrir el Arduino IDE.

Seleccionar la placa: ESP32 Dev Module.

Cargar el código al ESP32.

Conectar el ESP32 por USB y abrir el Monitor Serial.

Verificar que la salida muestre los mensajes del sistema correctamente.

BREVE DESCRIPCION
El sistema simula un aeropuerto con múltiples aviones que desean aterrizar. Utiliza FreeRTOS para administrar tareas concurrentes y colas para la comunicación entre las tareas de los aviones y la torre de control. Las pistas de aterrizaje son representadas por semáforos (mutex), que garantizan el acceso exclusivo a cada pista.



El código se encontrara en la carpeta "CÓDIGO" para que puedan ver que hace cada funcion.