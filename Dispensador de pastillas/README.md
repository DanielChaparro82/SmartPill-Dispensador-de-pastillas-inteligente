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

# Instrucciones

Propuesta de circuito para dispensador de pastillas

![ARDUINO](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/ab8f0ff6-2e38-4305-bc92-a9bcc7f980c3)

Nota:
- Push button Amarillo: Desplazamiento entre menús
- Push button Verde: Cambiar de opción
- Push button Azul: Cambiar valor de variables

Una vez descargado y abierto el código en el IDE Arduino se debera seleccionar la pestaña Tools y seleccionar las siguientes configuración:
- Board: "Arduino UNO"

![Arduino UNO](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/cd3221a1-d55c-4910-800d-09dd78e39e12)

A continuación se debera subir el código al ArDuino UNO

![Upload Arduino](https://github.com/DanielChaparro82/SmartPill-Dispensador-de-pastillas-inteligente/assets/135756954/4045d7a4-2ac0-40c4-bd68-f2c3a43533c0)

# Referencias externas
- [Simple & Easy Arduino Clock with DS1302](https://www.youtube.com/watch?v=s4ymtoTa_eo)
