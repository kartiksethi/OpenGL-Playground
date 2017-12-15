#ifndef SCENERY_PROPS_H
#define SCENERY_PROPS_H

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>

using namespace glm;
using namespace std;

/**
 * Draws a solid cylinder of specified dimensions at origin
 * @param BASE_INNER inner radius of base
 * @param TOP_INNER inner radius of top
 * @param BASE_OUTER outer radius of base
 * @param TOP_OUTER outer radius of top
 * @param HEIGHT height of the cylinder
 * @param SLICES number of slides to be broken into
 * @param STACKS number of stacks to be broken into
 */
void glutSolidCylinder(double BASE_INNER,double TOP_INNER,double BASE_OUTER,double TOP_OUTER,double HEIGHT,int SLICES,int STACKS)
{
    GLUquadric* cylinder = gluNewQuadric();
    GLUquadric* base = gluNewQuadric();
    GLUquadric* top = gluNewQuadric();
    gluCylinder(cylinder, BASE_OUTER, TOP_OUTER, HEIGHT, SLICES, STACKS);
    glRotated(180, 1, 0, 0);
    gluDisk(base, BASE_INNER, BASE_OUTER, SLICES, 1);
    glRotated(180, 1, 0, 0);
    glTranslated(0.0, 0.0, HEIGHT);
    gluDisk(top, TOP_INNER, TOP_OUTER, SLICES, 1);
    glTranslated(0.0, 0.0, -HEIGHT);
}

/**
 * Class for creating the surrounding walls of the park
 */
