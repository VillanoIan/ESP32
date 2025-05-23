SemaphoreHandle_t Pista1, Pista2, Pista3;//Declaramos las pistas 
QueueHandle_t colaSolicitudes, colaAutorizaciones;//Declaramos la cola solicutod y autorizaciones


void setup() {
  Serial.begin(115200);//Mostrar en la terminal
  delay(1000);
  //Declaramos la variables como mutex.
  Pista1 = xSemaphoreCreateMutex();
  Pista2 = xSemaphoreCreateMutex();
  Pista3 = xSemaphoreCreateMutex();
  //Creamos las colas
  colaSolicitudes = xQueueCreate(10, sizeof(int));       
  colaAutorizaciones = xQueueCreate(10, sizeof(int));  
  
  //Creamos una tarea para el nucleo 0
  for (int i = 1; i <= 5; i++) {
    int* avionID = (int*)malloc(sizeof(int));// Reservamos memoria dinámica para guardar el ID del avión de forma única
    *avionID = i;
    xTaskCreatePinnedToCore(
    Tarea_de_aviones, // Referencia a la funcion que vamos a ejecutar
    "Task_Core0",     // Nombre para la funcion, sirve solamente para propositos de debugging
    4096,             // Tamaño del stack la tarea
    avionID,          // Parametro que recibe la funcion que le vamos a pasar
    1,                // Prioridad de la tarea
    NULL,             // no es importante
    0                 // El core donde queremos que corra la task (0/1)
  );
    }
  
  //Creamos una tarea para el nucleo 1
  xTaskCreatePinnedToCore(
    Torre_de_Control, // Referencia a la funcion que vamos a ejecutar
    "Task_Core1",     // Nombre para la funcion, sirve solamente para propositos de debugging
    4096,             // Tamaño del stack la tarea
    NULL,             // Parametro que recibe la funcion que le vamos a pasar
    1,                // Prioridad de la tarea
    NULL,             // no es importante
    1                  // El core donde queremos que corra la task (0/1)
  );

}

void Tarea_de_aviones(void *parameter) {//Su funcion es enviar a la torre las solicitudes y revisar el estado de las pistas
  int miID = *((int *)parameter);// Seleccion del avíon

  for (;;) {
    // tiempo random de aproximación
    int espera = random(1000, 3000);
    vTaskDelay(espera / portTICK_PERIOD_MS);

    //Envia la solicitud
    Serial.printf("Avión %d solicita aterrizaje\n", miID);
    delay(500);
    xQueueSend(colaSolicitudes, &miID, portMAX_DELAY);

    //Recibe la autorizacion 
    int autorizado;
    xQueueReceive(colaAutorizaciones, &autorizado, portMAX_DELAY);

    //Compara la autorizacion con la ID del avion
    if (autorizado == miID) {
      Serial.printf("Avión %d autorizado por torre\n", miID);

      //Busca si hay pista disponible
      if (xSemaphoreTake(Pista1, 0) == pdTRUE) {
        Serial.printf("Avión %d aterrizando en Pista 1\n", miID);
        delay(500);
        vTaskDelay(random(2000, 4000) / portTICK_PERIOD_MS);
        xSemaphoreGive(Pista1);
        Serial.printf("Avión %d liberó Pista 1\n", miID);
        delay(500);
      } else if (xSemaphoreTake(Pista2, 0) == pdTRUE) {
        Serial.printf("Avión %d aterrizando en Pista 2\n", miID);
        delay(500);
        vTaskDelay(random(2000, 4000) / portTICK_PERIOD_MS);
        xSemaphoreGive(Pista2);
        Serial.printf("Avión %d liberó Pista 2\n", miID);
        delay(500);

      } else if (xSemaphoreTake(Pista3, 0) == pdTRUE) {
        Serial.printf("Avión %d aterrizando en Pista 3\n", miID);
        delay(500);
        vTaskDelay(random(2000, 4000) / portTICK_PERIOD_MS);
        xSemaphoreGive(Pista3);
        Serial.printf("Avión %d liberó Pista 3\n", miID);
        delay(500);

      } else {
        // Si no encuentra pista
        Serial.printf("Avión %d autorizado pero no encontró pista libre\n", miID);
        
      }
    }
  }
}

void Torre_de_Control(void *parameter) {//Funcion donde la funcion anterior "Tarea de aviones", se hace print para la aprobacion por la torre de control
  for (;;) {
    int idAvion;
    if (xQueueReceive(colaSolicitudes, &idAvion, portMAX_DELAY) == pdTRUE) {
      Serial.printf("Torre recibió solicitud del avión %d\n", idAvion);
      delay(500);
      vTaskDelay(500 / portTICK_PERIOD_MS);//delay de simulando un procesamiento
      xQueueSend(colaAutorizaciones, &idAvion, portMAX_DELAY);
      Serial.printf("Torre autorizó al avión %d\n", idAvion);
      delay(500);
    }
  }
}




//No se usa porque utiliza el sistema operativo FreeRTOS
void loop() {
}