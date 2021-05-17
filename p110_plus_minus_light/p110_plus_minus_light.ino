#define PLUS_BUTTON_PIN     2
#define MINUS_BUTTON_PIN    3
#define LED_PIN             9

int brightness = 100;
boolean plusUp = true;
boolean minusUp = true;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(PLUS_BUTTON_PIN, INPUT_PULLUP);
  pinMode(MINUS_BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
  analogWrite(LED_PIN, brightness);
  // реагируем на нажатия с помощью функции, написанной нами
  plusUp = handleClick(PLUS_BUTTON_PIN, plusUp, +35);
  minusUp = handleClick(MINUS_BUTTON_PIN, minusUp, -35);
}
// Собственная функция с 3 параметрами: номером пина с кнопкой
// (buttonPin), состоянием до проверки (wasUp) и градацией
// яркости при клике на кнопку (delta). Функция возвращает
// (англ. return) обратно новое, текущее состояние кнопки
boolean handleClick(int buttonPin, boolean wasUp, int delta)
{
  boolean isUp = digitalRead(buttonPin);
  if (wasUp && !isUp) {
    delay(10);
    isUp = digitalRead(buttonPin);
    // если был клик, меняем яркость в пределах от 0 до 255
    if (!isUp)    
      brightness = constrain(brightness + delta, 0, 255);
  }
  return isUp; // возвращаем значение обратно, в вызывающий код
}