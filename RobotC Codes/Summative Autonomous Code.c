#pragma config(Sensor, in2,    lineFollowerRIGHT, sensorLineFollower)
#pragma config(Sensor, in3,    lineFollowerCENTER, sensorLineFollower)
#pragma config(Sensor, in4,    lineFollowerLEFT, sensorLineFollower)
#pragma config(Sensor, dgtl2,  sonarSensor,    sensorSONAR_inch)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex269_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port3,           armMotor,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftMotor,     tmotorVex269_MC29, openLoop, driveLeft)
#pragma config(Motor,  port5,           clawarmMotor,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           clawturnMotor, tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	int threshold = 505;      /* found by taking a reading on both DARK and LIGHT    */
                            /* surfaces, adding them together, then dividing by 2. */
  int go = 1;						     	// Variable 1 used to run and 0 to stop

	wait1Msec(2000);

	motor[rightMotor] = 63; //Turn on to track from start
	motor[leftMotor] = 50;
	wait1Msec(1500);

	while(go == 1) 							//First leg pick up first pipe
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
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
    if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		go = 0;
		}
	}
	if (go == 0)
	{
		motor[clawMotor] = 63;  //Close claw (Make sure pipe is in between claw)
		wait1Msec(1500);

		motor[rightMotor] = -40; //Move back a bit
		motor[leftMotor] = -40;
		wait1Msec(1000);

		motor[rightMotor] = 40; //Point turn 180
		motor[leftMotor] = -40;
		wait1Msec(1000);

		go = 1;
	}
	while(go == 1) 							//Second leg drop off first pipe
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
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
    if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		go = 0;
		}
	}
	if (go == 0)
	{

		motor[clawturnMotor] = -63; //Rotate claw 90deg (horizontal)
		wait1Msec(1000);

		motor[clawMotor] = -63;  //Open claw
		wait1Msec(1500);

		motor[clawturnMotor] = 63; //Rotate claw 90deg (Vertical)

		motor[rightMotor] = -40; //Move back a bit
		motor[leftMotor] = -40;
		wait1Msec(1000);

		motor[rightMotor] = 40; //Point turn 180
		motor[leftMotor] = -40;
		wait1Msec(1000);

		go = 1;
	}
	while(go == 1) 							//Third leg pick up second pipe
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
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
    if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		go = 0;
		}
	}
	if (go == 0)
	{

		motor[rightMotor] = 40; //Turn left a bit
		motor[leftMotor] = -40;
		wait1Msec(0500);

		motor[rightMotor] = 40; //Move up a bit
		motor[leftMotor] = 40;
		wait1Msec(0350);

		motor[clawMotor] = 63;  //Close claw (Make sure pipe is in between claw)
		wait1Msec(1500);

		motor[rightMotor] = -40; //Move back a bit
		motor[leftMotor] = -40;
		wait1Msec(0350);

		motor[rightMotor] = -40; //Turn right a bit
		motor[leftMotor] = 40;
		wait1Msec(0500);

		motor[rightMotor] = -40; //Move back a bit
		motor[leftMotor] = -40;
		wait1Msec(1000);

		motor[rightMotor] = 40; //Point turn 180
		motor[leftMotor] = -40;
		wait1Msec(1000);

		go = 1;
	}
	while(go == 1) 							//Fourth leg drop off second pipe
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
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
    if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		go = 0;
		}
	}
	if (go == 0)
	{

	motor[clawturnMotor] = -63; //Rotate claw 90deg (horizontal)
	wait1Msec(1000);

	motor[clawMotor] = -63;  //Open claw
	wait1Msec(1500);

	motor[clawturnMotor] = 63; //Rotate claw 90deg (Vertical)

	motor[rightMotor] = -40; //Move back a bit
	motor[leftMotor] = -40;
	wait1Msec(1000);

	motor[rightMotor] = 40; //Point turn 180
	motor[leftMotor] = -40;
	wait1Msec(1000);

	go = 1;
	}
	while(go == 1) 							//Fifth leg pick up third pipe
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
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
    if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		go = 0;
		}
	}
	if (go == 0)
	{

		motor[rightMotor] = -40; //Turn right a bit
		motor[leftMotor] = 40;
		wait1Msec(0500);

		motor[rightMotor] = 40; //Move up a bit
		motor[leftMotor] = 40;
		wait1Msec(0350);

		motor[clawMotor] = 63;  //Close claw (Make sure pipe is in between claw)
		wait1Msec(1500);

		motor[rightMotor] = -40; //Move back a bit
		motor[leftMotor] = -40;
		wait1Msec(0350);

		motor[rightMotor] = 40; //Turn left a bit
		motor[leftMotor] = -40;
		wait1Msec(0500);

		motor[rightMotor] = -40; //Move back a bit
		motor[leftMotor] = -40;
		wait1Msec(1000);

		motor[rightMotor] = 40; //Point turn 180
		motor[leftMotor] = -40;
		wait1Msec(1000);

		go = 1;
	}
	while(go == 1) 							//Final leg drop off third pipe
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
      motor[leftMotor]  = 40;
      motor[rightMotor] = 0;
    }
    // CENTER sensor sees dark:
    if(SensorValue(lineFollowerCENTER) > threshold)
    {
      // go straight
      motor[leftMotor]  = 40;
      motor[rightMotor] = 40;
    }
    // LEFT sensor sees dark:
    if(SensorValue(lineFollowerLEFT) > threshold)
    {
      // counter-steer left:
      motor[leftMotor]  = 0;
      motor[rightMotor] = 40;
    }
    if(SensorValue(sonarSensor) > 20  || SensorValue(sonarSensor) == -1)		// Loop while robot's Ultrasonic sensor is further than 20 inches away from an object
		{                                                                         // || (or) it is '-1'.  (-1 is the value returned when nothing is in it's visable range)
		go = 0;
		}
	}
	if (go == 0)
	{

	motor[clawturnMotor] = -63; //Rotate claw 90deg (horizontal)
	wait1Msec(1000);

	motor[clawMotor] = -63;  //Open claw
	wait1Msec(1500);

	motor[clawturnMotor] = 63; //Rotate claw 90deg (Vertical)
	}
}
