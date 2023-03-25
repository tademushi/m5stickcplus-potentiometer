#include <M5StickCPlus.h>

#define POT_VIN 3.3
#define POT_PIN GPIO_NUM_36

void setup()
{
    M5.begin();

    M5.Lcd.setRotation(3);
    M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
    M5.Lcd.setTextSize(2);
    M5.Lcd.fillScreen(TFT_BLACK);

    pinMode(POT_PIN, INPUT);
    gpio_pulldown_dis(GPIO_NUM_25);
    gpio_pullup_dis(GPIO_NUM_25);
}

void loop()
{
    float vout = analogRead(POT_PIN) * POT_VIN / 4095.0;
    Serial.println(vout);

    M5.Lcd.setCursor(0, 0);
    M5.Lcd.printf("%.1f V    ", vout);

    delay(100);
}
