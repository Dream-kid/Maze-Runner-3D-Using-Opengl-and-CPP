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

GLfloat eyeX = 27;
GLfloat eyeY = 5;
GLfloat eyeZ = -25;

GLfloat lookX = 3;
GLfloat lookY = 5;
GLfloat lookZ = 28;
double angle = 0 ;

float rot = -12;

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


void desk()
{
    glPushMatrix();

    glScalef(.4,1.5,2.9);

    glTranslatef(45,3,2);
    float length=3.4;
    float width=.4;
    //ground
    float a=.8,b=.45,c=.31;
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(3*length,width,width);
    glTranslatef(-.75,-0.5,-0.5);
    cube(a,b,c);
    glPopMatrix();

//right

    glPushMatrix();
    glPushMatrix();
    glTranslatef(1,length/2,1);;
    glScalef(width,length,width);
    glTranslatef(-.5,-0.2,-0.5);
    cube(a,b,c);
    glPopMatrix();
    /*

    //left
        glPushMatrix();
        glPushMatrix();
        glTranslatef(1,length/2,1);;
        glScalef(width,length,width);
        glTranslatef(9,-.2,-0.5);
        cube(a,b,c);
        glPopMatrix();
        */
    //rack1
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length,width,width);
    glTranslatef(-.2,2,-0.5);
    cube(a,b,c);
    glPopMatrix();

    //rack2
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length,width,width);
    glTranslatef(-.2,4.5,-0.5);
    cube(a,b,c);
    glPopMatrix();

    //rack3
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length,width,width);
    glTranslatef(-.2,6.5,-0.5);
    cube(a,b,c);
    glPopMatrix();
    //top
    glPushMatrix();
    glTranslatef(length/2,1,1);;
    glScalef(length*3,width,width);
    glTranslatef(-.75,8.7,-0.5);
    cube(a,b,c);
    glPopMatrix();
    //right
    /*
        glPushMatrix();
        glPushMatrix();
        glTranslatef(1,length/2,1);;
        glScalef(width,length,width);
        glTranslatef(-21,-.2,-.5);
        cube(a,b,c);
        glPopMatrix();
    */
    //rack4
    glPushMatrix();
    glTranslatef(length,1,1);;
    glScalef(2*length+.3,width,width);
    glTranslatef(-1.3,4,-0.5);
    cube(a,b,c);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();

}








void flr()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
    glTranslatef(-0.5,-1,-0.5);
    cube(.2,.3,.5);
    glPopMatrix();
}


void wall1()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,20,60);
    glTranslatef(-30,0,-0.5);
    cube(1,.69,.0);
    glPopMatrix();
}
void wall2()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,20,60);
    glTranslatef(29,0,-0.5);
    cube(1,.69,.0);
    glPopMatrix();
}

void wall3()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(60,20,1);
    glTranslatef(-.5,0,10);
    cube(1,.69,.0);
    glPopMatrix();
}


void door()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(40,20,1);
    glTranslatef(-.6,0,-25);
    cube(1,.69,.0);
    glPopMatrix();

    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(40,10,1);
    glTranslatef(-.3,1,-25);
    cube(1,.69,.0);
    glPopMatrix();
}


void board()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(30,10,1);
    glTranslatef(-.6,.4,9);
    cube(1,1,1);
    glPopMatrix();


    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(31.5,11,1);
    glTranslatef(-.601,.32,9.5);
    cube(0,0,0);
    glPopMatrix();
}
void window()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,8,15);
    glTranslatef(28.9,.5,-1);
    cube(.102,1,1);
    glPopMatrix();

    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,8,.2);
    glTranslatef(28.89,.5,-45);
    cube(0,0,0);
    glPopMatrix();

    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,.2,15);
    glTranslatef(28.89,40,-1);
    cube(0,0,0);
    glPopMatrix();
}

void headwall()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(60,1,60);
    glTranslatef(-0.5,20,-0.5);
    cube(.2,.6,.5);
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

