# Introducción

Este proyecto utiliza un lector RFID (Identificador por radiofrecuencia) el cual permite la transmisión de datos a través de ondas de radio. Toda la información recolectada sera enviada desde un identificador RFID donde se indicara la hora, fecha y nombre del medicamento que seran registrados en una base de datos compartida tras el escaneo de las tarjetas RFID.

# Objetivo
Utilizar identificadores para transmitir información desde un lector hasta una base de datos donde se incluyan datos como la hora, fecha e información establecida para cada identificador.

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
- Google drive

# Requisitos previos
## IDE Arduino
Para poder subir el codigo a nuestro Arduino Uno requerimos tener previamente instalado el software IDE Arduino.
[Arduino Software](https://www.arduino.cc/en/software)

## Google drive
Generar un archivo con el formato de hoja de cálculo en Google Drive. https://drive.google.com

## Agregar tarjetas ESP8266
Para agregar la url de la tarjeta del URLs debemos ir al Arduino IDE y seleccionar Archivo -> Preferencias

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

![5](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/bf678953-5242-4353-a106-7e8798616794)

Hacer un archivo de excel de drive. Una vez teneindo eso seleccionamos --> extensiones --> Apps Script --> copiamos el codigo del archivo llamado "codigo Apps Script"

![1](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/02b14edf-b58a-46ee-b4f1-5a40b5447324)

![2](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/6f14c615-1d17-4ae6-b95e-5ca2740a95dd)

# Instrucciones
## Circuito
A continuación se muestra una propuesta de circuito para el RFID
![ESP8266 - RFID](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/f86b3543-46f3-4e9d-b604-f9ca85660dd9)

## Configuracion de tarjetas 
1. En la linea 14 del codigo se configura al nombre con la que se quiere registar la tarjeta NOTA: no debe de contener espacios

2. Por último se carga el codigo al esp8266 y pasamos la tarjeta en el sensor para que configure el nombre de la tarjeta 

## Configuracion para el envio de datos con el sensor RFID
1. En una linea nos pedira la Huella digital para URL la cual podemos obtener de la sigiente manera --> nos vamos al archivo xcel de drive --> en la pate superior 
de la pagina se encuentra un candado le damos click

![3](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/4d4ba419-fd1c-4afc-95ba-17a6f12810cb)

La seleccion es segura --> El certificado es valido --> y solo copiamos los numeros que aparecen en la partede Huella digital SHA-1 y los colocamos en en el codigo de IDE Arduino como se muestra en el ejemplo del archivo .ino

![4](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/46f3f890-b086-4fff-a28c-df67202a6b58)

3. En la linea 33 nos pide el link del archvio excel ya mencionado anteriormente lo pegamos y agregamos al final ?name=

4. Linea 55 nos indica que coloquemos el nombre de la red WIFI y contraseña cargamos código y verificamos que realemente mande los datos deseados

# Referencias externas
- http://arduino.esp8266.com/stable/package_esp8266com_index.json
- https://www.youtube.com/watch?v=97samwAA-TA&t=780s



