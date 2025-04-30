# SEMAFORO

En este README vas a encontrar cómo es el conexionado del semáforo.

Utilizamos un proto para poder armar los semaforos. Primero conecte los dos semaforos de una forma comoda al proto para poder hacer el conexionado mas facil. Despues conectamos el ESP32 para de la misma manera que el semaforo, de esta salen cables macho-macho que van del ESP32 al semaforo. Despues este va conectado a la pc junto con el programa Arduino IDE configurado para el ESP32(DEV MODULE ESP32). De ahi el siguiente paso fue programar el funcionamiento de este que se encuentra explicado funcion por funcion en la carpetas codigos, pero de una fomra resumida, estos complen un patro en donde deben sincronizarse de una manera especifica y respetando bien los tiempos.
A continuacion les dejo una imagen del circuito armado en un protoboard: 
![Imagen de WhatsApp 2025-04-29 a las 16 26 52_acec2578](https://github.com/user-attachments/assets/b5d43555-dc63-4983-abf5-65cc3be9fb40)
