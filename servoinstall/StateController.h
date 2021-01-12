//
// Created by Алексей Лысенко on 11.01.2021.
//

#ifndef SERVOINSTALL_STATECONTROLLER_H
#define SERVOINSTALL_STATECONTROLLER_H

#include "GlobalState.h"
#include "AppState.hpp"

class StateController {
protected:
    GlobalState _myState;
public:
    StateController(GlobalState myState) {
       _myState = myState;
    }
    virtual GlobalState loop(AppState appState) {
      return _myState;
    }
};


#endif //SERVOINSTALL_STATECONTROLLER_H
