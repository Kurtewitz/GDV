//
// Created by dominik on 01.05.18.
//

#include <iostream>
#include "Zylinder.h"


void Zylinder(float radius, float hoehe, float alpha){

        for (int punkt = 0; punkt <= alpha; punkt++) {
            double tetha = punkt * 2 * M_PI;
            double tetha45 = punkt * M_PI_4;
            double tetha90 = punkt * M_PI_2;
            double tetha135 = punkt * (3 * M_PI_4);
            double tetha180 = punkt * M_PI;
            double tetha270 = punkt * (3 * M_PI_2);
            glBegin(GL_POLYGON);

            glVertex3d(0,0,0);
            glVertex3d(0,0,hoehe);
            glVertex3d(radius * cos(tetha), radius * sin(tetha), 0);
            glVertex3d(radius * cos(tetha), radius * sin(tetha), hoehe);
            glVertex3d(radius * cos(tetha45), radius * sin(tetha45), 0);
            glVertex3d(radius * cos(tetha45), radius * sin(tetha45), hoehe);
            glVertex3d(radius * cos(tetha90), radius * sin(tetha90), 0);
            glVertex3d(radius * cos(tetha90), radius * sin(tetha90), hoehe);
            glVertex3d(radius * cos(tetha135), radius * sin(tetha135), 0);
            glVertex3d(radius * cos(tetha135), radius * sin(tetha135), hoehe);
            glVertex3d(radius * cos(tetha180), radius * sin(tetha180), 0);
            glVertex3d(radius * cos(tetha180), radius * sin(tetha180), hoehe);
            glVertex3d(radius * cos(tetha270), radius * sin(tetha270), hoehe);
            glVertex3d(radius * cos(tetha270), radius * sin(tetha270), 0);

            glEnd();

        }

}