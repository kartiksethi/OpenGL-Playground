//
// Created by anikethjr on 6/11/17.
//
#ifndef SCENERY_CAMERA_H
#define SCENERY_CAMERA_H

#include <bits/stdc++.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

#define PI 3.14159265

using namespace glm;
using namespace std;

class Camera
{
    private:
        dvec3 position, target;
        dvec3 up, u, v, n;
        /**
         * Sets up OpenGL's modelview matrix
         */
        void setModelViewMatrix();

    public:
        /**
         * Constructor which initializes the camera's position and properties with default values
         */
        Camera();
        /**
         * Sets up the position of the camera
         * @param position Position of the eye
         * @param target Point to look at from the eye
         * @param up The look-up vector
         */
        void setupPosition(dvec3 position, dvec3 target, dvec3 up);
        /**
         * Sets up various camera properties
         * @param viewAngle Viewing angle
         * @param aspect Aspect ratio
         * @param nearDist near distance of the camera
         * @param farDist far distance of the camera
         */
        void setupProperties(double viewAngle, double aspect, double nearDist, double farDist);
        /**
         * Rotates the camera around the roll axis by the specified angle
         * @param angle angle to rotate by
         */
        void roll(double angle);
        /**
         * Rotates the camera around the pitch axis by the specified angle
         * @param angle angle to rotate by
         */
        void pitch(double angle);
        /**
         * Rotates the camera around the yaw axis by the specified angle
         * @param angle angle to rotate by
         */
        void yaw(double angle);
        /**
         * Moves the camera by adding the given displacement
         * @param displacement Displacement vector which specifies additions to the camera position
         */
        void move(dvec3 displacement);
};

#endif //SCENERY_CAMERA_H