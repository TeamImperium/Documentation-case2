int state = 0; // ВКЛ/ВЫКЛ ВСЕЙ ПРОГРАММЫ
int colors[4] = {1, 2, 3, 4};   // 1 - КРАСНЫЙ; 2 - ЗЕЛЕНЫЙ; 3 - СИНИЙ; 4 - БЕЛЫЙ. ПЕРВЫЕ ДВА ЗНАЧЕНИЯ ДЛЯ ПЕРВОГО КОНТЕЙНЕРА, ОСТАЛЬНЫЕ - ДЛЯ ВТОРОГО КОНТЕЙНЕРА


bool belt = false; // ВКЛ/ВЫКЛ КОНВЕЙЕРНОЙ ЛЕНТЫ
bool ultrasonic = false; // ВКЛ/ВЫКЛ ДАТЧИКА РАССТОЯНИЯ 
bool color_sensor = false; // ВКЛ/ВЫКЛ ДАТЧИКА ЦВЕТА
bool sorter1 = false; // ВКЛ/ВЫКЛ ПЕРВОГО ПОРШНЯ СОРТИРОВЩИКА
bool sorter2 = false; // ВКЛ/ВЫКЛ ВТОРОГО ПОРШНЯ СОРТИРОВЩИКА


int 1distance = 20; // ДИСТАНЦИЯ, НА КОТОРОЙ КУБИК БУДЕТ НАХОДИТЬСЯ ОКОЛО ПЕРВОГО КОНТЕЙНЕРА
int 2distance = 10; // ДИСТАНЦИЯ, НА КОТОРОЙ КУБИК БУДЕТ НАХОДИТЬСЯ ОКОЛО ВТОРОГО КОНТЕЙНЕРА
int distance, cm; // ПОКАЗАЗАНИЯ ДАТЧИКА РАССТОЯНИЯ


int colorOUT[3]; // ВЫХОДНЫЕ ДАННЫЕ О ЦВЕТЕ КУБИКА
int color; // ЦВЕТ КОНКРЕТНОГО КУБИКА ДЛЯ СОРТИРОВКИ ЕГО В НУЖНЫЙ КОНТЕЙНЕР (ЗНАЧЕНИЯ ЦВЕТОВ СМ ВЫШЕ)
int freq = 0;

// ДАТЧИК РАССТОЯНИЯ
#define PIN_TRIG 
#define PIN_ECHO 
// ДАТЧИК РАССТОЯНИЯ


// ДАТЧИК ЦВЕТА
#define PIN_S0 
#define PIN_S1
#define PIN_S2 
#define PIN_S3 
#define PIN_OUT 
// ДАТЧИК ЦВЕТА


// ДРАЙВЕР
#define PIN_IN1 
#define PIN_IN2
// ДРАЙВЕР


// СЕРВО 1
#define PIN_PWM1 
// СЕРВО 1


// СЕРВО 2
#define PIN_PWM2  
// СЕРВО 2


// BLUETOOTH МОДУЛЬ
#define PIN_TX 
#define PIN_RX 
// BLUETOOTH МОДУЛЬ


// ФУНКЦИЯ ДЛЯ РАБОТЫ СЕРВОМОТОРА 1
void servo1WORK()
{
	int pulseWidth1 = (90 * 11) + 500; 
	digitalWrite(PIN_PWM1, HIGH);
	delayMicroseconds(pulseWidth1);
	digitalWrite(PIN_PWM1, LOW);
	delay(20 - pulseWidth1 / 1000);
}
// ФУНКЦИЯ ДЛЯ РАБОТЫ СЕРВОМОТОРА 1


// ФУНКЦИЯ ДЛЯ РАБОТЫ СЕРВОМОТОРА 2
void servo2WORK()
{
	int pulseWidth2 = (90 * 11) + 500; 
	digitalWrite(PIN_PWM2, HIGH);
	delayMicroseconds(pulseWidth2);
	digitalWrite(PIN_PWM2, LOW);
	delay(20 - pulseWidth2 / 1000);
}
// ФУНКЦИЯ ДЛЯ РАБОТЫ СЕРВОМОТОРА 2


