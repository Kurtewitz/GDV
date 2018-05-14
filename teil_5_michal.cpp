
#include <iostream>
#include <GL/freeglut.h>
#include "Zylinder.h"
#include "Wuerfel.h"

int frame;
int cameraRotationFaktor = 2;


void Init()
{

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);

	frame = 0;
}

void RenderScene() {

	glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(1, 1, 1, 1);
	gluLookAt(5, 0, 0, 0, 0, 0, 0, 1, 0);

	glRotatef( (frame / cameraRotationFaktor ) % 360, 0, 1, 0);

	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);


	//left side wheels 
	glPushMatrix();
	glTranslatef(2, 1, 0.5);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, 1, 0.5);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 1, 0.5);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 1, 0.5);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();


	//right side wheels 
	glPushMatrix();
	glTranslatef(2, 1, -1);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4, 1, -1);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 1, -1);
	glutSolidCylinder(1, 0.5, 16, 16);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(8, 1, -1);
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

    glutSwapBuffers();

}

void Reshape(int width,int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    glOrtho(-10, 10, -10, 10, -20, 20);
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
