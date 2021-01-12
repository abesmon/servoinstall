#pragma once /* Защита от двойного подключения заголовочного файла */
#include <Servo.h>

class FeatherBlock {
  private:
    int _servoPort;
    Servo _servo;
  public:
    FeatherBlock(int port, int lowPos, int highPos);
    void bootstrap();
    void write(int angle);
    int lowPos;
    int highPos;
};
