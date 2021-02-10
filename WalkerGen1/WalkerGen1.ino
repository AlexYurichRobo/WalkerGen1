#include <Servo.h>

//переменные для чтения информации из монитора порта
String strData = "";
boolean recievedFlag;
int intVar;

//параметры сервопривода
const int servos = 4;// количество сервоприводов в механизме

//переменные для углов горизонтальных осей сервоприводов
int angleHor = 90;
int devAngHor = 25;
int angMinHor = angleHor - devAngHor;
int angMaxHor = angleHor + devAngHor;

//параметры сервоприводов
const int servoCenterConst[servos] = {87, 83, 86, 82};
int servoAngle[servos];
Servo servoLegs[servos];
int rate = 20;                  //скорость движения сервоприводов
                                //чем меньше тем быстрее


void setup() {
  Serial.begin(9600); // включаем монитор порта
  int iter = 0; //счетчик сервоприводов (начинается с нуля)

  //инициализируем сервоприводы
  for (int i = 0; i < servos; ++i) {
    servoAngle[i] = servoCenterConst[i];    //заполняем новый, изменяемый массив для хранения текущего положения сервоприводов
    servoLegs[i].attach(i + 7);             //инициализируем порты с сервоприводами
    servoLegs[i].write(servoCenterConst[i]);      //выставляем начальное положение сервопривода
    delay(1000);
  }
}

/*
   Цель: Заставить робота качаться с ноги на ногу,
   с полным отрывом ступни от земли
*/
void loop() {
  //Задача 1. Выполнить отклонение от начального положения в одну сторону
  for (angleHor; angleHor < angMaxHor; ++angleHor) {
    for (int j = 0; j < servos; j += 2) {
      ++servoAngle[j];
      servoLegs[j].write(servoAngle[j]);
      delay(rate);
    }
  }
  //Задача 2. Вернуть робота в положение равновесия
  //Задача 3. Отклонить робота в другую сторону
  for (angleHor; angleHor > angMinHor; --angleHor) {
    for (int j = 0; j < servos; j += 2) {
      --servoAngle[j];
      servoLegs[j].write(servoAngle[j]);
      delay(rate);
    }
  }
}
