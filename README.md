# WalkerGen1

## Базовые функции для движения робота

Рассмотрим основные базовые движения робота.

Объявление переменных

```C++

#include <Servo.h>

//переменные для чтения информации из монитора порта
String strData = "";
boolean recievedFlag;
int intVar;

//параметры сервопривода
const int servos = 4;// количество сервоприводов в механизме

//переменные для углов горизонтальных осей робота
int angleHor = 90;
int devAngHor = 35;
int angMinHor = angleHor - devAngHor;
int angMaxHor = angleHor + devAngHor;

//переменные для вертикальных осей робота
int angleVer = 90;
int devAngVer = 20;
int angMinVer = angleVer - devAngVer;
int angMaxVer = angleVer + devAngVer;

//параметры сервоприводов
// сюда записываем полученные показатели среднего положения сервоприводов
const int servoCenterConst[servos] = {87, 89, 86, 82};
int servoAngle[servos];
Servo servoLegs[servos];
int rate = 5;
int delayTime = 100;
bool debug = true;
char directionFlag = 's';

```
