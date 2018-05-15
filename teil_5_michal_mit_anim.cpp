
#include <iostream>
#include <GL/freeglut.h>
#include "Wuerfel.h"

int frame;
int cameraRotationFaktor = 2;
bool rotateCamera = true;
int cameraRotationsPerLoop = 3;

/* translate (x, y, z)  + rotation (angle, x, y, z) */
float wheel_left_1_start[7] = { 2, 1, 0.5, 0, 0, 0, 0 };
float wheel_left_2_start[7] = { 4, 1, 0.5, 0, 0, 0, 0 };
float wheel_left_3_start[7] = { 6, 1, 0.5, 0, 0, 0, 0 };
float wheel_left_4_start[7] = { 8, 1, 0.5, 0, 0, 0, 0 };

/* translate (x, y, z)  + rotation (angle, x, y, z) */
float wheel_left_1_end[7] = { 0, -4, 1.5, 0, 0, 0, 0 };
float wheel_left_2_end[7] = { 0, -2, 1.5, 0, 0, 0, 0 };
float wheel_left_3_end[7] = { 0, 4, 2, 90, 1, 0, 0 };
float wheel_left_4_end[7] = { 0, 4, 4, 90, 1, 0, 0 };

/* translate (x, y, z)  + rotation (angle, x, y, z) */
float wheel_right_1_start[7] = { 2, 1, -1, 0, 0, 0, 0 };
float wheel_right_2_start[7] = { 4, 1, -1, 0, 0, 0, 0 };
float wheel_right_3_start[7] = { 6, 1, -1, 0, 0, 0, 0 };
float wheel_right_4_start[7] = { 8, 1, -1, 0, 0, 0, 0 };

/* translate (x, y, z)  + rotation (angle, x, y, z) */
float wheel_right_1_end[7] = { 0, -4, -2, 0, 0, 0, 0 };
float wheel_right_2_end[7] = { 0, -2, -2, 0, 0, 0, 0 };
float wheel_right_3_end[7] = { 0, 4, -2, 90, 1, 0, 0 };
float wheel_right_4_end[7] = { 0, 4, -4, 90, 1, 0, 0 };

/* translate (x, y, z) + rotation (angle, x, y, z) + base radius*/
float leg_left_start[8] = { 0, 2, 0, 90, 0, 1, 0, 1 };
float leg_right_start[8] = { 0, 2, 0, 90, 0, 1, 0, 1 };

/* translate (x, y, z) + rotation (angle, x, y, z) + base radius */
float leg_left_end[8] = { 0, 0, 1.25, 90, 1, 0, 0, 0.75 };
float leg_right_end[8] = { 0, 0, -1.25, 90, 1, 0, 0, 0.75 };

/* translate (x, y, z) + rotation (angle, x, y, z) + base radius*/
float arm_left_start[8] = { 6, 2, 0, 90, 0, 1, 0, 1 };
float arm_right_start[8] = { 6, 2, 0, 90, 0, 1, 0, 1 };

/* translate (x, y, z) + rotation (angle, x, y, z) + base radius */
float arm_left_end[8] = { 0, 3, 0.75, 0, 0, 0, 0, 0.75 };
float arm_right_end[8] = { 0, 3, -4.75, 0, 0, 0, 0, 0.75 };

/* translate (x, y, z) + scale (x, y, z) */
float chimney_start[6] = { 1, 4.5, 0, 1, 3, 1 };

/* translate (x, y, z) + scale (x, y, z) */
float chimney_end[6] = { 0, 4.5, 0, 1, 3, 1 };

/* translate (x, y, z) + scale (x, y, z) */
float cabin_start[10] = { 7.5, 4, 0, 5, 2, 1, 0, 0, 0, 0 };

/* translate (x, y, z)  + scale (x, y, z) + rotation (angle, x, y, z) */
float cabin_end[10] = { 0, 1.5, 0, 5, 2, 2, -90, 0, 0, 1 };




void Init()
{

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

	frame = 00;
}

