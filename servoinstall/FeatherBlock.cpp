#include "FeatherBlock.h"

FeatherBlock::FeatherBlock(int port, int lowPos, int highPos) {
  _servoPort = port;
  this->lowPos = lowPos;
  this->highPos = highPos;
}

void FeatherBlock::bootstrap() { 
  _servo.attach(_servoPort);
  _servo.write(lowPos);
}

void FeatherBlock::write(int angle) { _servo.write(angle); }
