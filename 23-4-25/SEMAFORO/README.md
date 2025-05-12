# SEMAFORO
Este sistema controla dos semáforos usando un ESP32, donde ambos semáforos funcionan de manera sincronizada, pero en sincronización inversa. Esto significa que cuando un semáforo está en verde, el otro está en rojo, y viceversa.

El control de estos semáforos se logra utilizando un mecanismo de semáforo (en este caso un mutex), que actúa como una "llave" para asegurarse de que solo una tarea pueda modificar el estado de los semáforos a la vez. Cuando una tarea está cambiando las luces de un semáforo, la otra tarea tiene que esperar hasta que termine. Esto previene que ambos semáforos cambien sus luces al mismo tiempo y asegura que siempre haya una secuencia ordenada de luces.

En resumen, los semáforos se manejan en sincronización inversa, controlando las luces de ambos semáforos de manera coordinada y evitando conflictos, lo cual es posible gracias al uso del semáforo (mutex) que regula el acceso a la modificación de los estados de las luces.