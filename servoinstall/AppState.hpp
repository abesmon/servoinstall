//
//  AppState.hpp
//  servoinstall
//
//  Created by Алексей Лысенко on 11.01.2021.
//

#ifndef AppState_hpp
#define AppState_hpp

#include "FeatherBlock.h"
#include "Config.h"

class AppState {
public:
    AppState() {}
    FeatherBlock feathersBlock[FEATHERSCOUNT] = {
        FeatherBlock(2, 120, 50),
        FeatherBlock(3, 120, 50),
        FeatherBlock(4, 120, 50),
        FeatherBlock(5, 120, 30),
        FeatherBlock(6, 120, 50)
    };
};

#endif /* AppState_hpp */
