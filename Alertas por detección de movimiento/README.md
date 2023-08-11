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

# Requisitos previos
## IDE Arduino
Para poder subir el codigo a nuestro Arduino Uno requerimos tener previamente instalado el software IDE Arduino.
[Arduino Software](https://www.arduino.cc/en/software)

## Agregar tarjeta ESP32
Para agregar la url de la tarjeta del Esp32 debemos ir al Arduino IDE y seleccionar Archivo -> Preferencias

Luego en "Gestor de URLs Adicionales de Tarjeta" agregamos: https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json

## Agregar librerias
Las librerías utilizadas en este proyecto son "ArduinoJson" y "UniversalTelegramBot", se pueden instalar desde el gestor de librería del IDE Arduino. También se pueden descargar directamente e instalarlas desde  Sketch -> Include Library -> Add .ZIP Library

Universal Telegram Bot: https://github.com/witnessmenow/Universal-Arduino-Telegram-Bot

# Referencias externas
[Alarma con Esp32 CAM y Telegram](https://github.com/electrodeuna/alarm-esp32cam/tree/main)
