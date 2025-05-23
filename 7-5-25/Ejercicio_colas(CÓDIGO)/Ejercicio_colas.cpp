#include "data.h" // Llamamos a la librería
QueueHandle_t myQueue; // Definimos la cola

void setup() {
  Serial.begin(115200);
  delay(1000);
  myQueue = xQueueCreate(30, sizeof(Person)); // Creamos y asignamos el tamaño de la cola

  xTaskCreatePinnedToCore(
    Productor,       // Referencia a la función que vamos a ejecutar
    "Task_Core0",    // Nombre de la tarea (solo para propósitos de depuración)
    4096,            // Tamaño del stack de la tarea
    NULL,            // Parámetro que recibe la función
    1,               // Prioridad de la tarea
    NULL,            // No es importante en este caso
    1                // Núcleo donde queremos que corra la tarea (core 1)
  );

  xTaskCreatePinnedToCore(
    Consumidor,      // Referencia a la función que vamos a ejecutar
    "Task_Core1",    // Nombre de la tarea (solo para propósitos de depuración)
    4096,            // Tamaño del stack de la tarea
    NULL,            // Parámetro que recibe la función
    1,               // Prioridad de la tarea
    NULL,            // No es importante en este caso
    0                // Núcleo donde queremos que corra la tarea (core 0)
  );
}

void Productor(void *parameter) {
  // Función del productor: envía datos tomados desde la librería data.cpp
  Person pipol;
  for (;;) {
    int Id = randomId();               // Obtenemos un ID aleatorio
    pipol = getPersonById(Id);        // Obtenemos la persona con ese ID
    xQueueSend(myQueue, &pipol, portMAX_DELAY); // Enviamos el dato a la cola
  }
}

void Consumidor(void *parameter) {
  // Función del consumidor: recibe datos enviados por el productor y los muestra por la terminal
  for (;;) {
    Person persona;
    xQueueReceive(myQueue, &persona, portMAX_DELAY); // Recibe los datos de la cola
    Serial.printf("Id: ");
    Serial.println(persona.id);
    Serial.printf("Nombre: ");
    Serial.println(persona.name);
    Serial.printf("Apellido: ");
    Serial.println(persona.last_name);
    Serial.printf("Email: ");
    Serial.println(persona.email);
    Serial.println("-----------------------");
  }
}

// No se utiliza
void loop() {
  // Código principal que se ejecutaría repetidamente (no se usa en este proyecto)
}
