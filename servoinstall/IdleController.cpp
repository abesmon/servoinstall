//
//  IdleController.cpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#include "IdleController.hpp"
#include <Arduino.h>

GlobalState IdleController::loop(AppState appState) {
    String content = "";
    while(Serial.available() > 0) {
        content = Serial.readString();
    }

    if (content != "") {
        if (content == "debug") {
            return globalStateDebug;
        } else if (content == "anim") {
            return globalStateBaseAnim;
        } else if (content == "goHigh") {
            goHigh(appState);
        } else if (content == "serial") {
            return globalStateSerialMotion;
        }else {
            Serial.println("Command not supported");
            return StateController::loop(appState);
        }
    }
    return StateController::loop(appState);
}

void IdleController::goHigh(AppState appState) {
  for (int i = 0; i < FEATHERSCOUNT; i++) {
    appState.feathersBlock[i].write(appState.feathersBlock[i].highPos);
  }
}
