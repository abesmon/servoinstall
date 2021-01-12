//
//  DebugController.hpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#ifndef DebugController_hpp
#define DebugController_hpp

#include "StateController.h"

class DebugController: public StateController {
public:
    DebugController(): StateController(globalStateDebug) { };
    GlobalState loop(AppState appState);
};

#endif /* DebugController_hpp */
