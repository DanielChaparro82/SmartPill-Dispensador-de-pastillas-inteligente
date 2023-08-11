# Introducción
Un sistema dispensador de pastillas es una herramienta útil para aquellas personas que necesitan tomar medicamentos en horarios específicos. Este sistema en particular utiliza 3 servomotores conectados a un Arduino Uno para dispensar las pastillas. Además, cuenta con una pantalla LCD donde se pueden acceder a diferentes menús con push buttons para establecer los horarios en los que se activarán los servomotores y soltarán una pastilla. Estos horarios se guardan en un RTC para mayor precisión. Cuando llega la hora de consumir el medicamento, el sistema emite un sonido a través de un buzzer para recordar al usuario que debe tomar su medicamento. Este sistema es fácil de usar y puede ser de gran ayuda para aquellas personas que necesitan recordatorios para tomar sus medicamentos.

# Objetivo
Asegurar que las personas tomen sus medicamentos en el horario adecuado por medio de un sistema inteligente que proporcione las pastillas y alerte al paciente en el tiempo requerido.

# Materiales
## Hardware
- Arduino UNO
- LCD 16×2
- Protoboard
- Modulo I2C
- RTC DS1302
- Cable USB a Mini USB
- Servomotores 9g
- Cable USB A/B
- Push buttons
- Baterías 9V
- Jumpers
- Buzzer
  
## Software
- IDE Arduino

# Requisitos previos
## IDE Arduino
Para poder subir el codigo a nuestro Arduino Uno requerimos tener previamente instalado el software IDE Arduino.
[Arduino Software](https://www.arduino.cc/en/software)

## Agregar librerias
Las librerías utilizadas en este proyecto son "LiquidCrystal_I2C", "virtuabotixRTC" y "RTClib" se pueden instalar desde el gestor de librería del IDE Arduino. También se pueden descargar directamente e instalarlas desde  Sketch -> Include Library -> Add .ZIP Library

Incorporación por Gestor de librerias

![Gestor de librerias](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/b9cf3ac4-be7d-47d7-baea-e3392f4bdba0)

Incorporación como libreria .ZIP

![Libreria ZIP](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/77bd9b17-445a-4f13-95e4-dc4bad0496f7)

## Referencias externas
