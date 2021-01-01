#include <Arduino.h>

#include "SPI.h"
#include "Adafruit_GFX.h"

#include <GxEPD.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#include <GxGDEW027C44/GxGDEW027C44.h> //  2.7" b/w/r

#define ELINK_BUSY 4
#define ELINK_RESET 16
#define ELINK_DC 17
#define ELINK_SS 5

#include <Fonts/FreeSans9pt7b.h>

#define DEFALUT_FONT FreeSans9pt7b

GxIO_Class io(SPI, ELINK_SS, ELINK_DC, ELINK_RESET);
GxEPD_Class display(io, ELINK_RESET, ELINK_BUSY);

void setup()
{
  // put your setup code here, to run once:

  display.init();
  display.setRotation(1);
  display.eraseDisplay();
  display.setTextColor(GxEPD_BLACK);
  display.setFont(&DEFALUT_FONT);
  display.setTextSize(0);
  display.setCursor(60, 50);
  display.print("Hallo Matze");
  display.update();
}

void loop()
{
  // put your main code here, to run repeatedly:
}