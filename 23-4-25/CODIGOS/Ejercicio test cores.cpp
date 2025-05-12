void setup() {// Comienzo del programa creando las variables cores con sus respectivos nombres y nucleos.
  Serial.begin(9600);//Para ver en la terminal si funciona los cores
  xTaskCreatePinnedToCore(
  Tarea1, // Referencia a la funcion que vamos a ejecutar
  "TareaCore", // Nombre para la funcion, sirve solamente para propositos de debugging
  4096, // Tamaño del stack la tarea
  NULL, // Parametro que recibe la funcion que le vamos a pasar
  1, // Prioridad de la tarea
  NULL, // no es importante
  1 // El core donde queremos que corra la task (0/1)
  );
  xTaskCreatePinnedToCore(
  Tarea1, // Referencia a la funcion que vamos a ejecutar
  "TareaCore2", // Nombre para la funcion, sirve solamente para propositos de debugging
  4096, // Tamaño del stack la tarea
  NULL, // Parametro que recibe la funcion que le vamos a pasar
  0, // Prioridad de la tarea
  NULL, // no es importante
  0 // El core donde queremos que corra la task (0/1)
  );
}
void Tarea1(void *parameter)//Llamar ambos cores en una funcion especifica
{
  for(; ;)// Crear un for infinito para que repita la tarea. Su funcion es mostrar en la terminal si esta funcionando ambos cores.
  {
    int Core=xPortGetCoreID();
    Serial.println(Core);
    vTaskDelay(pdMS_TO_TICKS(1000));
    
     


  }
}





void loop() {


}