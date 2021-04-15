#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
using namespace std;
#include<bits/stdc++.h>
const int width = 500;
const int height = 500;

GLfloat eyeX = 14;
GLfloat eyeY = 5;
GLfloat eyeZ = -30;

GLfloat lookX = 3;
GLfloat lookY = 5;
GLfloat lookZ = 28;
double angle = 0 ;

float rot = -13;

static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,3,7,5},
    {0,4,5,1},
    {2,6,7,3},
    {0,1,3,2},
    {4,5,7,6}
};


void cube(float colR=0.5, float colG=0.5, float colB=0.5, float alpha=1)
{
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {
        glColor4f(colR,colG,colB,alpha);

        colR += 0.03;
        colG += 0.03;
        colB += 0.03;

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}

void axes()
{
    float length = 10;
    float width = 0.3;

    // X-axis
    glPushMatrix();
    glTranslatef(length/2,0,0);
    glScalef(length,width,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.8,0.1,0.1);
    glPopMatrix();

    // Y-axis
    glPushMatrix();
    glTranslatef(0,length/2,0);
    glScalef(width,length,width);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.1,0.8,0.1);
    glPopMatrix();

    // Z-axis
    glPushMatrix();
    glTranslatef(0,0,length/2);
    glScalef(width,width,length);
    glTranslatef(-0.5,-0.5,-0.5);
    cube(0.1,0.1,0.8);
    glPopMatrix();
}

void flr()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
    glTranslatef(-0.5,-1,-0.5);
    cube();
    glPopMatrix();
}


void wall1()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,20,60);
    glTranslatef(-30,0,-0.5);
    cube();
    glPopMatrix();
}
void wall2()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,20,60);
    glTranslatef(29,0,-0.5);
    cube();
    glPopMatrix();
}

void wall3()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(60,20,1);
    glTranslatef(-.5,0,10);
    cube();
    glPopMatrix();
}
void headwall()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
    glTranslatef(-0.5,20,-0.5);
    cube();
    glPopMatrix();
}
void spin()
{
    angle = angle + 0.4;
    if (angle >= 360)
        angle = 0;
}
double a=2;
double b=1;
double c= 10;
void fan()
{
    float length = 10;
    float width = 0.3;
    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(width,length,width);
    glTranslatef(-20,1,20);
    cube(0.1,0.8,0.1);
    glPopMatrix();


    glPushMatrix();
    glScalef(1,.1,1);
    glTranslatef(-5,150,2);
    glColor3f(1, 1, 1);            // Set color as glColor3f(R,G,B)
    glRotatef(angle, 0, 0, 1);
    glRecti(-a, -a, a, a);
    glColor3f(1, 1, 0);
    glRecti(-b, a, b, c);
    glColor3f(1, 0, 0);
    glRecti(-c, -b, -a, b);
    glColor3f(0.4, 0, 0);
    glRecti(-b, -c, b, -a);
    glColor3f(0.4, 0.2, 0.6);
    glRecti(a, -b, c, b);
    glPopMatrix();
}


void table()
{
    float height=6;
    float width=10;
    float length=5;

    float base_height=1;
    float leg_height=height-base_height;
    float leg_width=0.5;

    // whole table
    glPushMatrix();
    glTranslatef(0,leg_height,0);

    // base
    glPushMatrix();
    glScalef(width,base_height,length);
    glTranslatef(-0.5,0,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.53,0.39,0.28);
    glPopMatrix();

    glPopMatrix();
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);

    glRotatef(rot, 0,1,0);
  //  axes();

    table();
    flr();
    wall1();
    wall2();
    wall3();
    headwall();
    fan();
    //cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<lookX<<" "<<lookY<<" "<<lookZ<<endl;
//cout<<rot<<endl;
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27 :
    case 'q':
        exit(0);
        break;
    case '+':
        eyeZ++;
        //eyeY++;
        break;
    case '-':
        eyeZ--;
        // eyeY--;
        break;

    case 'a':
        eyeX++;
        //eyeY++;
        break;
    case 's':
        eyeX--;
        // eyeY--;
        break;

    case 'g':
        eyeY++;
        //eyeY++;
        break;
    case 'h':
        eyeY--;
        // eyeY--;
        break;

    case 'w':
        //lookX++;
        lookY++;
        //  lookZ++;
        break;
    case 'e':
        //  lookX--;
        lookY--;
        //  lookZ--;
        break;

    case 'o':
        lookX++;
        //lookY++;
        //  lookZ++;
        break;
    case 'p':
        lookX--;
        //lookY--;
        //  lookZ--;
        break;

    case 'k':
        lookZ++;
        //lookY++;
        //  lookZ++;
        break;
    case 'l':
        lookZ--;
        //lookY--;
        //  lookZ--;
        break;


    case ',':
        rot++;
        break;
    case '.':
        rot--;
        break;

    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
    spin();
}

/* Program entry point */

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("GLUT Shapes");

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

//    glClearColor(1,1,1,1);

    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    printf("########################################################################################\n");
    printf("########################################################################################\n");
    printf("##############                                                         #################\n");
    printf("##############           PLEASE FOLLOW THE BELOW INSTRUCTIONS          #################\n");
    printf("##############                                                         #################\n");
    printf("########################################################################################\n");
    printf("########################################################################################\n\n\n");
    printf("Use 'w' to look up, 's' to look down, 'd' to look right, and 'a' to look left.\n");
    printf("Use 'i' to move camera up, 'k' to move camera down, 'l' to move camera right, and 'j' to move camera left with the look at point fixed.\n");
    printf("Use '+' to zoom in and '-' to zoom out.\n\n\n");

    glutMainLoop();

    return EXIT_SUCCESS;
}
