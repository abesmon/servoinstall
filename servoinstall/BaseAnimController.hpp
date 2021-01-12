//
//  BaseAnimController.hpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#ifndef BaseAnimController_hpp
#define BaseAnimController_hpp

#include "StateController.h"

class BaseAnimController: public StateController {
public:
    BaseAnimController(): StateController(globalStateBaseAnim) { };
    GlobalState loop(AppState appState);
};

#endif /* BaseAnimController_hpp */
