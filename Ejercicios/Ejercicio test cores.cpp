void setup() {
  Serial.begin(9600);
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
void Tarea1(void *parameter)
{
  for(; ;)
  {
    int Core=xPortGetCoreID();
    Serial.println(Core);
    delay(1000);
    
     


  }
}





void loop() {


}