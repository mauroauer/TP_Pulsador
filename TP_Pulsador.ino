long tiempoActual;
long tiempoBoton;
int estadoSistema;
boolean estadoPulsador;
boolean estadoLuz;

void setup() {
  pinMode(8, INPUT);
//  pinMode(11, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  tiempoActual = millis();
  tiempoBoton = tiempoActual;
  estadoSistema = 0;
  estadoPulsador = digitalRead(8);
  estadoLuz = LOW;

}

void loop() {
  tiempoActual = millis();
  estadoPulsador = digitalRead(8);

  if (estadoSistema == 0) {
    // Acciones

    // Transiciones
    // si se oprime el botón se cambia de estado
    if (estadoPulsador == true && tiempoActual > tiempoBoton + 1000) {
      estadoSistema = 1;
      tiempoBoton = tiempoActual;
      estadoLuz = HIGH;

    }
  }
  if (estadoSistema == 1) {
    // Acciones

    // Transiciones
    // si se oprime el botón se genera el cambio de estado bucle para resetear el temporizador
    if (estadoPulsador == true && tiempoActual > tiempoBoton + 1000) {
      tiempoBoton = tiempoActual;
      estadoSistema = 0;
      estadoLuz = LOW;
    }
  }
//  digitalWrite(11, estadoLuz);
  digitalWrite(LED_BUILTIN, estadoLuz);
}
