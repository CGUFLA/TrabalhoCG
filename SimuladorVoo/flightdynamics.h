
// *********************************************************************
// *     This software is made available only to individuals and only  *
// *     for educational purposes. Any and all commercial use is       *
// *     stricly prohibited.                                           *
// *********************************************************************
//**********************************************************************
//* Disclaimer: Any borrowed code used in this                         *
//*             program is the property of the                         *
//*             code originator. credit to them.                       *
//*                                                                    *
//*                                                                    *
//*   Unfinished                                                       *
//*   WARNING:                                                         *
//*                                                                    *
//*                                                                    *
//*                                                                    *
//**********************************************************************

// **********************************************************************
// *                                                                    *
// **********************************************************************

namespace nsCessna
{

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	// The following yaw function was written originally to get around the fact that in the glut proceedure
	// for the mouse function, it will be called per click or unclick but not for while it was held down.
	// To compensate for this the yaw movement was written as the idle callback so that while the mouse
	// button is held down the plane will yaw.  This is why the idle callback is called yaw.  It now also
	// contains the commands for movement as well as the spinning of the prop and other various things that
	// need to be done in the normal idle callback.




	void yaw(void)
	{
		turnspeed = (theta[2] / 10); // sets the speed at which the plane will turn based on how much the plane is banking
									 // a sharper bank will result in a faster turn

		if ((yaw0 == 1) && (planeyaw < 5)){ // actually rotates the plane 5 degrees when yawing in that direction
			planeyaw++; // provides for a visual yaw so it doesn't look like the world is simply turnong
		}
		if ((yaw1 == 1) && (planeyaw > -5)){ // rotates the plane -5 degrees when yawing in the other direction
			planeyaw--;
		}

		if ((yaw0 == 0) && (yaw1 == 0) && (planeyaw > 0)){  // rotates the plane back to forward position while
			planeyaw--;
			theta[1]--;// rotating the rest of the earth
		}
		if ((yaw0 == 0) && (yaw1 == 0) && (planeyaw < 0)){ // rotates the plane back to forward position
			planeyaw++;
			theta[1]++;// while rotating the rest of the earth
		}

		theta[1] = theta[1] + turnspeed; // rotates by the turnspeed

		if (yaw0 == 1) theta[1] -= 1.0; // if mouse button held, spin
		if (yaw1 == 1) theta[1] += 1.0;

		propspin += propvar;  // spins the prop at a speed that can be changed with + and - keys
		if (propspin > 360.0) propspin -= 360.0; // if it has exceeded 360 degrees it is then reduced back to 0
		if (propspin < -360.0) propspin += 360.0; // if it has gone beneath -360 degrees it is then put back to 0
		if (theta[1] > 180.0) theta[1] -= 360.0; //if maximum spin reached subtract 360 degrees
		if (theta[1] < -180.0) theta[1] += 360.0; //if minimum spin reached add 360 degrees
		speed = (propvar / 5.0);  // sets the speed of the plane's movement by the propvar which is changed with + and - keys


		//  the following large stream of if statements will set the movement of the plane across the ground by
		//  changing the position forward and sideways (z and x axis) by the rotation that it is experiencing in the y direction
		//  originally was set to be done with sin and cosin functions because they give the wanted results using the same
		//  direction degrees and would also have given a more exact direction, but for an unknown reason would send the plane
		//  to move around in small circles instead of moving forward.  Splitting up the movements into groups of degrees
		//  does not give it exact movement to the direction the plane is flying, but does give realistic movement


		if ((theta[1] <= 0) && (theta[1] >= -10)){
			forwardpos += 1 * speed;
			sidewayspos -= 0;
		}
		if ((theta[1] < -10) && (theta[1] >= -20)){
			forwardpos += 0.92 * speed;
			sidewayspos -= 0.12 * speed;
		}
		if ((theta[1] < -20) && (theta[1] >= -30)){
			forwardpos += 0.75 * speed;
			sidewayspos -= 0.25 * speed;
		}
		if ((theta[1] < -30) && (theta[1] >= -40)){
			forwardpos += 0.62 * speed;
			sidewayspos -= 0.38 * speed;
		}
		if ((theta[1] < -40) && (theta[1] >= -50)){
			forwardpos += 0.5 * speed;
			sidewayspos -= 0.5 * speed;
		}
		if ((theta[1] < -50) && (theta[1] >= -60)){
			forwardpos += 0.38 * speed;
			sidewayspos -= 0.62 * speed;
		}
		if ((theta[1] < -60) && (theta[1] >= -70)){
			forwardpos += 0.25 * speed;
			sidewayspos -= 0.75 * speed;
		}
		if ((theta[1] < -70) && (theta[1] >= -80)){
			forwardpos += 0.12 * speed;
			sidewayspos -= 0.92 * speed;
		}
		if ((theta[1] < -80) && (theta[1] >= -90)){
			forwardpos += 0.0 * speed;
			sidewayspos -= 1.0 * speed;
		}
		if ((theta[1] < -90) && (theta[1] >= -100)){
			forwardpos -= 0 * speed;
			sidewayspos -= 1 * speed;
		}
		if ((theta[1] < -100) && (theta[1] >= -110)){
			forwardpos -= .12 * speed;
			sidewayspos -= .92 * speed;
		}
		if ((theta[1] < -110) && (theta[1] >= -120)){
			forwardpos -= .20 * speed;
			sidewayspos -= .83 * speed;
		}

		if ((theta[1] < -120) && (theta[1] >= -130)){
			forwardpos -= .25 * speed;
			sidewayspos -= .75 * speed;
		}
		if ((theta[1] < -130) && (theta[1] >= -140)){
			forwardpos -= .38 * speed;
			sidewayspos -= .62 * speed;
		}
		if ((theta[1] < -140) && (theta[1] >= -150)){
			forwardpos -= .5 * speed;
			sidewayspos -= .5 * speed;
		}
		if ((theta[1] < -150) && (theta[1] >= -160)){
			forwardpos -= .62 * speed;
			sidewayspos -= .38 * speed;
		}
		if ((theta[1] < -160) && (theta[1] >= -170)){
			forwardpos -= .75 * speed;
			sidewayspos -= .25 * speed;
		}
		if ((theta[1] < -170) && (theta[1] >= -175)){
			forwardpos -= .92 * speed;
			sidewayspos -= .18 * speed;
		}
		if ((theta[1] < -175) && (theta[1] >= -180)){
			forwardpos -= 1 * speed;
			sidewayspos -= 0;
		}

		if ((theta[1] >= 0) && (theta[1] <= 10)){
			forwardpos += 1 * speed;
			sidewayspos += 0;
		}
		if ((theta[1] > 10) && (theta[1] <= 20)){
			forwardpos += 0.92 * speed;
			sidewayspos += 0.12 * speed;
		}
		if ((theta[1] > 20) && (theta[1] <= 30)){
			forwardpos += 0.75 * speed;
			sidewayspos += 0.25 * speed;
		}
		if ((theta[1] > 30) && (theta[1] <= 40)){
			forwardpos += 0.62 * speed;
			sidewayspos += 0.38 * speed;
		}
		if ((theta[1] > 40) && (theta[1] <= 50)){
			forwardpos += 0.5 * speed;
			sidewayspos += 0.5 * speed;
		}
		if ((theta[1] > 50) && (theta[1] <= 60)){
			forwardpos += 0.38 * speed;
			sidewayspos += 0.62 * speed;
		}
		if ((theta[1] > 60) && (theta[1] <= 70)){
			forwardpos += 0.25 * speed;
			sidewayspos += 0.75 * speed;
		}
		if ((theta[1] > 70) && (theta[1] <= 80)){
			forwardpos += 0.12 * speed;
			sidewayspos += 0.92 * speed;
		}
		if ((theta[1] > 80) && (theta[1] <= 90)){
			forwardpos += 0.0 * speed;
			sidewayspos += 1.0 * speed;
		}
		if ((theta[1] > 90) && (theta[1] <= 100)){
			forwardpos -= 0 * speed;
			sidewayspos += 1 * speed;
		}
		if ((theta[1] > 100) && (theta[1] <= 110)){
			forwardpos -= .12 * speed;
			sidewayspos += .92 * speed;
		}
		if ((theta[1] > 110) && (theta[1] <= 120)){
			forwardpos -= .20 * speed;
			sidewayspos += .83 * speed;
		}

		if ((theta[1] > 120) && (theta[1] <= 130)){
			forwardpos -= .25 * speed;
			sidewayspos += .75 * speed;
		}
		if ((theta[1] > 130) && (theta[1] <= 140)){
			forwardpos -= .38 * speed;
			sidewayspos += .62 * speed;
		}
		if ((theta[1] > 140) && (theta[1] <= 150)){
			forwardpos -= .5 * speed;
			sidewayspos += .5 * speed;
		}
		if ((theta[1] > 150) && (theta[1] <= 160)){
			forwardpos -= .62 * speed;
			sidewayspos += .38 * speed;
		}
		if ((theta[1] > 160) && (theta[1] <= 170)){
			forwardpos -= .75 * speed;
			sidewayspos += .25 * speed;
		}
		if ((theta[1] > 170) && (theta[1] <= 175)){
			forwardpos -= .92 * speed;
			sidewayspos += .18 * speed;
		}
		if ((theta[1] > 175) && (theta[1] <= 180)){
			forwardpos -= 1 * speed;
			sidewayspos += 0 * speed;
		}
		//end of the plane's movement section

		//the following is the former code that i tried which should have been the equivelent of the previous section
		//but sent the plane traveling in tiny circles instead, again cause is unknown.
		//sidewayspos += sin(theta[1]) * speed;
		//forwardpos += cos(theta[1]) * speed;

		glutPostRedisplay();
	}

	// **********************************************************************
	// *                                                                    *
	// **********************************************************************

	void stallanimate(){ // usually called when the plane is stalling
		updownspeed -= 2; // makes the plane lose altitude
		theta[0] += 4; // quickly makes the plane start to dive
	}





}