void RenderScene() {

	glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
	gluLookAt(-5, 0, 5, 0, 0, 0, 0, 1, 0);

	if(rotateCamera) glRotatef( (frame / cameraRotationFaktor ) % 360, 0, 1, 0);

	//dampflock von allen winkeln bei erster camera rotation
	if (frame % (cameraRotationsPerLoop * 360 * cameraRotationFaktor) < 1 * 360 * cameraRotationFaktor ) {
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);


		//left side wheels 
		glPushMatrix();
		glTranslatef(2, 1, 0.5);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(4, 1, 0.5);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(6, 1, 0.5);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, 1, 0.5);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();


		//right side wheels 
		glPushMatrix();
		glTranslatef(2, 1, -1);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(4, 1, -1);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(6, 1, -1);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(8, 1, -1);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();



		glColor4f(0, 1, 0, 1);

		//main cylinder
		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 2, 0);
		glutSolidCylinder(1, 10, 16, 16);
		glPopMatrix();


		// chimney
		glPushMatrix();
		glTranslatef(1, 4.5, 0);
		glScalef(1, 3, 1);
		Wuerfel(1);
		glPopMatrix();

		//cabin
		glPushMatrix();
		glTranslatef(7.5, 4, 0);
		glScalef(5, 2, 1);
		Wuerfel(1);
		glPopMatrix();

	}

	//transform
	else if (
		frame % (cameraRotationsPerLoop * 360 * cameraRotationFaktor) >= 1 * 360 * cameraRotationFaktor &&
		frame % (cameraRotationsPerLoop * 360 * cameraRotationFaktor) <= (cameraRotationsPerLoop - 1) * 360 * cameraRotationFaktor) {

		float transformationProgress = (float) (frame % (cameraRotationsPerLoop * 360 * cameraRotationFaktor) - (360 * cameraRotationFaktor)) / ( (cameraRotationsPerLoop - 2) * 360 * cameraRotationFaktor);

		std::cout << "transformation: " << transformationProgress << " = (" << frame % (cameraRotationsPerLoop * 360 * cameraRotationFaktor) << " - " << (360 * cameraRotationFaktor) << " ) / " << ((cameraRotationsPerLoop - 2) * 360 * cameraRotationFaktor)  << std::endl;
		

		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		

		//-----------left side wheels--------------------- 
		//left leg wheels
		glPushMatrix();
		glTranslatef(
			(wheel_left_1_end[0] - wheel_left_1_start[0]) * transformationProgress + wheel_left_1_start[0],
			(wheel_left_1_end[1] - wheel_left_1_start[1]) * transformationProgress + wheel_left_1_start[1],
			(wheel_left_1_end[2] - wheel_left_1_start[2]) * transformationProgress + wheel_left_1_start[2]);
		glRotatef(frame % 360, 0, 0, 1);
		glRotatef(
			(wheel_left_1_end[3] - wheel_left_1_start[3]) * transformationProgress + wheel_left_1_start[3],
			(wheel_left_1_end[4] - wheel_left_1_start[4]) * transformationProgress + wheel_left_1_start[4],
			(wheel_left_1_end[5] - wheel_left_1_start[5]) * transformationProgress + wheel_left_1_start[5],
			(wheel_left_1_end[6] - wheel_left_1_start[6]) * transformationProgress + wheel_left_1_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(
			(wheel_left_2_end[0] - wheel_left_2_start[0]) * transformationProgress + wheel_left_2_start[0],
			(wheel_left_2_end[1] - wheel_left_2_start[1]) * transformationProgress + wheel_left_2_start[1],
			(wheel_left_2_end[2] - wheel_left_2_start[2]) * transformationProgress + wheel_left_2_start[2]);
		glRotatef(frame % 360, 0, 0, 1);
		glRotatef(
			(wheel_left_2_end[3] - wheel_left_2_start[3]) * transformationProgress + wheel_left_2_start[3],
			(wheel_left_2_end[4] - wheel_left_2_start[4]) * transformationProgress + wheel_left_2_start[4],
			(wheel_left_2_end[5] - wheel_left_2_start[5]) * transformationProgress + wheel_left_2_start[5],
			(wheel_left_2_end[6] - wheel_left_2_start[6]) * transformationProgress + wheel_left_2_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		//left arm wheels
		glPushMatrix();
		glTranslatef(
			(wheel_left_3_end[0] - wheel_left_3_start[0]) * transformationProgress + wheel_left_3_start[0],
			(wheel_left_3_end[1] - wheel_left_3_start[1]) * transformationProgress + wheel_left_3_start[1],
			(wheel_left_3_end[2] - wheel_left_3_start[2]) * transformationProgress + wheel_left_3_start[2]);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(
			(wheel_left_3_end[3] - wheel_left_3_start[3]) * transformationProgress + wheel_left_3_start[3],
			(wheel_left_3_end[4] - wheel_left_3_start[4]) * transformationProgress + wheel_left_3_start[4],
			(wheel_left_3_end[5] - wheel_left_3_start[5]) * transformationProgress + wheel_left_3_start[5],
			(wheel_left_3_end[6] - wheel_left_3_start[6]) * transformationProgress + wheel_left_3_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(
			(wheel_left_4_end[0] - wheel_left_4_start[0]) * transformationProgress + wheel_left_4_start[0],
			(wheel_left_4_end[1] - wheel_left_4_start[1]) * transformationProgress + wheel_left_4_start[1],
			(wheel_left_4_end[2] - wheel_left_4_start[2]) * transformationProgress + wheel_left_4_start[2]);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(
			(wheel_left_4_end[3] - wheel_left_4_start[3]) * transformationProgress + wheel_left_4_start[3],
			(wheel_left_4_end[4] - wheel_left_4_start[4]) * transformationProgress + wheel_left_4_start[4],
			(wheel_left_4_end[5] - wheel_left_4_start[5]) * transformationProgress + wheel_left_4_start[5],
			(wheel_left_4_end[6] - wheel_left_4_start[6]) * transformationProgress + wheel_left_4_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();
		//-----------left side wheels end--------------------- 


		//-----------right side wheels------------------------ 
		//right leg wheels
		glPushMatrix();
		glTranslatef(
			(wheel_right_1_end[0] - wheel_right_1_start[0]) * transformationProgress + wheel_right_1_start[0],
			(wheel_right_1_end[1] - wheel_right_1_start[1]) * transformationProgress + wheel_right_1_start[1],
			(wheel_right_1_end[2] - wheel_right_1_start[2]) * transformationProgress + wheel_right_1_start[2]);
		glRotatef(frame % 360, 0, 0, 1);
		glRotatef(
			(wheel_right_1_end[3] - wheel_right_1_start[3]) * transformationProgress + wheel_right_1_start[3],
			(wheel_right_1_end[4] - wheel_right_1_start[4]) * transformationProgress + wheel_right_1_start[4],
			(wheel_right_1_end[5] - wheel_right_1_start[5]) * transformationProgress + wheel_right_1_start[5],
			(wheel_right_1_end[6] - wheel_right_1_start[6]) * transformationProgress + wheel_right_1_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(
			(wheel_right_2_end[0] - wheel_right_2_start[0]) * transformationProgress + wheel_right_2_start[0],
			(wheel_right_2_end[1] - wheel_right_2_start[1]) * transformationProgress + wheel_right_2_start[1],
			(wheel_right_2_end[2] - wheel_right_2_start[2]) * transformationProgress + wheel_right_2_start[2]);
		glRotatef(frame % 360, 0, 0, 1);
		glRotatef(
			(wheel_right_2_end[3] - wheel_right_2_start[3]) * transformationProgress + wheel_right_2_start[3],
			(wheel_right_2_end[4] - wheel_right_2_start[4]) * transformationProgress + wheel_right_2_start[4],
			(wheel_right_2_end[5] - wheel_right_2_start[5]) * transformationProgress + wheel_right_2_start[5],
			(wheel_right_2_end[6] - wheel_right_2_start[6]) * transformationProgress + wheel_right_2_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		//right arm wheels
		glPushMatrix();
		glTranslatef(
			(wheel_right_3_end[0] - wheel_right_3_start[0]) * transformationProgress + wheel_right_3_start[0],
			(wheel_right_3_end[1] - wheel_right_3_start[1]) * transformationProgress + wheel_right_3_start[1],
			(wheel_right_3_end[2] - wheel_right_3_start[2]) * transformationProgress + wheel_right_3_start[2]);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(
			(wheel_right_3_end[3] - wheel_right_3_start[3]) * transformationProgress + wheel_right_3_start[3],
			(wheel_right_3_end[4] - wheel_right_3_start[4]) * transformationProgress + wheel_right_3_start[4],
			(wheel_right_3_end[5] - wheel_right_3_start[5]) * transformationProgress + wheel_right_3_start[5],
			(wheel_right_3_end[6] - wheel_right_3_start[6]) * transformationProgress + wheel_right_3_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(
			(wheel_right_4_end[0] - wheel_right_4_start[0]) * transformationProgress + wheel_right_4_start[0],
			(wheel_right_4_end[1] - wheel_right_4_start[1]) * transformationProgress + wheel_right_4_start[1],
			(wheel_right_4_end[2] - wheel_right_4_start[2]) * transformationProgress + wheel_right_4_start[2]);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(
			(wheel_right_4_end[3] - wheel_right_4_start[3]) * transformationProgress + wheel_right_4_start[3],
			(wheel_right_4_end[4] - wheel_right_4_start[4]) * transformationProgress + wheel_right_4_start[4],
			(wheel_right_4_end[5] - wheel_right_4_start[5]) * transformationProgress + wheel_right_4_start[5],
			(wheel_right_4_end[6] - wheel_right_4_start[6]) * transformationProgress + wheel_right_4_start[6]);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();
		//-----------right side wheels end--------------------


		glColor4f(0, 1, 0, 1);


		//------------legs------------------
		//left leg
		glPushMatrix();
		glTranslatef(
			(leg_left_end[0] - leg_left_start[0]) * transformationProgress + leg_left_start[0],
			(leg_left_end[1] - leg_left_start[1]) * transformationProgress + leg_left_start[1],
			(leg_left_end[2] - leg_left_start[2]) * transformationProgress + leg_left_start[2]);
		glRotatef(
			(leg_left_end[3] - leg_left_start[3]) * transformationProgress + leg_left_start[3],
			(leg_left_end[4] - leg_left_start[4]) * transformationProgress + leg_left_start[4], 
			(leg_left_end[5] - leg_left_start[5]) * transformationProgress + leg_left_start[5],
			(leg_left_end[6] - leg_left_start[6]) * transformationProgress + leg_left_start[6]);
		glutSolidCylinder(
			(leg_left_end[7] - leg_left_start[7]) * transformationProgress + leg_left_start[7], 6, 16, 16);
		glPopMatrix();

		//right leg
		glPushMatrix();
		glTranslatef(
			(leg_right_end[0] - leg_right_start[0]) * transformationProgress + leg_right_start[0],
			(leg_right_end[1] - leg_right_start[1]) * transformationProgress + leg_right_start[1],
			(leg_right_end[2] - leg_right_start[2]) * transformationProgress + leg_right_start[2]);
		glRotatef(
			(leg_right_end[3] - leg_right_start[3]) * transformationProgress + leg_right_start[3],
			(leg_right_end[4] - leg_right_start[4]) * transformationProgress + leg_right_start[4],
			(leg_right_end[5] - leg_right_start[5]) * transformationProgress + leg_right_start[5],
			(leg_right_end[6] - leg_right_start[6]) * transformationProgress + leg_right_start[6]);
		glutSolidCylinder(
			(leg_right_end[7] - leg_right_start[7]) * transformationProgress + leg_right_start[7], 6, 16, 16);
		glPopMatrix();
		//------------legs end------------------


		//------------arms----------------------
		//left arm
		glPushMatrix();
		glTranslatef(
			(arm_left_end[0] - arm_left_start[0]) * transformationProgress + arm_left_start[0],
			(arm_left_end[1] - arm_left_start[1]) * transformationProgress + arm_left_start[1],
			(arm_left_end[2] - arm_left_start[2]) * transformationProgress + arm_left_start[2]);
		glRotatef(
			(arm_left_end[3] - arm_left_start[3]) * transformationProgress + arm_left_start[3],
			(arm_left_end[4] - arm_left_start[4]) * transformationProgress + arm_left_start[4],
			(arm_left_end[5] - arm_left_start[5]) * transformationProgress + arm_left_start[5],
			(arm_left_end[6] - arm_left_start[6]) * transformationProgress + arm_left_start[6]);
		glutSolidCylinder(
			(arm_left_end[7] - arm_left_start[7]) * transformationProgress + arm_left_start[7], 4, 16, 16);
		glPopMatrix();

		//right arm
		glPushMatrix();
		glTranslatef(
			(arm_right_end[0] - arm_right_start[0]) * transformationProgress + arm_right_start[0],
			(arm_right_end[1] - arm_right_start[1]) * transformationProgress + arm_right_start[1],
			(arm_right_end[2] - arm_right_start[2]) * transformationProgress + arm_right_start[2]);
		glRotatef(
			(arm_right_end[3] - arm_right_start[3]) * transformationProgress + arm_right_start[3],
			(arm_right_end[4] - arm_right_start[4]) * transformationProgress + arm_right_start[4],
			(arm_right_end[5] - arm_right_start[5]) * transformationProgress + arm_right_start[5],
			(arm_right_end[6] - arm_right_start[6]) * transformationProgress + arm_right_start[6]);
		glutSolidCylinder(
			(arm_right_end[7] - arm_right_start[7]) * transformationProgress + arm_right_start[7], 4, 16, 16);
		glPopMatrix();
		//------------arms end------------------

		// chimney
		glPushMatrix();
		glTranslatef(
			(chimney_end[0] - chimney_start[0]) * transformationProgress + chimney_start[0],
			(chimney_end[1] - chimney_start[1]) * transformationProgress + chimney_start[1],
			(chimney_end[2] - chimney_start[2]) * transformationProgress + chimney_start[2]);
		glScalef(
			(chimney_end[3] - chimney_start[3]) * transformationProgress + chimney_start[3],
			(chimney_end[4] - chimney_start[4]) * transformationProgress + chimney_start[4],
			(chimney_end[5] - chimney_start[5]) * transformationProgress + chimney_start[5]);
		Wuerfel(1);
		glPopMatrix();

		//cabin
		glPushMatrix();
		glTranslatef(
			(cabin_end[0] - cabin_start[0]) * transformationProgress + cabin_start[0],
			(cabin_end[1] - cabin_start[1]) * transformationProgress + cabin_start[1],
			(cabin_end[2] - cabin_start[2]) * transformationProgress + cabin_start[2]);
		glRotatef(
			(cabin_end[6] - cabin_start[6]) * transformationProgress + cabin_start[6],
			(cabin_end[7] - cabin_start[7]) * transformationProgress + cabin_start[7],
			(cabin_end[8] - cabin_start[8]) * transformationProgress + cabin_start[8],
			(cabin_end[9] - cabin_start[9]) * transformationProgress + cabin_start[9]);
		glScalef(
			(cabin_end[3] - cabin_start[3]) * transformationProgress + cabin_start[3],
			(cabin_end[4] - cabin_start[4]) * transformationProgress + cabin_start[4],
			(cabin_end[5] - cabin_start[5]) * transformationProgress + cabin_start[5]);
		Wuerfel(1);
		glPopMatrix();

	}




	//roboter von allen winkeln
	else if (frame % (cameraRotationsPerLoop * 360 * cameraRotationFaktor) > (cameraRotationsPerLoop - 1) * 360 * cameraRotationFaktor) {
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f);


		//-----------left side wheels--------------------- 
		//left leg wheels
		glPushMatrix();
		glTranslatef(0, -4, 1.5);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -2, 1.5);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		//left arm wheels
		glPushMatrix();
		glTranslatef(0, 4, 2);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 4, 4);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();
		//-----------left side wheels end--------------------- 


		//-----------right side wheels------------------------ 
		//right leg wheels
		glPushMatrix();
		glTranslatef(0, -4, -2);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -2, -2);
		glRotatef(frame % 360, 0, 0, 1);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		//right arm wheels
		glPushMatrix();
		glTranslatef(0, 4, -2);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 4, -4);
		glRotatef(frame % 360, 0, 1, 0);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(1, 0.5, 16, 16);
		glPopMatrix();
		//-----------right side wheels end--------------------


		glColor4f(0, 1, 0, 1);


		//------------legs------------------
		//left leg
		glPushMatrix();
		glTranslatef(0, 0, 1.25);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(0.75, 6, 16, 16);
		glPopMatrix();

		//right leg
		glPushMatrix();
		glTranslatef(0, 0, -1.25);
		glRotatef(90, 1, 0, 0);
		glutSolidCylinder(0.75, 6, 16, 16);
		glPopMatrix();
		//------------legs end------------------


		//------------arms----------------------
		//left arm
		glPushMatrix();
		glTranslatef(0, 3, 0.75);
		//glRotatef(90, 1, 0, 0);
		glutSolidCylinder(0.75, 4, 16, 16);
		glPopMatrix();

		//right arm
		glPushMatrix();
		glTranslatef(0, 3, -4.75);
		//glRotatef(90, 1, 0, 0);
		glutSolidCylinder(0.75, 4, 16, 16);
		glPopMatrix();
		//------------arms end------------------

		// chimney
		glPushMatrix();
		glTranslatef(0, 4.5, 0);
		glScalef(1, 3, 1);
		Wuerfel(1);
		glPopMatrix();

		//cabin
		glPushMatrix();
		glTranslatef(0, 1.5, 0);
		glRotatef(-90, 0, 0, 1);
		glScalef(5, 2, 2);
		Wuerfel(1);
		glPopMatrix();

	}




    glutSwapBuffers();

}

void Reshape(int width,int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    glOrtho(-10, 10, -10, 10, -15, 15);
    //glFrustum(-5,5,-5,5,0,4);
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)
{
	frame = value;
    std::cout << "value=" << value << std::endl;
    glutPostRedisplay();
    int wait_msec = 10;
    glutTimerFunc(wait_msec, Animate, ++value);
}

int main(int argc, char **argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize( 600, 600 );
    glutCreateWindow( "ChooChoo" );
    glutDisplayFunc( RenderScene );
    glutReshapeFunc( Reshape );
    glutTimerFunc( 10, Animate, 0);
    Init();
    glutMainLoop();

    return 0;
}
