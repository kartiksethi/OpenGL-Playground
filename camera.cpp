//
// Created by anikethjr on 7/11/17.
//
#include "camera.h"

Camera::Camera()
{
    setupPosition(dvec3(0.0,0.0,5.0),dvec3(0.0,0.0,0.0),dvec3(0,1,0));
    setupProperties(45.0f,928.00/696.00,0.1,50.0);
}

void Camera :: setupProperties(double viewAngle, double aspect, double nearDist, double farDist)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(viewAngle, aspect, nearDist, farDist);
    glMatrixMode(GL_MODELVIEW);
}

void Camera :: setModelViewMatrix()
{
    double m[16];
    m[0]=u.x;
    m[1]=v.x;
    m[2]=n.x;
    m[3]=0;
    m[4]=u.y;
    m[5]=v.y;
    m[6]=n.y;
    m[7]=0;
    m[8]=u.z;
    m[9]=v.z;
    m[10]=n.z;
    m[11]=0;
    m[12]=-dot(position,u);
    m[13]=-dot(position,v);
    m[14]=-dot(position,n);
    m[15]=1.0;
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(m);
}

void Camera::setupPosition(dvec3 position, dvec3 target, dvec3 up)
{
    this->position = position;
    this->target = target;
    this->up = up;
    n = normalize(position-target);
    u = normalize(cross(up,n));
    v = normalize(cross(n,u));
    setModelViewMatrix();
}

void Camera:: roll(double angle)
{
    dmat3 roll_matrix(0.0f);
    roll_matrix[0][0] = cos(radians(angle));
    roll_matrix[0][1] = -sin(radians(angle));
    roll_matrix[1][0] = sin(radians(angle));
    roll_matrix[1][1] = cos(radians(angle));

    dmat3 original_matrix(0.0f);
    original_matrix[0] = u;
    original_matrix[1] = v;

    dmat3 transformed_matrix = original_matrix*roll_matrix;
    u = transformed_matrix[0];
    v = transformed_matrix[1];

    setModelViewMatrix();
}

void Camera::move(dvec3 displacement)
{
    dmat3x3 mat;
    mat[0][0] = u.x;
    mat[0][1] = u.y;
    mat[0][2] = u.z;

    mat[1][0] = v.x;
    mat[1][1] = v.y;
    mat[1][2] = v.z;

    mat[2][0] = n.x;
    mat[2][1] = n.y;
    mat[2][2] = n.z;

    dvec3 change = mat*displacement;
    position = position + change;
    target = target + change;
    setModelViewMatrix();
}

void Camera:: yaw(double angle)
{
    dmat3 yaw_matrix(0.0f);
    yaw_matrix[0][0] = cos(radians(angle));
    yaw_matrix[0][1] = sin(radians(angle));
    yaw_matrix[1][0] = -sin(radians(angle));
    yaw_matrix[1][1] = cos(radians(angle));

    dmat3 original_matrix(0.0f);
    original_matrix[0] = u;
    original_matrix[1] = n;

    dmat3 transformed_matrix = original_matrix*yaw_matrix;
    u = transformed_matrix[0];
    n = transformed_matrix[1];

    setModelViewMatrix();
}

void Camera:: pitch(double angle)
{
    dmat3 pitch_matrix(0.0f);
    pitch_matrix[0][0] = cos(radians(angle));
    pitch_matrix[0][1] = -sin(radians(angle));
    pitch_matrix[1][0] = sin(radians(angle));
    pitch_matrix[1][1] = cos(radians(angle));

    dmat3 original_matrix(0.0f);
    original_matrix[0] = v;
    original_matrix[1] = n;

    dmat3 transformed_matrix = original_matrix*pitch_matrix;
    v = transformed_matrix[0];
    n = transformed_matrix[1];

    setModelViewMatrix();
}