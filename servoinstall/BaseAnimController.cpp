//
//  BaseAnimController.cpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#include "BaseAnimController.hpp"
#include <Arduino.h>

float timeDiff = 0;
float lastFrameTime = 0;
float circlePos = 0;
float degreesPerSec = 5;
float degreesOffset = 1;

GlobalState BaseAnimController::loop(AppState appState) {
    analogWrite(LEDPIN, ((sin(millis() * 0.001) + 1) * 0.5) * LEDMAX + LEDMIN);
    float newFrame = millis();
    timeDiff = (newFrame - lastFrameTime) / 1000;
    lastFrameTime = newFrame;
    circlePos += (degreesPerSec * timeDiff);
    
#if DEBUG
    Serial.println("from prevFrame past: " + String(timeDiff));
    Serial.println("Circlepos: " + String(circlePos));
#endif
    
    for (int i = 0; i < FEATHERSCOUNT; i++) {
        
        float servoCirclePos = circlePos + (i * degreesOffset);
        float funcPos = ((sin(servoCirclePos) + 1) * 0.5) * 1000;
#if DEBUG
        Serial.print("Servo " + String(i) + " servoCirclePos: " + String(servoCirclePos));
        Serial.print(" | func pos: ");
        Serial.print(funcPos);
#endif
        int pos = map(funcPos, 0, 1000, appState.feathersBlock[i].lowPos, appState.feathersBlock[i].highPos);
        
        appState.feathersBlock[i].write(pos);
    }
#if DEBUG
    Serial.println("");
#endif
    
    delay(ANIM_DELAY);

    GlobalState resultState = StateController::loop(appState);
    String content = "";
    while(Serial.available() > 0) {
        content = Serial.readString();
    }
    if (content == "stop") {
      resultState = globalStateIdle;
    }
    
    return resultState;
}