void Chair12()
{
    float height=2;
    float width=4;
    float length=2;

    float base_height=.5;
    float leg_height=height-base_height;
    float leg_width=.4;

    // whole table
    glPushMatrix();
    glTranslatef(0,leg_height,0);

    // base
    glPushMatrix();
    glScalef(width,base_height,length);
    glTranslatef(-0.5,0,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(0.4f, 0.302f, 0.0f);
    glPopMatrix();
//upper put
    glPushMatrix();
    glScalef(3,2,.5);
    glTranslatef(-0.5,.5,-1);
    cube(1,1,0);
    glPopMatrix();

    //middle part 1
glPushMatrix();
    glScalef(.2,1,.2);
    glTranslatef(3,0,-2);
   cube(0,0,0);
    glPopMatrix();

glPushMatrix();
    glScalef(.2,1,.2);
    glTranslatef(-4,0,-2);
   cube(0,0,0);
    glPopMatrix();



    glPopMatrix();

}

void Table12()
{
    float height=2;
    float width=4;
    float length=2;

    float base_height=.5;
    float leg_height=height-base_height;
    float leg_width=.2;

    // whole table
    glPushMatrix();
    glTranslatef(0,leg_height,0);

    // base
    glPushMatrix();
    glScalef(width,base_height,length);
    glTranslatef(-0.5,0,-0.5);
    cube(.6,.2,0);
    glPopMatrix();

    // legs
    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(.8f, .6f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef((width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(.8f, .6f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(.8f, .6f, 0.0f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-(width/2-leg_width/2),0,-(length/2-leg_width/2));
    glScalef(leg_width,leg_height,leg_width);
    glTranslatef(-0.5,-1,-0.5);
    cube(.8f, .6f, 0.0f);
    glPopMatrix();
    glPopMatrix();
}
void test()
{


    for (int i = -8; i <= 10; i+=2)
    {
        for (int j = -4; j <= 3; j+=2)
        {
            glPushMatrix();
            glTranslatef(i*2.0, 0.6f, -15.5+j * 2.0 + 2.2f);
            glScalef(0.25f, 0.3f, 0.25f);
            glRotatef(0.0, 0.0, 1.0, 0.0);
            Chair12();
            glPopMatrix();
        }
    }


    for (int i = -8; i <= 10; i+=2)
    {
        for (int j = -4; j <= 3; j+=2)
        {
            glPushMatrix();
            glTranslatef(i*2.0 + 0.3f, 1.2f,-14.2+ j * 2.0 + 1.2f);
            glScalef(0.4f, 0.4f, 0.4f);
            Table12();
            glPopMatrix();
        }
    }

}



void table()
{
    float height=1;
    float width=30;
    float length=5;

    float base_height=.5;
    float leg_height=height-base_height;
    float leg_width=1;

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
void drop()
{

    glPushMatrix();
//wear drop front
    glColor3ub (89,39,25);
    glBegin(GL_POLYGON);
    glVertex3f (460, 660, 0);
    glVertex3f (470, 670, 0);
    glVertex3f (330, 670,0);
    glVertex3f (340, 660, 0);
    glVertex3f (340, 320, 0);
    glVertex3f (460, 320, 0);
    glEnd();

//wear drop front-drawer 1 - outer
    glColor3ub (42,23,15);
    glBegin(GL_POLYGON);
    glVertex3f (455, 431, 0);
    glVertex3f (345, 431, 0);
    glVertex3f (345, 324, 0);
    glVertex3f (455, 324, 0);
    glEnd();

//wear drop front-drawer 1 - handel
    glColor3ub (255,255,255);
    glBegin(GL_POLYGON);
    glVertex3f (410, 381, 0);
    glVertex3f (390, 381, 0);
    glVertex3f (390, 375, 0);
    glVertex3f (410, 375, 0);
    glEnd();

//wear drop front-drawer 2 - outer
    glColor3ub (42,23,15);
    glBegin(GL_POLYGON);
    glVertex3f (455, 435, 0);
    glVertex3f (345, 435, 0);
    glVertex3f (345, 541, 0);
    glVertex3f (455, 541, 0);
    glEnd();

//wear drop front-drawer 2 - handel
    glColor3ub (255,255,255);
    glBegin(GL_POLYGON);
    glVertex3f (410, 481, 0);
    glVertex3f (390, 481, 0);
    glVertex3f (390, 475, 0);
    glVertex3f (410, 475, 0);
    glEnd();
//wear drop front-drawer 3 - outer
    glColor3ub (42,23,15);
    glBegin(GL_POLYGON);
    glVertex3f (455, 653, 0);
    glVertex3f (345, 653, 0);
    glVertex3f (345, 545, 0);
    glVertex3f (455, 545, 0);
    glEnd();

//wear drop front-drawer 3 - handel
    glColor3ub (255,255,255);
    glBegin(GL_POLYGON);
    glVertex3f (410, 585, 0);
    glVertex3f (390, 585, 0);
    glVertex3f (390, 579, 0);
    glVertex3f (410, 579, 0);
    glEnd();

//wear drop side
    glColor3ub (39,32,21);
    glBegin(GL_POLYGON);
    glVertex3f (470, 670, 0);
    glVertex3f (500, 667, 0);
    glVertex3f (492, 657, 0);
    glVertex3f (492, 330, 0);
    glVertex3f (460, 320, 0);
    glVertex3f (460, 660, 0);
    glEnd();
    glPopMatrix();
}
void weardrop()
{
    glPushMatrix();
//    glTranslatef(0,-0.5,0);



    glTranslatef(4,-14,8);
//glRotatef(rot,0,1,1);
    glScalef(.05,.042,.05);
    drop();
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
    //axes();
    desk();
    table();
    flr();
    wall1();
    wall2();
    wall3();
    door();
    board();
    headwall();
    fan();
    test();
    window();

    weardrop();
    glPushMatrix();
    glTranslatef(1,-.5,-15);
    fan();
    glPopMatrix();

    //  glTranslatef(1,-.5,-15);
    //
    //cout<<eyeX<<" "<<eyeY<<" "<<eyeZ<<" "<<lookX<<" "<<lookY<<" "<<lookZ<<" "<<rot<<endl;
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
