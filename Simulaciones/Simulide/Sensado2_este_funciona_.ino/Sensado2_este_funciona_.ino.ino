//voltimetro versión 1

//prueba de solo sensado

//declaración de las variables a utilizar

float vout = 5; //valor de la tensión máxima que soporta el microcontrolador
float r1 = 1000000;  //valor de la resistencia r1=1M ohms
float r2 = 100000;  //valor de la resistencia r2=100k ohms
float vin;
float vreal;
//configuración de inicio
//se ejecuta solo una vez
void setup()
{
  Serial.begin(9600); //inicio de la comunicación serial
  delay(300);
  Serial.println("Voltimetro - Version 1");
  Serial.print("Rango: 0V - ");
  Serial.print((int)vout*(r1+r2)/r2);
  Serial.println("V");
  delay(300);
  Serial.println("...");
  delay(1000);
  
}

//rutina que enviará los datos al puerto serial
void loop()
{
  Serial.println("Testeando...");
  delay(1000);
  Serial.print("Bateria 1: ");
  Serial.print(v1());
  Serial.println("V");
  Serial.print("Bateria 2: ");
  Serial.print(v2());
  Serial.println("V");
  delay(1000);
  Serial.println("...");
  delay(1000);
}

float v1()
{
//lee el pin AN0 y convierte la señal a un valor digital
//vin en el voltaje de entrada en el pin AN0
  vin = (analogRead(0)*vout)/1024;
  divisor();
  float volt1 = divisor();
  return volt1;
}

float v2()
{
//lee el pin AN1 y convierte la señal a un valor digital
//vin en el voltaje de entrada en el pin AN0
  vin = (analogRead(1)*vout)/1024;
  divisor();
  float volt2 = divisor();
  return volt2;
}

//rutina de sensado de la tensión
float divisor()
{
//esta funcion convierte el valor leido a el valor real
//para ser enviado al puerto serial 
  vreal =  vin*(r2+r1)/r2;
  return vreal; //guarda el valor vrela en la funcion sensado()
}
