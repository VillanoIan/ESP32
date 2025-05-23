# SEMÁFORO🚦
Este proyecto utiliza el ESP32 para controlar dos semáforos, implementando el concepto de sincronización de tareas mediante un mutex (semaforo). Los semáforos se controlan de forma inversa, es decir, cuando un semáforo está en verde, el otro está en rojo, y viceversa.

Funcionamiento básico:
Conexiónado:

Los LEDs de los semáforos se conectan a los pines del ESP32 de acuerdo con la configuración indicada:

Semáforo 1: Rojo (pin 26), Amarillo (pin 27), Verde (pin 33)

Semáforo 2: Rojo (pin 18), Amarillo (pin 19), Verde (pin 21)

Asi les debe quedar:

![image](https://github.com/user-attachments/assets/375c475a-2c12-45f8-aff8-e67d6ed972cb)


Mutex (Semáforo):
Se crea un mutex para garantizar que solo una tarea acceda a los semáforos a la vez. Esto sincroniza las operaciones, de manera que cuando un semáforo cambia de estado (por ejemplo, de verde a amarillo), el otro semáforo no puede hacerlo hasta que la tarea que lo controla haya liberado el mutex.

Sincronización inversa:
El funcionamiento de los semáforos es inverso: cuando el primer semáforo está en rojo, el segundo está en verde; cuando el primer semáforo está en verde, el segundo está en rojo. Esto se logra mediante la sincronización de tareas usando el mutex.

Tareas del semáforo:

Semáforo 1: Cambia de estado entre rojo, verde y amarillo en un ciclo de tiempo determinado (rojo por 4 segundos, verde por 3 segundos y amarillo por 1 segundo).

Semáforo 2: Sigue el mismo ciclo pero en sentido inverso: el verde del Semáforo 1 es el rojo del Semáforo 2, y viceversa.

Para saber cada funcion del codigo, lo podes ver con mas detalle en la carpeta "CODIGOS"
