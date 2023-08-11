#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
#include <RTClib.h>
virtuabotixRTC myRTC(6, 7, 8);

LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <EEPROM.h>
#include <Servo.h>
Servo servo1; 
Servo servo2;  // Servomotores
Servo servo3;

const int btnChange = 2;
const int btnOK = 3;
const int btnMode = 4;
const int buzzer = 5;

int alarmHour = 12;
int alarmMinutes = 0;
boolean hourMode = 0;
boolean alarmOn = 1;
int M = 12;     // Mes
int D = 31;     // Día
int Y = 2020;   // Año
int day = 7;    // Días de la semana
int h = 23;     // Horas del día
int m = 59;     // Minutos

int addrH[] = {0, 1, 2, 3, 4};
int addrM[] = {5, 6, 7, 8, 9};
int addrActive[] = {10, 11, 12, 13, 14};

int mode = 1;
int submode = 1;
int slot = 0;

byte clockChar[] = {B00000, B01110, B10101, B10101, B10111, B10001, B01110, B00000};
byte alarmChar[] = {B00100, B01110, B01110, B01110, B11111, B00000, B00100, B00000};
byte dateChar[] = {B11111, B00000, B01100, B01010, B01010, B01100, B00000, B11111};

void setup()  {
  servo1.attach(9);
  servo2.attach(10);
  servo3.attach(11);
  pinMode(btnChange, INPUT_PULLUP);
  pinMode(btnOK, INPUT_PULLUP);
  pinMode(btnMode, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);


  lcd.init();         // Inicializar LCD
  lcd.backlight();    // Enciende el contraste en LCD
  lcd.createChar(0, clockChar);
  lcd.createChar(1, alarmChar);
  lcd.createChar(2, dateChar);

  Serial.begin(9600);

}

///////////////////////////////////////////////////////////////////   void LOOP  ///////////////////////////////////////////

void loop()  {
  
  if (digitalRead(btnMode) == LOW) {
    mode++;

    Serial.println("btnMode press");
    if (mode == 4) {
      mode = 1;
    }
    submode = 0;
    lcd.clear();
    delay(200);
  }

  if (mode == 1) {
    clockDisplay();
    Serial.println(mode);
    //    delay(200);
  }

  if (mode == 2) {
    alarmMode();
    Serial.println(mode);
    //    delay(200);
  }

  if (mode == 3) {
    updateRTC();
    Serial.println(mode);
    //    delay(200);
  }
  if (mode == 0) {
    alarm();
    Serial.println(mode);
    EEPROM.write(addrActive, 0);
    //    delay(200);
  }

// Si se encuentran coincidencias con la memoria PROM el servomotor se encendera
 for (int x = 0; x < 3; x++) {
    if (EEPROM.read(addrActive[x]) == 1) {
      Serial.print("Alarma Activada:");
      Serial.println(x);
      if ( myRTC.hours == EEPROM.read(addrH[x]) && myRTC.minutes == EEPROM.read(addrM[x])) {
        EEPROM.write(addrActive[x], 0);
        mode = 0;
        if (x == 0) { // Movimiento Servomotor #1
           servo1.write(0);
           delay(1000);
           servo1.write(180);
           delay(2000);
           servo1.write(0);
           delay(1000);
        } else 
        if (x == 1) { // Movimiento Servomotor #2
           servo2.write(0); 
           delay(1000); 
           servo2.write(180); 
           delay(2000); 
           servo2.write(0); 
           delay(1000);
        } else 
        if (x == 2) { // Movimiento Servomotor #3
           servo3.write(0); 
           delay(1000); 
           servo3.write(180); 
           delay(2000); 
           servo3.write(0); 
           delay(1000);
        }
      }
    }
  }
}

// Se enciende el buzzer
void alarm() {
  clockDisplay();
  lcd.noBacklight();
  digitalWrite(buzzer, HIGH);
  delay(300);
  lcd.backlight();
  digitalWrite(buzzer, LOW);
  delay(200);
}


///////////////////////////////////////////////////////////////////   Imprimir variables en display  ///////////////////////////////////////////

