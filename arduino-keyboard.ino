#include <Bounce2.h>
#include <Keyboard.h>
#include <KeyboardLayout.h>

const int pedal1Pin = 3;

Bounce debouncerPedal = Bounce();

void setup() {
  pinMode(pedal1Pin, INPUT_PULLUP);
  debouncerPedal.attach(pedal1Pin);
  debouncerPedal.interval(50);
  Keyboard.begin();
}

void loop() {
  debouncerPedal.update();

  if (debouncerPedal.rose()) {
    Keyboard.release(KEY_KP_DOT);
  }

  if (debouncerPedal.fell()) {
    Keyboard.press(KEY_KP_DOT);
  }
}
