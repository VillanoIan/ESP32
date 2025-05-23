#define rojo 26//defino en que salida va del ESP32
#define amarillo 27
#define verde 33
#define rojo2 18
#define amarillo2 19
#define verde2 21

SemaphoreHandle_t mySemaphore;  // declaracion de la varaible que vamos a usar como semaforo

void setup() {//indico en que salida va cada color
  pinMode(rojo, OUTPUT);
  pinMode(amarillo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(rojo2, OUTPUT);
  pinMode(amarillo2, OUTPUT);
  pinMode(verde2, OUTPUT);
  Serial.begin(115200);//Printear en la terminal la salida
    mySemaphore = xSemaphoreCreateMutex(); // En este caso queremos que sea un mutex.

  xTaskCreatePinnedToCore(
    semaforo1,     // Referencia a la funcion que vamos a ejecutar
    "Task_Core1",  // Nombre para la funcion, sirve solamente para propositos de debugging
    4096,          // Tamaño del stack la tarea
    NULL,          // Parametro que recibe la funcion que le vamos a pasar
    1,             // Prioridad de la tarea
    NULL,          // no es importante
    1              // El core donde queremos que corra la task (0/1)
  );

  xTaskCreatePinnedToCore(
    semaforo2,     // Referencia a la funcion que vamos a ejecutar
    "Task_Core2",  // Nombre para la funcion, sirve solamente para propositos de debugging
    4096,          // Tamaño del stack la tarea
    NULL,          // Parametro que recibe la funcion que le vamos a pasar
    1,             // Prioridad de la tarea
    NULL,          // no es importante
    0              // El core donde queremos que corra la task (0/1)
  );
 // En este caso queremos que sea un mutex.
}

void semaforo1(void *parameter) {//Llamamos la funcion semaforo.
  for (;;) {/*Creamos un for infinito para indicar la tarea del semaforo que consta de usar una bandera donde esta se sincroniza
    con el patron de forma inversa al primer semaforo*/
    if (xSemaphoreTake(mySemaphore, portMAX_DELAY) == pdTRUE) {


      //rojo
      digitalWrite(rojo, HIGH);
      digitalWrite(amarillo, LOW);
      digitalWrite(verde, LOW);
      delay(4000);

      //verde
      digitalWrite(rojo, LOW);
      digitalWrite(amarillo, LOW);
      digitalWrite(verde, HIGH);
      delay(3000);

      //amarillo
      digitalWrite(rojo, LOW);
      digitalWrite(amarillo, HIGH);
      digitalWrite(verde, LOW);
      delay(1000);
    }
    xSemaphoreGive(mySemaphore);//Liberamos semaforos
  }
}

void semaforo2(void *parameter) {//Lo mismo pero inverso
  for (;;) {
    if (xSemaphoreTake(mySemaphore, portMAX_DELAY) == pdTRUE) {

      //Verde
      digitalWrite(rojo2, LOW);
      digitalWrite(amarillo2, LOW);
      digitalWrite(verde2, HIGH);
      delay(3000);

      //amarillo
      digitalWrite(rojo2, LOW);
      digitalWrite(amarillo2, HIGH);
      digitalWrite(verde2, LOW);
      delay(1000);

      //rojo
      digitalWrite(rojo2, HIGH);
      digitalWrite(amarillo2, LOW);
      digitalWrite(verde2, LOW);
      delay(4000);
    }
    xSemaphoreGive(mySemaphore);//Libera el semaforo
  }
}


void loop() {
}