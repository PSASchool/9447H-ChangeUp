#include "main.h"
#include "globals.hpp"

#include "class/control/auton.hpp"
#include "class/control/intakes.hpp"
#include "class/control/slew.hpp"
#include "class/displayController.hpp"
#include "class/control/odom.hpp"
#include "class/control/chassis.hpp"


Display display;
Auton auton;
static Intake intake;
static Slew slew;
static Chassis chassis;

void initialize() {
  display.setup();
  intake.iiInit();
  if(isSetup){display.destroy();}
}


void disabled(){}

void competition_initialize() {
  display.display();
  while(1){
    display.backgroundcheck();
    while(alliance==0){display.setAlliance(); pros::delay(15);}
      display.arcChecker();
      display.setVars();
      display.updateSensors();
  pros::delay(20);}
}

void opcontrol() {
  pros::Task intakeTask(Intake::runIntakes);
  intake.intakeLock();
  chassis.setState(COAST);
  while (true) {
    // double leftValue = LOdometer.get_position();
    // double rightvalue = ROdometer.get_position();
    // double averageValue = (fabs(leftValue) + fabs(rightvalue))/2;

    // printf("Average: %d\n", averageValue);
    slew.tankDrive(900, 500, 900);
    // intake.runIntakes();
    // intakeTask.set_priority(TASK_PRIORITY_DEFAULT+1);
    // intakeTask.
    pros::delay(15);
  }
}
void autonomous() {
  // pros::Task odomTask(Odom::updatePosition);
  // printf("startPos, firstPos, secondPos, thirdPos %d %d %d %d \n", startPos, firstPos, secondPos, thirdPos);
 if(alliance == 3){auton.runSkills();} //If Skills was selected it will run skills else it will build the auton.
 else{auton.run();}
  // auton.runTests();
}