// ФУНКЦИЯ ДЛЯ РАБОТЫ ДАТЧИКА РАССТОЯНИЯ
void ultrasonicWORK()
{
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(PIN_TRIG, HIGH);

  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  distance = pulseIn(PIN_ECHO, HIGH);
  cm = (distance / 2) / 29.1;
        
  delay(250);
}
void ultrasonicSTOP()
{
  digitalWrite(PIN_TRIG, LOW);
}
// ФУНКЦИЯ ДЛЯ РАБОТЫ ДАТЧИКА РАССТОЯНИЯ


// ФУНКЦИЯ ДЛЯ РАБОТЫ КОНВЕЙЕРНОЙ ЛЕНТЫ
void beltWORK()
{
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN1, LOW);
}
void beltSTOP()
{
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN1, LOW);
}
// ФУНКЦИЯ ДЛЯ РАБОТЫ КОНВЕЙЕРНОЙ ЛЕНТЫ


// ФУНКЦИЯ ДЛЯ РАБОТЫ ДАТЧИКА ЦВЕТА
void colorWORK()
{
  digitalWrite(pinS2,LOW); // ВЫХОДНЫЕ ДАННЫЕ С RED ФИЛЬТРОМ
  digitalWrite(pinS3,LOW);
  freq = pulseIn(pinOut, 0);
  colorOUT[0] = freq;
  delay(150);

  digitalWrite(pinS2,HIGH); // ВЫХОДНЫЕ ДАННЫЕ С GREEN ФИЛЬТРОМ
  digitalWrite(pinS3,HIGH);
  freq = pulseIn(pinOut, 0);
  colorOUT[1] = freq;
  delay(150);

  digitalWrite(pinS2,LOW); // ВЫХОДНЫЕ ДАННЫЕ С BLUE ФИЛЬТРОМ
  digitalWrite(pinS3,HIGH);
  freq = pulseIn(pinOut, 0);
  colorOUT[2] = freq;
  delay(150);
}
void colorSTOP()
{
  digitalWrite(PIN_S0, LOW);
  digitalWrite(PIN_S1, LOW);
  digitalWrite(PIN_S2, LOW);
  digitalWrite(PIN_S3, LOW);
}
// ФУНКЦИЯ ДЛЯ РАБОТЫ ДАТЧИКА ЦВЕТА


void setup() 
{
pinMode(PIN_TRIG, OUTPUT); // ПОДКЛЮЧЕНИЕ ВСЕХ МОДУЛЕЙ В СООТВЕТСТВУЮЩИЕ ВХОДЫ/ВЫХОДЫ
pinMode(PIN_ECHO, INPUT);

pinMode(PIN_S0, OUTPUT);
pinMode(PIN_S1, OUTPUT);
pinMode(PIN_S2, OUTPUT);
pinMode(PIN_S3, OUTPUT);
pinMode(PIN_OUT, INPUT);

pinMode(PIN_IN1, OUTPUT);
pinMode(PIN_IN2, OUTPUT);

pinMode(PIN_PWM1, OUTPUT);

pinMode(PIN_PWM2, OUTPUT);

Serial.begin(9600);

digitalWrite(pinS0,HIGH);
digitalWrite(pinS1,LOW);
}



void loop()
{

if (Serial.available())
  {
    colors = Serial.read();   // ВЫБОР ЦВЕТОВ
    state = Serial.read();    // НАЧАЛО РАБОТЫ
    if (state == 0)
    {
      digitalWrite(PIN_TRIG, LOW); // ОТКЛЮЧЕНИЕ ВСЕХ МОДУЛЕЙ ПРИ ОСТАНОВКЕ РАБОТЫ И ПРИ ПЕРВОМ ЗАПУСКЕ
      digitalWrite(PIN_S0, LOW);
      digitalWrite(PIN_S1, LOW);
      digitalWrite(PIN_S2, LOW);
      digitalWrite(PIN_S3, LOW);
      digitalWrite(PIN_IN1, LOW);
      digitalWrite(PIN_IN2, LOW);
      digitalWrite(PIN_PWM1, LOW);
      digitalWrite(PIN_PWM2, LOW);
    }
    if (state == 1)
    {
      // НАЧАЛО РАБОТЫ
    }
  }
}
