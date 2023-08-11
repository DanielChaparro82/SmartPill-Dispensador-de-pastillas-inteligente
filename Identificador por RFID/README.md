# Introducción

Este proyecto utiliza un lector RFID (Identificador por radiofrecuencia)

# Objetivo

# Materiales
## Hardware
- Sensor RFID-RC522
- Buzzer
- Jumpers
- ESP8266
- Protoboard
- Cable USB a Mini USB 
- Tarjetas RFID
  
## Software
- IDE Arduino
- 

# Requisitos previos
## IDE Arduino
Para poder subir el codigo a nuestro Arduino Uno requerimos tener previamente instalado el software IDE Arduino.
[Arduino Software](https://www.arduino.cc/en/software)

## Agregar tarjetas ESP8266
Para agregar la url de la tarjeta del Esp32 debemos ir al Arduino IDE y seleccionar Archivo -> Preferencias

![Tarjeta ESP32 1](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/e3851425-a7ba-4aa9-b55b-cacc1578f94c)

Luego en "Gestor de URLs Adicionales de Tarjeta" agregamos: http://arduino.esp8266.com/stable/package_esp8266com_index.json

![Tarjeta ESP32 2](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/99d89824-82ed-44ba-a64b-89152395e312)

## Agregar librerias
Las librerías utilizadas en este proyecto son "SPI.h", "MFRC522.h", "Arduino.h","ESP8266WiFi.h","ESP8266WiFiMulti.h","ESP8266HTTPClient.h","WiFiClient.h" y "WiFiClientSecureBearSSL.h",  se pueden instalar desde el gestor de librería del IDE Arduino. También se pueden descargar directamente e instalarlas desde  Sketch -> Include Library -> Add .ZIP Library

Incorporación por Gestor de librerias

![Gestor de librerias](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/b9cf3ac4-be7d-47d7-baea-e3392f4bdba0)

Incorporación como libreria .ZIP

![Libreria ZIP](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/77bd9b17-445a-4f13-95e4-dc4bad0496f7)

En la sección Board seleccionamos el NodeMCU 1.0 (ESP-12E MODULE)

Hacer un archivo de excel de drive. Una vez teneindo eso seleccionamos --> extensiones --> Apps Script --> copiamos el codigo del archivo llamado "codigo Apps Script"

# Instrucciones
# Configuracion de tarjetas 
1. En la linea 14 del codigo se configura al nombre con la que se quiere registar la tarjeta NOTA: no debe de contener espacios

2. Por último se carga el codigo al esp8266 y pasamos la tarjeta en el sensor para que configure el nombre de la tarjeta 

# Configuracion para el envio de datos con el sensor RFID
1. En una linea nos pedira la Huella digital para URL la cual podemos obtener de la sigiente manera --> nos vamos al archivo xcel de drive --> en la pate superior 
de la pagina se encuentra un candado le damos click --> La seleccion es segura --> El certificado es valido --> y solo copiamos los numeros que aparecen en la partede Huella digital SHA-1 y los colocamos en en el codigo de IDE Arduino como se muestra en el ejemplo del archivo .ino

2. En la linea 33 nos pide el link del archvio excel ya mencionado anteriormente lo pegamos y agregamos al final ?name=

3. Linea 55 nos indica que coloquemos el nombre de la red WIFI y contraseña
cargamos código y verificamos que realemente mande los datos deseados

# Referencias externas
- http://arduino.esp8266.com/stable/package_esp8266com_index.json
- https://www.youtube.com/watch?v=97samwAA-TA&t=780s



