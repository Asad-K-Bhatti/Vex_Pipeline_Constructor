#pragma config(Sensor, in1,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in2,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl2,  frontsonarSensor, sensorSONAR_cm)
#pragma config(Sensor, dgtl6,  backsonarSensor, sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port5,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorVex269_MC29, openLoop, driveLeft)
#pragma config(Motor,  port7,           clawarmMotor,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           clawturnMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawMotor,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	motor[clawarmMotor] = 40;

	int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */

  wait1Msec(2000);

  motor[leftMotor] = -40;
  motor[rightMotor] = -63;
	wait1Msec(1370);

	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
	wait1Msec(0500);

	while(SensorValue(frontsonarSensor) > 14  || SensorValue(frontsonarSensor) == -1)		//First leg pick up first pipe
																																						// Loop while robot's Ultrasonic sensor is further than 7cm away from an object
																																						// || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
	{
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+



    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = -60;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = -60;
      motor[rightMotor] = -60;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = -60;
    }
	}

	if(SensorValue(frontsonarSensor) < 14  || SensorValue(frontsonarSensor) != -1)

	{
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(0500);

		motor[clawMotor] = 63;  //Close claw (Make sure pipe is in between claw)
		wait1Msec(1500);

		motor[leftMotor] = 40;
		motor[rightMotor] = 40;
		wait1Msec(0500);

		motor[clawturnMotor] = 63;
		wait1Msec(0500);

		motor[leftMotor] = 60;
		motor[rightMotor] = 60;
		wait1Msec(0500);

	}

	if(SensorValue(backsonarSensor) < 10  || SensorValue(backsonarSensor) != -1)

	{
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(0500);

		motor[leftMotor] = 0;
		motor[rightMotor] = -127;
		wait1Msec(0500);

		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(0500);
	}

	while(SensorValue(frontsonarSensor) > 14  || SensorValue(frontsonarSensor) == -1)		//Second leg drop off first pipe
																																						// Loop while robot's Ultrasonic sensor is further than 7cm away from an object
																																						// || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
	{
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+
    displayLCDCenteredString(0, "LEFT  CNTR  RGHT");        //  Display   |
    displayLCDPos(1,0);                                     //  Sensor    |
    displayNextLCDNumber(SensorValue(lineFollowerLEFT));    //  Readings  |
    displayLCDPos(1,6);                                     //  to LCD.   |
    displayNextLCDNumber(SensorValue(lineFollowerCENTER));  //            |
    displayLCDPos(1,12);                                    //  L  C  R   |
    displayNextLCDNumber(SensorValue(lineFollowerRIGHT));   //  x  x  x   |
    // - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -+



    // RIGHT sensor sees dark:
    if(SensorValue(lineFollowerRIGHT) > threshold)
    {
      // counter-steer right:
      motor[leftMotor]  = -60;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = -60;
      motor[rightMotor] = -60;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = -60;
    }
	}

	if(SensorValue(frontsonarSensor) < 14  || SensorValue(frontsonarSensor) != -1)		//First leg pick up first pipe
																																						// Loop while robot's Ultrasonic sensor is further than 7cm away from an object
																																						// || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
	{
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(0500);

		motor[clawMotor] = -63;  //Close claw (Make sure pipe is in between claw)
		wait1Msec(1500);

		motor[leftMotor] = 40;
		motor[rightMotor] = 40;
		wait1Msec(0500);

		motor[clawturnMotor] = -63;
		wait1Msec(0500);

		motor[leftMotor] = 60;
		motor[rightMotor] = 60;
		wait1Msec(0500);

	}

	if(SensorValue(backsonarSensor) < 10  || SensorValue(backsonarSensor) != -1)

	{
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(0500);

		motor[leftMotor] = 0;
		motor[rightMotor] = 127;
		wait1Msec(0500);

		motor[leftMotor] = 0;
		motor[rightMotor] = 0;
		wait1Msec(0500);
	}
}