void clockDisplay() {
  myRTC.updateTime();
  //  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(0);

  lcd.setCursor(0, 1);
  switch (myRTC.month) {
    // Meses
    case 1: lcd.print("ENE "); break;
    case 2: lcd.print("FEB "); break;
    case 3: lcd.print("MAR "); break;
    case 4: lcd.print("ABR "); break;
    case 5: lcd.print("MAY "); break;
    case 6: lcd.print("JUN "); break;
    case 7: lcd.print("JUL "); break;
    case 8: lcd.print("AGO "); break;
    case 9: lcd.print("SEP "); break;
    case 10: lcd.print("OCT "); break;
    case 11: lcd.print("NOV "); break;
    case 12: lcd.print("DIC "); break;
  }

  if (myRTC.dayofmonth < 10) {
    lcd.print(" ");
    lcd.print(myRTC.dayofmonth);
  }
  else{
    lcd.print(myRTC.dayofmonth);
  }
  lcd.print(",");
  lcd.print(myRTC.year);

  lcd.setCursor(13, 1);
  switch (myRTC.dayofweek) {
    // Días de la semana
    case 1: lcd.print("DOM"); break;
    case 2: lcd.print("LUN"); break;
    case 3: lcd.print("MAR"); break;
    case 4: lcd.print("MIE"); break;
    case 5: lcd.print("JUE"); break;
    case 6: lcd.print("VIE"); break;
    case 7: lcd.print("SAB"); break;
  }
  lcd.setCursor(3, 0);
  if ((myRTC.hours > 12 && myRTC.hours < 22) || (myRTC.hours > 0 && myRTC.hours < 10)) {
    lcd.print("0");
  }
  if (myRTC.hours == 0) {
    lcd.print("12");
  }
  else if (myRTC.hours <= 12) {
    lcd.print(myRTC.hours);
  }
  else {
    lcd.print(myRTC.hours - 12);
  }
  lcd.print(":");
  if (myRTC.minutes < 10) {
    lcd.print("0");
  }
  lcd.print(myRTC.minutes);
  lcd.print(":");
  if (myRTC.seconds < 10) {
    lcd.print("0");
  }
  lcd.print(myRTC.seconds);
  lcd.print("   ");
  if (myRTC.hours < 12) {
    lcd.print("AM");
  }
  else {
    lcd.print("PM");
  }
}

