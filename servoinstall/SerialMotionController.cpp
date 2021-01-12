//
//  SerialMotionController.cpp
//  servoinstall
//
//  Created by Алексей Лысенко on 12.01.2021.
//

#include "SerialMotionController.hpp"

int firstInLoop = true;

GlobalState SerialMotionController::loop(AppState appState) {
    if (firstInLoop) {
      Serial.println("Entered Serial loop");
      firstInLoop = false;
    }
    GlobalState returnState = StateController::loop(appState);

    String content = "";
    while(Serial.available() > 0) {
        content = Serial.readString();
    }
    
    if (content != "") {
      if (content == "stop") {
        returnState = globalStateIdle;
      }

      if (content.startsWith("f")) {      
        for (int i=1; i<= 5; i++) {
          String featherPos = getValue(content, ';', i);
          if (featherPos != "") {
            int featherIntPos = featherPos.toInt(); // 1...9999
            int pos = map(featherIntPos, 1, 9999, appState.feathersBlock[i].lowPos, appState.feathersBlock[i].highPos);
            appState.feathersBlock[i - 1].write(pos);
          }
        }
      }
    }

    if (returnState != _myState) {
      firstInLoop = true;
    }
    
    return returnState;
}

String SerialMotionController::getValue(String data, char separator, int index) {
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
