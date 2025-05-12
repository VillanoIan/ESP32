#include "data.h" // Librería donde se definen las funciones de los colores del semáforo

#define ROJO 26
#define AMARILLO 25 // Definimos el color y en qué posición van
#define VERDE 33

QueueHandle_t myQueue;//Declaro la cola.

void setup() {//Indicamos en donde van conectadas y como.
  pinMode(ROJO, OUTPUT);
  pinMode(AMARILLO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  Serial.begin(115200);
  delay(1000);
  myQueue = xQueueCreate(30, sizeof(LedCommand));
  
  xTaskCreatePinnedToCore( // Creamos los cores
    Productor,     // Referencia a la función que vamos a ejecutar
    "Task_Core0",  // Nombre para la función, sirve solamente para propósitos de depuración
    4096,          // Tamaño del stack de la tarea
    NULL,          // Parámetro que recibe la función que le vamos a pasar
    1,             // Prioridad de la tarea
    NULL,          // No es importante
    1              // El core donde queremos que corra la tarea (0/1)
  );

  xTaskCreatePinnedToCore(
    Consumidor,    // Referencia a la función que vamos a ejecutar
    "Task_Core1",  // Nombre para la función, sirve solamente para propósitos de depuración
    4096,          // Tamaño del stack de la tarea
    NULL,          // Parámetro que recibe la función que le vamos a pasar
    1,             // Prioridad de la tarea
    NULL,          // No es importante
    0              // El core donde queremos que corra la tarea (0/1)
  );
}

void Productor(void *parameter) { // Función donde vamos a indicar qué colores deben prenderse y de qué manera
  for (;;) {
    LedCommand Commands = randomCommand();
    if (Commands == LED_BLINK) { // Condición: si se ejecuta el comando LED_BLINK, se envía a la primera posición de la cola (tiene prioridad)
      xQueueSendToFront(myQueue, &Commands, 0);
    } else { // Si no se cumple, se envía normalmente
      xQueueSend(myQueue, &Commands, portMAX_DELAY);
    }
  }
}

void Consumidor(void *parameter) { // Recibe la función del Productor y la ejecuta
  for (;;) {
    LedCommand color;
    xQueueReceive(myQueue, &color, portMAX_DELAY); // Recibe la cola de comandos
    Serial.printf("Color: "); // Mostramos por la terminal los datos
    Serial.println(color);
    
    if (color == LED_RED) { // Condición: si recibe el comando LED_RED
      digitalWrite(ROJO, HIGH);
      delay(1000);
      digitalWrite(ROJO, LOW);
    }
    if (color == LED_YELLOW) { // Condición: si recibe el comando LED_YELLOW
      digitalWrite(AMARILLO, HIGH);
      delay(1000);
      digitalWrite(AMARILLO, LOW);
    }
    if (color == LED_GREEN) { // Condición: si recibe el comando LED_GREEN
      digitalWrite(VERDE, HIGH);
      delay(1000);
      digitalWrite(VERDE, LOW);
    }
    if (color == LED_BLINK) { // Condición: si recibe el comando LED_BLINK (prende y apaga los LEDs simultáneamente)
      digitalWrite(AMARILLO, HIGH);
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, HIGH);
      delay(200);
      digitalWrite(VERDE, LOW);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(ROJO, LOW);
      delay(200);
      digitalWrite(VERDE, HIGH);
      digitalWrite(AMARILLO, HIGH);
      digitalWrite(ROJO, HIGH);
      delay(200);
      digitalWrite(ROJO, LOW);
      digitalWrite(VERDE, LOW);
      digitalWrite(AMARILLO, LOW);
      delay(200);
      digitalWrite(VERDE, HIGH);
      digitalWrite(ROJO, HIGH);
      digitalWrite(AMARILLO, HIGH);
      delay(200);
      digitalWrite(VERDE, LOW);
      digitalWrite(AMARILLO, LOW);
      digitalWrite(ROJO, LOW);
    }
  }
}


void loop() {// No se utiliza porque usamos multitarea con FreeRTOS
}
