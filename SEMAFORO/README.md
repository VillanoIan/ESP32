# SEMAFORO

En este README vas a encontrar cómo es el conexionado del semáforo.

Usamos una protoboard para armar el circuito de los semáforos. Primero conecté los dos semáforos de una forma cómoda sobre la placa para que el cableado fuera más sencillo. Después, sumamos el ESP32, también ubicado de forma eficiente. Desde ahí, salieron cables macho-macho que van directo del ESP32 a los LEDs de los semáforos.

Una vez listo el armado, conectamos el ESP32 a la computadora y abrimos el Arduino IDE, ya configurado con la placa ESP32 (ESP32 Dev Module). A partir de ahí, cargamos el código que se encuentra en la carpeta CODIGOS.

En resumen, el funcionamiento del programa consiste en que cada semáforo sigue un mismo tipo de patrón de luces (rojo, amarillo, verde), pero de forma inversa entre sí: cuando uno está en rojo, el otro está en verde, y así sucesivamente, manteniendo la sincronización y los tiempos adecuados.

Acá abajo dejo una imagen del circuito ya armado en la protoboard:
![Imagen de WhatsApp 2025-04-29 a las 16 26 52_acec2578](https://github.com/user-attachments/assets/b5d43555-dc63-4983-abf5-65cc3be9fb40)
