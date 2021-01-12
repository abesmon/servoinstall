//
// Created by Алексей Лысенко on 11.01.2021.
//

#include "App.h"
#include <Arduino.h>

void App::setup() {
for (int i = 0; i < FEATHERSCOUNT; i++) {
        _appState.feathersBlock[i].bootstrap();
    }
    Serial.begin(9600);
    pinMode(LEDPIN, OUTPUT);
}

void App::loop() {
    _globalState = _controllers[_globalState]->loop(_appState);
}
