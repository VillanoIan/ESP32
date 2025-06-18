#include <WiFi.h>
#include <PubSubClient.h>
#include<string>
String SSID, contra;
WiFiClient espClient;
  // Creamos un cliente de MQTT con la conexión a internet via wifi
PubSubClient client(espClient);

void setup() {
  Serial.begin(115200);
  // Conectarse a una red por nombre + contraseña
  
  WiFi.begin("<Nombre del a red>","<Contraseña del a red>");
  while (WiFi.status() != WL_CONNECTED){
    Serial.println("No logro conectarse");
    Serial.println("Reintentando...");
    delay(3000);
  }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("Se logro conectarse al Wi-Fi");

  }

  // Realizamos la conexión con el servidor
  
  client.setServer("broker.hivemq.com",1883);
  client.connect("Ianchu2123"); // devuelve un booleano indicando si se conecto correctamente
  client.connected(); // devuelve un booleano que nos permite chequear si la conexión fue exitosa
  while(!client.connected()){
    Serial.println("Fallo al conectarse al broker");
    delay(1000);
  }
  if(client.connected()){
    Serial.println("Se ha conectado exitosamente al broker");
  }
  client.subscribe("huergo/sistemas-embebidos/Villano"); // seguir patron del topico a escuchar
  client.setCallback(callback);// Configuramos el cliente con el callback correcto
  
}

void loop() {
  if (Serial.available()) {
    String msg;
    msg = Serial.readStringUntil('\n');
    msg_final= "Villano: "+ msg;
    client.publish("huergo/sistemas-embebidos/Villano", msg.c_str()); // convertir el mensaje mediante .c_str()
    client.loop();
  }
}

// Callback (una función con una firma particular) que respondera ante un nuevo mensaje recibido
void callback(char* topic, byte* payload, unsigned int length) {
  // Iteramos el payload
    char letra;
    for (int i = 0; i < length; i++) {
    letra=(char)payload[i];
    Serial.print(letra);
  }
  Serial.println();
}

