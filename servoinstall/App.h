//
// Created by Алексей Лысенко on 11.01.2021.
//

#ifndef SERVOINSTALL_APP_H
#define SERVOINSTALL_APP_H

#include "FeatherBlock.h"
#include "Config.h"
#include "GlobalState.h"

#include "StateController.h"
#include "IdleController.hpp"
#include "DebugController.hpp"
#include "BaseAnimController.hpp"
#include "SerialMotionController.hpp"

class App {
private:
    GlobalState _globalState = globalStateIdle;

    IdleController _idleController = IdleController();
    DebugController _debugController = DebugController();
    BaseAnimController _baseAnimController = BaseAnimController();
    SerialMotionController _serialMotionController = SerialMotionController();
    
    StateController *_controllers[4] = {
      &_idleController,
      &_debugController,
      &_baseAnimController,
      &_serialMotionController
    };
    AppState _appState = AppState();
    
public:
    App() {};
    void setup();
    void loop();
};


#endif //SERVOINSTALL_APP_H
