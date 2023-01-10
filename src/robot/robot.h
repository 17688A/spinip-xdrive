#include "main.h"

#define MTR_PORT_LF 1
#define MTR_PORT_LB 3
#define MTR_PORT_RF 2
#define MTR_PORT_RB 4

// main
void on_center_button(void);

//#include "../robot/config.cpp"
//...

//#include "../robot/auto.cpp"
void autonomous(void);

//#include "../robot/event.cpp"
void initialize(void);
void competition_initialize(void);
void disabled(void);

//#include "../robot/teleop.cpp"
void opcontrol(void);