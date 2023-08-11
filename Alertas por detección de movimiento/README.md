# Introducción

Este proyecto utiliza un sensor PIR (Passive Infrared Sensor) para detectar movimiento en un área determinada. Cuando se detecta movimiento, el sistema envía una alerta a través de un bot de Telegram y toma una foto utilizando una cámara conectada a un módulo ESP32. La foto se envía junto con la alerta para que el usuario pueda ver lo que está sucediendo en tiempo real.

# Objetivo

Combinar tecnologías de detección de movimiento, comunicación inalámbrica y mensajería instantánea para proporcionar una solución de monitoreo en tiempo real fácil de usar y accesible.

# Materiales
## Hardware
- Protoboard
- ESP32 CAM
- Sensor de movimiento PIR
- FTDI TTL USB Serial converter FT232RL 7
- Cable USB a Mini USB
- Batería 9v
- Jumpers
## Software
- IDE Arduino
- Telegram

# Requisitos previos
## IDE Arduino
Para poder subir el codigo a nuestro Arduino Uno requerimos tener previamente instalado el software IDE Arduino.
[Arduino Software](https://www.arduino.cc/en/software)

## Agregar tarjeta ESP32
Para agregar la url de la tarjeta del Esp32 debemos ir al Arduino IDE y seleccionar Archivo -> Preferencias

![Tarjeta ESP32 1](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/e3851425-a7ba-4aa9-b55b-cacc1578f94c)

Luego en "Gestor de URLs Adicionales de Tarjeta" agregamos: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

![Tarjeta ESP32 2](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/99d89824-82ed-44ba-a64b-89152395e312)

## Agregar librerias
Las librerías utilizadas en este proyecto son "ArduinoJson" y "UniversalTelegramBot", se pueden instalar desde el gestor de librería del IDE Arduino. También se pueden descargar directamente e instalarlas desde  Sketch -> Include Library -> Add .ZIP Library

![Libreria ZIP](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/77bd9b17-445a-4f13-95e4-dc4bad0496f7)

Universal Telegram Bot: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot

# Instrucciones

Circuito para hacer que la ESP32 CAM entre en modo de programación

![ESP32-CAM-CONFIG](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/bc896d9d-1b75-41c9-b80f-6fbf4978fccd)

Una vez descargado y abierto el codigo en el IDE Arduino se debera de seleccionar la pestaña Tools y seleccionar las siguientes configuraciones:
- Board: "AI Thinker ESP32-CAM"
- CPU Frequency: "240MHz (Wifi/BT)"
- Flash Frequency: "80MHz"
- Flash Mode: "QIO"
- Partition Scheme: "Huge APP (3MB No OTA/1MB SPIFFS)"

![Configuración](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/09e49816-d1b2-4327-8391-9ece7ae2a6ee)

A continuación se debera subir el código a la ESP32 en modo de programación

![Captura de pantalla 2023-08-11 003529](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/1cbc516c-8082-4f4d-b204-86c7a9e18513)

Posteriormente se debera realizar la siguiente conexión

![ESP32-CAM-PIR](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/19bf6c36-dc7b-425b-b967-b4804bd46486)

# Configuración del Bot de Telegram
El bot puede ser configurado de acuerdo a las necesidades del usuario, se puede tomar como referencia el siguiente enlace
https://blog.330ohms.com/2021/03/09/crea-tu-propio-bot-de-telegram-con-esp32/ 

# Referencias externas
- [Como configurar un bot de Telegram](https://blog.330ohms.com/2021/03/09/crea-tu-propio-bot-de-telegram-con-esp32/)
- [Alarma con Esp32 CAM y Telegram](https://github.com/electrodeuna/alarm-esp32cam/tree/main)
- [Configuración de IDE Arduino para ESP32 CAM](https://edu.codigoiot.com/mod/subcourse/view.php?id=3922)
- [Conectar el ESP32 CAM a Wi-fi](https://edu.codigoiot.com/mod/subcourse/view.php?id=3929)