class Wall
{
public:
    /**
     * Function to create the wall
     */
    void create() {
        // front wall
        glColor3d(145/255.0, 112/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(-3.5, 0.001, 4.96);
        glScaled(3,0.75,0.09);
        glutSolidCube(1);
        glPopMatrix();

        // front wall
        glColor3d(145/255.0, 112/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(3.5, 0.001, 4.96);
        glScaled(3,0.75,0.09);
        glutSolidCube(1);
        glPopMatrix();


        // back wall
        glColor3d(145/255.0, 112/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0, 0.001, -4.96);
        glScaled(10,0.75,0.09);
        glutSolidCube(1);
        glPopMatrix();


        // right wall
        glColor3d(145/255.0, 112/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(4.96, 0.001, 0);
        glScaled(0.09,0.75,10);
        glutSolidCube(1);
        glPopMatrix();


        // left wall
        glColor3d(145/255.0, 112/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(-4.96, 0.001, 0);
        glScaled(0.09,0.75,10);
        glutSolidCube(1);
        glPopMatrix();

        line();
    }


    /**
     * Function to create the borders of the wall
     */
    void line() {
        glColor3d(0,0,0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // front wall
        glPushMatrix();
        glTranslated(-3.5, 0.001, 4.96);
        glScaled(3,0.75,0.09);
        glutSolidCube(1);
        glPopMatrix();

        // front wall
        glPushMatrix();
        glTranslated(3.5, 0.001, 4.96);
        glScaled(3,0.75,0.09);
        glutSolidCube(1);
        glPopMatrix();

        // back wall
        glPushMatrix();
        glTranslated(0, 0.001, -4.96);
        glScaled(10,0.75,0.09);
        glutSolidCube(1);
        glPopMatrix();

        // right wall
        glPushMatrix();
        glTranslated(4.96, 0.001, 0);
        glScaled(0.09,0.75,10);
        glutSolidCube(1);
        glPopMatrix();

        // left wall
        glPushMatrix();
        glTranslated(-4.96, 0.001, 0);
        glScaled(0.09,0.75,10);
        glutSolidCube(1);
        glPopMatrix();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

};

/**
 * Class which is used to draw a swing
 */
class Swing {
public:
    /**
     * Constructor which draws the various shapes required to make the swing
     */
    Swing() {
        solid();
        border();
    }

    /**
     * Function which draws the solids of the swings
     */
    void solid() {
        glColor3d(255.0 / 255, 0, 0);
        //Left bars
        glPushMatrix();
        glTranslated(0, 0, 0);
        glRotated(-20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.17, 0, 0);
        glRotated(20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        //Right bars
        glPushMatrix();
        glTranslated(0, 0, -0.75);
        glRotated(-20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.17, 0, -0.75);
        glRotated(20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        //Top rod
        glPushMatrix();
        glTranslated(0.09, 0.23, -0.375);
        glScaled(0.01, 0.01, 0.5);
        glutSolidCube(1.5);
        glPopMatrix();

        //Chains
        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.25);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.5);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.65);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        //Seats
        glColor3d(255.0 / 255.0, 255.0 / 255.0, 17.0 / 255.0);
        glPushMatrix();
        glTranslated(0.09, -0.14, -0.575);
        glScaled(0.25, 0.01, 0.33);
        glutSolidCube(0.5);
        glPopMatrix();

        glColor3d(255.0 / 255.0, 255.0 / 255.0, 17.0 / 255.0);
        glPushMatrix();
        glTranslated(0.09, -0.14, -0.175);
        glScaled(0.25, 0.01, 0.33);
        glutSolidCube(0.5);
        glPopMatrix();
    }

    /**
     * Function which draws the borders of the shapes which constitute the swing
     */
    void border()
    {
        glColor3d(0,0,0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        //Left bars
        glPushMatrix();
        glTranslated(0, 0, 0);
        glRotated(-20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.17, 0, 0);
        glRotated(20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        //Right bars
        glPushMatrix();
        glTranslated(0, 0, -0.75);
        glRotated(-20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.17, 0, -0.75);
        glRotated(20, 0, 0, 1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        //Top rod
        glPushMatrix();
        glTranslated(0.09, 0.23, -0.375);
        glScaled(0.01, 0.01, 0.5);
        glutSolidCube(1.5);
        glPopMatrix();

        //Chains
        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.1);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.25);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.5);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        glColor3d(0, 0, 0);
        glPushMatrix();
        glTranslated(0.09, 0.05, -0.65);
        glScaled(0.01, 0.5, 0.01);
        glutSolidCube(0.75);
        glPopMatrix();

        //Seats
        glPushMatrix();
        glTranslated(0.09, -0.14, -0.575);
        glScaled(0.25, 0.01, 0.33);
        glutSolidCube(0.5);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.09, -0.14, -0.175);
        glScaled(0.25, 0.01, 0.33);
        glutSolidCube(0.5);
        glPopMatrix();
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
};

/**
 * Class which is used to draw a merry-go-round
 */
class MerryGoRound
{
public:
    /**
     * Constructor which draws the various shapes required to make the merry-go-round
     */
    MerryGoRound() {
        solid();
        border();
    }
    /**
     * Function which draws the solids of the merry-go-round
     */
    void solid()
    {
        //Base
        glColor3d(86.0/255.0, 49.0/255.0, 168.0/255.0);
        glPushMatrix();
        glRotated(90,1,0,0);
        glutSolidCylinder(0,0,0.5,0.5,0.1,32,32);
        glPopMatrix();
        glPushMatrix();
        glColor3d(255.0/255.0, 255.0/255.0, 255.0/255.0);
        glRotated(90,1,0,0);
        glutSolidCylinder(0.5,0.5,0.55,0.55,0.01,32,32);
        glPopMatrix();

        //Bars
        glColor3d(0.0/255.0, 0.0/255.0, 0.0/255.0);
        //Central bar
        glPushMatrix();
        glTranslated(0,0.14,0);
        glScaled(0.01,0.3,0.01);
        glutSolidCube(1);
        glPopMatrix();
        //Horizontal and vertical bars
        for(int i=0;i<6;i++)
        {
            glColor3d(111.0/255.0, 124.0/255.0, 122.0/255.0);
            glPushMatrix();
            glRotated(i*60,0,1,0);
            glTranslated(0.2,0.285,0);
            glScaled(0.4,0.01,0.01);
            glutSolidCube(1);
            glPopMatrix();
            glPushMatrix();
            glRotated(i*60,0,1,0);
            glTranslated(0.4,0.14,0);
            glScaled(0.01,0.3,0.01);
            glutSolidCube(1);
            glPopMatrix();
        }
    }

    /**
     * Function which draws the borders of the shapes which constitute the merry-go-round
     */
    void border()
    {
        glColor3d(0,0,0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        //Base
        glPushMatrix();
        glRotated(90,1,0,0);
        glutSolidCylinder(0,0,0.5,0.5,0.1,32,32);
        glPopMatrix();
        glPushMatrix();
        glRotated(90,1,0,0);
        glutSolidCylinder(0.5,0.5,0.55,0.55,0.01,32,32);
        glPopMatrix();

        //Bars
        //Central bar
        glPushMatrix();
        glTranslated(0,0.14,0);
        glScaled(0.01,0.3,0.01);
        glutSolidCube(1);
        glPopMatrix();
        //Horizontal and vertical bars
        for(int i=0;i<6;i++)
        {
            glPushMatrix();
            glRotated(i*60,0,1,0);
            glTranslated(0.2,0.285,0);
            glScaled(0.4,0.01,0.01);
            glutSolidCube(1);
            glPopMatrix();
            glPushMatrix();
            glRotated(i*60,0,1,0);
            glTranslated(0.4,0.14,0);
            glScaled(0.01,0.3,0.01);
            glutSolidCube(1);
            glPopMatrix();
        }
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
};

/**
 * Class which creates the ground
 */
class Ground
{
public:
    /**
     * Constructor which draws the ground
     */
    Ground()
    {
        glColor3d(0.0/255.0,200/255.0,0.0/255.0);
        glPushMatrix();
        glTranslated(0,-0.87,0);
        glScaled(2,0.2,2);
        glutSolidCube(5);
        glPopMatrix();

        glColor3d(0,0,0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glPushMatrix();
        glTranslated(0,-0.87,0);
        glScaled(2,0.2,2);
        glutSolidCube(5);
        glPopMatrix();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    }
};

/**
 * Class for creating a slide
 */
class Slide
{
public:

    /**
     * Function to create the slide
     * @param inclination defines the inclination of the slide
     */
    void create(double inclination) {
        base(inclination);
        stairs();
        bars();
        frame();
        line(inclination);

    }

    /**
     * Function that defines the base of the slide
     * @param inclination defines the inclination of the slide
     */
    void base(double inclination) {
        // right edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0, 0, 0);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right base edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(-0.707 + 0.246, -0.351, 0);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right top edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.46, 0.35, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // slide part
        glColor3d(5.0 / 255, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0, 0, -0.1);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1, 0.001, -0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide base part
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(-0.707 + 0.246, -0.351, -0.1);
        glScaled(0.23, 0.001, -0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide top part
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.46, 0.35, -0.1);
        glScaled(0.23, 0.001, -0.2);
        glutSolidCube(1);
        glPopMatrix();

        // left edge
        glColor3d(255 / 255.0, 0, 0);
        glPushMatrix();
        glTranslated(0, 0, -0.2);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left base edge
        glColor3d(255 / 255.0, 0, 0);
        glPushMatrix();
        glTranslated(-0.707 + 0.246, -0.351, -0.2);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left top edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.46, 0.35, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function that defines the stairs/steps of the slide
     */
    void stairs() {
        // right stairs edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.56, -0.01, 0);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left stairs edge
        glColor3d(255.0 / 255, 0, 0);
        glPushMatrix();
        glTranslated(0.56, -0.01, -0.2);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function that defines the bars for the stairs/steps of the slide
     */
    void bars() {
        // bars
        // bar 1
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, 0.18, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // bar 2
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, 0.03, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // bar 3
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, -0.12, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        // bar 4
        glColor3d(5.0 / 255.0, 47.0 / 255, 51.0 / 255);
        glPushMatrix();
        glTranslated(0.56, -0.27, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function that defines the frame at the top of the slide
     */
    void frame() {

        // frame
        // frame right side
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.36, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.41, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.51, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.56, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame left side
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.36, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.41, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.51, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.56, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top
        // frame top right
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.55, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top left
        // frame top right
        glColor3d(58 / 255.0, 110 / 255.0, 193 / 255.0);
        glPushMatrix();
        glTranslated(0.46, 0.55, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function to create the borders of the slide
     * @param inclination defines the inclination of the slide
     */
    void line(double inclination) {
        glColor3d(0,0,0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // right edge
        glPushMatrix();
        glTranslated(0,0,0);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1,0.03,0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right base edge
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, 0);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right top edge
        glPushMatrix();
        glTranslated(0.46, 0.35, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // slide part
        glPushMatrix();
        glTranslated(0, 0, -0.1);
        glRotatef(inclination, 0, 0, 1);
        glScaled(0.2,0.001,-0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide base part
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, -0.1);
        glScaled(0.23,0.001,-0.2);
        glutSolidCube(1);
        glPopMatrix();

        // slide base part
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, -0.1);
        glScaled(0.23,0.001,-0.2);
        glutSolidCube(1);
        glPopMatrix();

        // left edge
        glPushMatrix();
        glTranslated(0,0,-0.2);
        glRotatef(inclination, 0, 0, 1);
        glScaled(1,0.03,0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left base edge
        glPushMatrix();
        glTranslated(-0.707+0.246, -0.351, -0.2);
        glScaled(0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left top edge
        glPushMatrix();
        glTranslated(0.46, 0.35, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // right stairs edge
        glPushMatrix();
        glTranslated(0.56, -0.01, 0);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // left stairs edge
        glPushMatrix();
        glTranslated(0.56, -0.01, -0.2);
        glScaled(0.03, 0.71, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // bars
        glPushMatrix();
        glTranslated(0.56, 0.18, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, 0.03, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, -0.12, -0.1);
        glScaled(0.03, 0.03, 0.2);
        glutSolidCube(1);
        glPopMatrix();


        // frame
        // frame right side
        glPushMatrix();
        glTranslated(0.36, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.41, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.46, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.51, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, 0.464, 0);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame left side
        glPushMatrix();
        glTranslated(0.36, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.41, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.46, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.51, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.56, 0.464, -0.2);
        glScaled(-0.015, 0.2, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top
        // frame top right
        glPushMatrix();
        glTranslated(0.46, 0.55, 0);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        // frame top left
        // frame top right
        glPushMatrix();
        glTranslated(0.46, 0.55, -0.2);
        glScaled(-0.23, 0.03, 0.01);
        glutSolidCube(1);
        glPopMatrix();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
};

/**
 * Class for creating a monkey bar
 */
class MonkeyBar
{
public:

    /**
     * Function to create the monkey bar
     */
    void create() {
        frame();
        bars();
        line();
    }

    /**
     * Function that defines the frame of the monkey bar
     */
    void frame() {
        // frame
        // frame right edge
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left edge
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0, 0, -0.35);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame right legs
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(-0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left legs
        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(-0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(9/255.0, 71/255.0, 42/255.0);
        glPushMatrix();
        glTranslated(0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function to add the bars in the frame
     */
    void bars() {
        // bars
        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(-0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(-0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(-0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glColor3d(53/255.0, 64/255.0, 86/255.0);
        glPushMatrix();
        glTranslated(0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();
    }

    /**
     * Function to create the borders of the monkey bar
     */
    void line() {
        glColor3d(0,0,0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // frame
        // frame right edge
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left edge
        glPushMatrix();
        glTranslated(0, 0, -0.35);
        glScaled(1, 0.03, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame right legs
        glPushMatrix();
        glTranslated(-0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.485, -0.287, 0);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // frame left legs
        glPushMatrix();
        glTranslated(-0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.485, -0.287, -0.35);
        glScaled(0.03, 0.6, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // bars
        glPushMatrix();
        glTranslated(0, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.15, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.3, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(-0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.45, 0, -0.2);
        glScaled(0.03, 0.03, -0.35);
        glutSolidCube(1);
        glPopMatrix();


        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    }

};

/**
 * Class for creating a wooden bench
 */
class Bench
{
public:
    /**
     * Function to create the wooden bench
     */
    void create() {
        base();
        line();
    }

    /**
     * Function that defines the base and the seat of the bench
     */
    void base() {
        // base right legs
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.5, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // right joiner
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.25, 0.175, 0);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // base left legs
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.5, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // left joiner
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0.25, 0.175, -1);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // seat
        glColor3d(124/255.0, 90/255.0, 4/255.0);
        glPushMatrix();
        glTranslated(0.05, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.12, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.19, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.26, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.33, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.4, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.47, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

    }

    /**
     * Function to create the borders of the bench
     */
    void line() {
        glColor3d(0,0,0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // base right legs
        glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glPushMatrix();
        glTranslated(0.5, 0, 0);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // right joiner
        glPushMatrix();
        glTranslated(0.25, 0.175, 0);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // base left legs
        glPushMatrix();
        glTranslated(0, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();


        glPushMatrix();
        glTranslated(0.5, 0, -1);
        glScaled(0.05, 0.3, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // left joiner
        glPushMatrix();
        glTranslated(0.25, 0.175, -1);
        glScaled(0.55, 0.05, 0.05);
        glutSolidCube(1);
        glPopMatrix();

        // seat
        glPushMatrix();
        glTranslated(0.05, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.12, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.19, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.26, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.33, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.4, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPushMatrix();
        glTranslated(0.47, 0.225, -0.5);
        glScaled(0.05, 0.05, -1.3);
        glutSolidCube(1);
        glPopMatrix();

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

};

/**
 * Class to draw the path within the park
 */
class Path
{
public:
    void create()
    {
        // center cylinder
        glColor3d(45/255.0, 45/255.0, 43/255.0);
        glPushMatrix();
        glTranslated(0, -0.28, 0);
        glScaled(0.05, 0.3, 0.05);
        glRotated(90,1,0,0);
        glutSolidCylinder(0,0,30,30,0.3,32,32);
        glPopMatrix();

        //side lanes
        glPushMatrix();
        glTranslated(0, -0.34, 0);
        glScaled(10, 0.1, 1.3);
        glutSolidCube(1);
        glPopMatrix();

        //front back lanes
        glPushMatrix();
        glTranslated(0, -0.34, 0);
        glScaled(1.3, 0.1, 10);
        glutSolidCube(1);
        glPopMatrix();
        line();

    }

    void line()
    {
        // center cylinder
        glPushMatrix();
        glTranslated(0, -0.28, 0);
        glScaled(0.05, 0.3, 0.05);
        glRotated(90,1,0,0);
        glutSolidCylinder(0,0,30,30,0.1,32,32);
        glPopMatrix();

        //side lanes
        glPushMatrix();
        glTranslated(0, -0.34, 0);
        glScaled(10, 0.1, 1.3);
        glutSolidCube(1);
        glPopMatrix();


        //front back lanes
        glPushMatrix();
        glTranslated(0, -0.34, 0);
        glScaled(1.3, 0.1, 10);
        glutSolidCube(1);
        glPopMatrix();



    }
};

#endif //SCENERY_PROPS_H