///////////////////////////////////////////////////////////////////   Alarma  ///////////////////////////////////////////
void alarmMode() {
  if (submode == 0) {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.setCursor(2, 0);
    lcd.print("Selec:");

    if (digitalRead(btnChange) == LOW) {
      slot++;
      if (slot > 4 ) {
        slot = 0;
      }
      delay(200);
    }
    lcd.setCursor(10, 0);
    lcd.print("Alar#");
    lcd.print(slot + 1);
    lcd.setCursor(0, 1);

    if (EEPROM.read(addrH[slot]) > 23) {
      EEPROM.write(addrH[slot], 0);
    }
    if (EEPROM.read(addrM[slot]) > 59) {
      EEPROM.write(addrM[slot], 0);
    }
    if (EEPROM.read(addrActive[slot]) > 1) {
      EEPROM.write(addrActive[slot], 0);
    }
    if ((EEPROM.read(addrH[slot]) > 12 && EEPROM.read(addrH[slot]) < 22) || (EEPROM.read(addrH[slot]) > 0 && EEPROM.read(addrH[slot]) < 10)) {
      lcd.print("0");
    }
    if (EEPROM.read(addrH[slot]) == 0) {
      lcd.print("12");
      alarmHour = 12;
    }
    else if (EEPROM.read(addrH[slot]) <= 12) {
      lcd.print(EEPROM.read(addrH[slot]));
      alarmHour = EEPROM.read(addrH[slot]);
    }
    else {
      lcd.print(EEPROM.read(addrH[slot]) - 12);
      alarmHour = EEPROM.read(addrH[slot]) - 12;
    }
    lcd.print(":");
    if (EEPROM.read(addrM[slot]) < 10) {
      lcd.print("0");
    }
    lcd.print(EEPROM.read(addrM[slot]));
    alarmMinutes = EEPROM.read(addrM[slot]);
    lcd.print(" ");
    if (EEPROM.read(addrH[slot]) < 12) {
      lcd.print("AM");
      hourMode = 0;
    }
    else {
      lcd.print("PM");
      hourMode = 1;
    }
    lcd.print("   ");
    if (EEPROM.read(addrActive[slot]) == 1) {
      lcd.print("ON ");
    }
    else {
      lcd.print("OFF");
    }
  }
  else {
    lcd.setCursor(0, 0);
    lcd.write(1);
    lcd.setCursor(2, 0);
    lcd.print("Sel ||");
    lcd.setCursor(0, 1);
    lcd.print("Alarm ||");
    lcd.setCursor(9, 1);
    if (alarmHour < 10) {
      lcd.print("0");
      lcd.setCursor(10, 1);
    }
    lcd.print(alarmHour);
    lcd.setCursor(11, 1);
    lcd.print(":");
    lcd.setCursor(12, 1);
    if (alarmMinutes < 10) {
      lcd.print("0");
      lcd.setCursor(13, 1);
    }
    lcd.print(alarmMinutes);
    if (hourMode == 0) {
      lcd.print("AM");
    }
    else {
      lcd.print("PM");
    }
  }
  //  lcd.print(alarmMinutes);
  if (digitalRead(btnOK) == LOW) {
    submode++;
    if (submode > 4) {
      submode = 0;
    }
    delay(200);
    lcd.clear();
  }
  if (submode == 1) {
    lcd.setCursor(9, 0);
    lcd.write(1);
    lcd.write(1);
    if (digitalRead(btnChange) == LOW) {
      alarmHour++;
      if (alarmHour > 12) {
        alarmHour = 1;
      }
      delay(500);
    }
  }
  if (submode == 2) {
    lcd.setCursor(12, 0);
    lcd.write(1);
    lcd.write(1);
    if (digitalRead(btnChange) == LOW) {
      alarmMinutes++;
      if (alarmMinutes >= 60) {
        alarmMinutes = 0;
      }
      delay(500);
    }
  }
  if (submode == 3) {
    lcd.setCursor(14, 0);
    lcd.write(1);
    lcd.write(1);
    if (digitalRead(btnChange) == LOW) {
      hourMode = !hourMode;
      delay(500);
    }
  }
  while (submode == 4) {
    lcd.setCursor(0, 0);
    lcd.print("ACTIVAR ALARMA?");
    lcd.setCursor(0, 1);
    lcd.print("Alarma #");
    lcd.print(slot + 1);
    lcd.print("   ");
    if(alarmOn==1){
      lcd.print("ON ");
    }
    else{
      lcd.print("OFF");
    }
    if (digitalRead(btnChange) == LOW) {
      alarmOn = !alarmOn;
      delay(200);
    }

    if (digitalRead(btnOK) == LOW && alarmOn == 1) {
      lcd.clear();
      lcd.setCursor(0, 1);
      lcd.print("Guardado..");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      delay(200);
      lcd.print(".");
      if (hourMode == 1 && alarmHour != 12) {
        EEPROM.write(addrH[slot], alarmHour + 12);
      }
      else if (hourMode == 0 && alarmHour == 12) {
        EEPROM.write(addrH[slot], 0);
      }
      else {
        EEPROM.write(addrH[slot], alarmHour);
      }

      EEPROM.write(addrM[slot], alarmMinutes);
      EEPROM.write(addrActive[slot], 1);
      submode = 0;
      mode = 1;
      lcd.clear();
    }
    if (digitalRead(btnOK) == LOW && alarmOn == 0)  {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Alarma #");
      lcd.print(slot + 1);
      lcd.setCursor(0, 1);
      lcd.print(" OFF      ");
      
      EEPROM.write(addrActive[slot], 0);
      submode = 0;
      mode = 1;
      
      delay(2000);
      lcd.clear();
    }
  }
}

///////////////////////////////////////////////////////////////////   Establecer horarios y fecha fija  ///////////////////////////////////////////

