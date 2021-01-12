//
//  SerialMotionController.hpp
//  servoinstall
//
//  Created by Алексей Лысенко on 12.01.2021.
//

#ifndef SerialMotionController_hpp
#define SerialMotionController_hpp

#include "StateController.h"
#include <Arduino.h>

class SerialMotionController: public StateController {
public:
    SerialMotionController(): StateController(globalStateSerialMotion) {};
    GlobalState loop(AppState appState);
private:
    String getValue(String data, char separator, int index);
};

#endif /* SerialMotionController_hpp */
