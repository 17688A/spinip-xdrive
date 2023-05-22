#include "./robot.h"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	pros::Motor lf_mtr(MTR_PORT_LF);
	pros::Motor lb_mtr(MTR_PORT_LB);
	pros::Motor rf_mtr(MTR_PORT_RF);
	pros::Motor rb_mtr(MTR_PORT_RB);

	while (true) {

	int spin = master.get_analog(ANALOG_RIGHT_X);


	int straight = master.get_analog(ANALOG_LEFT_Y);


	int strafe = master.get_analog(ANALOG_RIGHT_Y);

	int lfDrive  = spin + straight + strafe;
	int lbDrive  = spin + straight - strafe;
	int rfDrive  = spin - straight - strafe;
	int rbDrive  = spin - straight + strafe;

	lf_mtr.move(lfDrive);
	lb_mtr.move(lbDrive);
	rf_mtr.move(rfDrive);
	rb_mtr.move(rbDrive);

	pros::delay(20);
	}
}