void updateRTC() {
  lcd.setCursor(0, 0);
  lcd.write(2);
  if (digitalRead(btnOK) == LOW) {
    submode++;
    if (submode > 7) {
      submode = 0;
    }
    delay(200);
    lcd.clear();
  }

// Cambio de menú para seleccionar día y hora
  if (submode == 0) {
    lcd.setCursor(2, 0);
    lcd.print("Selec Dia/Hora?");
    lcd.setCursor(0, 1);
    lcd.print("Confirmar |Ok|");
  }
  if (submode == 1) {
    lcd.setCursor(2, 0);
    lcd.print("Selec Mes");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      M++;
      if (M == 13) {
        M = 1;
      }
      delay(200);
    }
    switch (M) {
      // Cambiar Mes
      case 1: lcd.print("ENERO     ");
        break;
      case 2: lcd.print("FEBRERO    ");
        break;
      case 3: lcd.print("MARZO       ");
        break;
      case 4: lcd.print("ABRIL       ");
        break;
      case 5: lcd.print("MAYO         ");
        break;
      case 6: lcd.print("JUNIO        ");
        break;
      case 7: lcd.print("JULIO        ");
        break;
      case 8: lcd.print("AGOSTO      ");
        break;
      case 9: lcd.print("SEPTIEMBRE   ");
        break;
      case 10: lcd.print("OCTUBRE     ");
        break;
      case 11: lcd.print("NOVIEMBRE    ");
        break;
      case 12: lcd.print("DICIEMBRE    ");
        break;
    }
  }
  // Cambiar día
  if (submode == 2) {
    lcd.setCursor(2, 0);
    lcd.print("Selec Dia");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      D++;
      if (D == 32) {
        D = 1;
      }
      delay(200);
    }
    lcd.print(D);
    lcd.print(" ");
  }

  if (submode == 3) {
    // Cambiar año
    lcd.setCursor(2, 0);
    lcd.print("Selec periodo");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      Y++;
      if (Y == 2099) {
        Y = 2000;
      }
      delay(200);
    }
    lcd.print(Y);
  }
  // Cambiar de día
  if (submode == 4) {
    lcd.setCursor(2, 0);
    lcd.print("Selec dia");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      day++;
      if (day == 8) {
        day = 1;
      }
      delay(200);
    }
    switch (day) {
      // Cambiar día de la semana
      case 1: lcd.print("DOMINGO      ");
        break;
      case 2: lcd.print("LUNES      ");
        break;
      case 3: lcd.print("MARTES     ");
        break;
      case 4: lcd.print("MIERCOLES   ");
        break;
      case 5: lcd.print("JUEVES    ");
        break;
      case 6: lcd.print("VIERNES      ");
        break;
      case 7: lcd.print("SABADO    ");
        break;
    }
  }
  // Cambiar de hora
  if (submode == 5) {
    lcd.setCursor(2, 0);
    lcd.print("Selec Hora");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      h++;
      if (h == 24) {
        h = 0;
      }
      delay(200);
    }
    if (h > 12) {
      lcd.print(h - 12);
      lcd.print(" ");
    }
    else if (h == 0) {
      lcd.print("12");
      lcd.print(" ");
    }
    else {
      lcd.print(h);
      lcd.print(" ");

    }
    // Cambiar entre horaio matutino y vespertino
    if (h >= 12) {
      lcd.setCursor(9, 1);
      lcd.print("PM");
    }
    else {
      lcd.setCursor(9, 1);
      lcd.print("AM");
    }

  }
  // Cambiar minutos
  if (submode == 6) {
    lcd.setCursor(2, 0);
    lcd.print("Selec Minutos");
    lcd.setCursor(0, 1);
    lcd.print("--> ");
    if (digitalRead(btnChange) == LOW) {
      m++;
      if (m == 60) {
        m = 0;
      }
      delay(200);
    }
    lcd.print(m);
    lcd.print(" ");
  }
  // Guardar el horario en la memoria RTC
  if (submode == 7) {
    lcd.setCursor(2, 0);
    lcd.print("Dia y Hora");
    lcd.setCursor(0, 1);
    lcd.print("Actualizado..");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    delay(200);
    lcd.print(".");
    myRTC.setDS1302Time(00, m, h, day, D, M, Y);
    delay(200);
    lcd.clear();
    mode = 1;
  }
}
