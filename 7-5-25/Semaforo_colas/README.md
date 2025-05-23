# SEMÁFORO UTILIZANDO COLAS🚦 
En este documento vas a encontrar cómo es el conexionado del semáforo y una explicación de su funcionamiento.

CONEXIÓN:
Utilizamos un protoboard donde debe ir conectado el ESP32 junto con los tres LEDs que representan el semáforo, de la siguiente manera:

- LED rojo → Pin GPIO 26
- LED amarillo → Pin GPIO 25
- LED verde → Pin GPIO 33
- Las resistencias necesarias para cada LED se conectan en serie.
- Los extremos negativos de los LEDs van conectados a GND.

CONFIGURACIÓN:
1. Abrir el Arduino IDE.
2. Seleccionar la placa: ESP32 Dev Module.
3. Cargar el código al ESP32.
4. Verificar que esté todo correctamente conectado antes de ejecutar.

FUNCIONAMIENTO:
El semáforo enciende y apaga sus luces según una secuencia definida en el código, que utiliza una estructura llamada "colas" provista por FreeRTOS (el sistema operativo en tiempo real del ESP32).

El codigo se puede encontrar en la carpetas "CÓDIGO" del repositorio ESP32.

El programa se divide en dos tareas principales:

- Productor:
  Genera comandos aleatorios (LED rojo, verde, amarillo o parpadeo de todos) y los envía a la cola.

- Consumidor:
  Recibe esos comandos desde la cola y los ejecuta, encendiendo el LED correspondiente.

Cuando el comando es LED_BLINK (parpadeo), se le da prioridad y se coloca al inicio de la cola, de modo que se ejecute antes que otros comandos ya en espera.

Para saber cada funcion del codigo, puedes encontrarlo en la carpeta "CODIGOS" con comentarios explicando ciertas funciones
