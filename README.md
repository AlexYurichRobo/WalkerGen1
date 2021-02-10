# WalkerGen1

## Базовые функции для движения робота

Процесс разработки движений робота описан на канале, в плейлите, ему посвященном:


[![Сборка робота](https://sun9-29.userapi.com/impg/weG9ZLaRDRPLj1wx-14dwFZdoW_zb94o8bGiBQ/HYM6C9fTb_c.jpg?size=2560x1920&quality=96&proxy=1&sign=099709e6688fc18dbf858e1c27c8da13&type=album)](https://www.youtube.com/watch?v=vLxFxW2TRR0&list=PLPlEq5SS8JN62263Q4-hY7qEeuCIrCNkc&index=3)

Рассмотрим основные базовые движения робота.

Объявление переменных и объектов класса Servo. Сюдаже вносим полученные углы, полученные в процессе калибровки на предыдущем [этапе](https://github.com/AlexYurichRobo/WalkerServoTest):

```C++
    #include <Servo.h>
    //параметры сервопривода
    const int servos = 4;// количество сервоприводов в механизме 
    
    // сюда записываем полученные значения среднего положения сервоприводов
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

# Функции

1. **DebugPhase** - Отладочная функция, обеспечивающая паузу между фазами движений при движении. Принимает TRUE или FALSE:
```C++
    void DebugPhase(bool debugPhase)
```

2. **SweepVer** - базовая функция отклонения робота вправо или влево, принимает параметром символы 'l' или 'r' соответственно отклонение на левую или правую ногу :
```C++
   void SweepVer(char dirSweep)
```

3. **BalanceVer** - базовая функция возвращения горизонтальных оей в первоначальное положение, указанное в масиве servoCenterConst[servos]
```C++
   void BalanceVer()
```

4. **SweepHor** - базовая функция  функция для совершения шага, аналогична функции SweepVer()
```C++
   void SweepHor(char dirSweep)
```

5. **BalanceHor** - базовая функция выравнивания вертикальных осей в начальное положение
```C++
   void BalanceHor()
```

6. **ForwardSlow** - функция для движения вперёд. Принимает параметром количествопар шагов. Базируется на последовательном вызове вышеописанных функций для соответствующей фазы движения. По умолчанию совершает 1 шаг
```C++
   void ForwardSlow(int steps = 1)
```

7. **BackwardSlow** - функция для движения назад. Принимает параметром количествопар шагов. Базируется на последовательном вызове вышеописанных функций для соответствующей фазы движения. По умолчанию совершает 1 шаг
```C++
void BackwardSlow(int steps = 1)
```

8. **StopSlow** - функция описывающая процесс возвращения ног в начальное положение после движения вперёд или назад
```C++
void StopSlow()
```

9. **TurnLeft** - функция для поворота налево примерно на 90 градусов параметром необходимо подобрать угол, который будет отличаться для разных поверхностей и скоростей, в силу проскальзывания ступней.
```C++
void TurnLeft(int angTurn = 36)
```

10. **TurnRight** - аналогична TurnLeft, но обеспечивает поворот направо
```C++
void TurnRight(int angTurn = 36)
```

11.**CourseDevLeft** - oтклонение курса на угол, передаваемый параметром
```C++
void CourseDevLeft(int angTurn = 36)
```

12. **CourseDevRight**  Отклонение курса на угол, передаваемый параметром
```C++
void CourseDevRight(int angTurn = 36)
```

