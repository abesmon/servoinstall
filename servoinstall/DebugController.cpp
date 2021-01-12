//
//  DebugController.cpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#include "DebugController.hpp"
#include <arduino.h>

int incomingByte = 0;
int debugServoIndex = 0;

GlobalState DebugController::loop(AppState appState) {
    GlobalState resultState = StateController::loop(appState);
    
    if (Serial.available() > 0) {
        // read the incoming byte:
        //Serial.read();
        incomingByte = Serial.parseInt();
        if (incomingByte > 0) {
            // say what you got:
            Serial.print("I received: ");
            Serial.println(incomingByte, DEC);
            appState.feathersBlock[debugServoIndex].write(incomingByte);
        } else if (incomingByte <= -1 && incomingByte >= -5) {
            debugServoIndex = (incomingByte * -1) - 1;
            Serial.print("Switched to debug: ");
            Serial.println(debugServoIndex);
        } else if (incomingByte == -9) {
            resultState = globalStateIdle;
        }
    }
    
    return resultState;
}
