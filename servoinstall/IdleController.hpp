//
//  IdleController.hpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#ifndef IdleController_hpp
#define IdleController_hpp

#include "StateController.h"

class IdleController: public StateController {
public:
    IdleController(): StateController(globalStateIdle) {}
    GlobalState loop(AppState state) override;
private:
    void goHigh(AppState state);
};

#endif /* IdleController_hpp */
