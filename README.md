# WalkerGen1

## Базовые функции для движения робота

Рассмотрим основные базовые движения робота.

Объявление переменных иобъектов класса Servo. Сюдаже вносим полученные углы, полученные в процессе калибровки на предыдущем [этапе](https://github.com/AlexYurichRobo/WalkerServoTest):

```C++
   #include <Servo.h>
    //параметры сервопривода
    const int servos = 4;// количество сервоприводов в механизме     // сюда записываем полученные показатели среднего положения сервоприводов
    const int servoCenterConst[servos] = {87, 89, 86, 82};
    int servoAngle[servos];
    Servo servoLegs[servos];
```
Инициализируем основные управляющие параметры отклонений углов для вертикальных и горизонтальных осей:

```C++
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
```
Добавляем служебные переменные интенсивности выставления углов, через задержки, и флаги:
```C++
    //параметры сервоприводов
    int rate = 5;
    int delayTime = 100;
    bool debug = true;
    char directionFlag = 's';
```

## Функции

Отладочная функция, обеспечивающая паузу между фазами движений при движении. Принимает TRUE или FALSE.

```C++
    void DebugPhase(bool debugPhase)
```

```C++

```


```C++

```

```C++

```


```C++

```


```C++

```


```C++

```


```C++

```

