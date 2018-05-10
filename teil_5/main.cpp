
#include <iostream>
#include <GL/freeglut.h>
#include "Zylinder.h"
#include "Wuerfel.h"

void Init()
{

    glEnable(GL_DEPTH_TEST);
    glClearDepth(1.0);


}

void RenderScene() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    gluLookAt(5,0,0,0,0,0,0,1,0);
    glClearColor(1,1,1,0);

    glColor4f(0,0,0,0);
    Zylinder(1.5,7,100);
    glPushMatrix();

    glPopMatrix();
    glColor4f(0,0,0,0);
    glTranslatef(0,1,-2.5);
    Wuerfel(5);
    glPushMatrix();

    glPopMatrix();
    glColor4f(0,0,0,0);
    glRotatef(90,1,0,0);
    glTranslatef(0,7,-2);
    Zylinder(0.25,1.5,100);
    glPushMatrix();

    glColor4f(0.5,0.5,0.5,0);
    glRotatef(90,0,1,0);//aeußerster linker Zylider
    glTranslatef(-5.5,1.5,0);
    Zylinder(1,5,100);

    glTranslatef(0,-2,0);
    Zylinder(1,5,100);

    glTranslatef(0,-4,0);
    Zylinder(1,5,100);

    glTranslatef(0,-2,0);
    Zylinder(1,5,100);

    glTranslatef(0,-2,0);
    Zylinder(1,5,100);

    glPopMatrix();

    glutSwapBuffers();

}

void Reshape(int width,int height)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0,0,width,height);
    glOrtho(-10, 10, -10, 10, 0, 10);
    //glFrustum(-5,5,-5,5,0,4);
    glMatrixMode(GL_MODELVIEW);
}

void Animate (int value)
{

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
