#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include<bits/stdc++.h>
using namespace std;
const int width = 700;
const int height = 700;
float flw=0;
GLfloat eyeX = -214;
GLfloat eyeY = 5;
GLfloat eyeZ = -518;
int score=0;
GLfloat centerX = -288;
GLfloat centerY = 0;
GLfloat centerZ = 28;
float view3rd=0;
float a12=1.0;
float s12=1.0;
float d12=1.0;
float a22=1.0;
float s22=1.0;
float d22=1.0;
float a32=1.0;
float s32=1.0;
float d32=1.0;
float a42=1.0;
float s42=1.0;
float d42=1.0;
float a52=1.0;
float s52=1.0;
float d52=1.0;
double angle = 0 ;
bool l_on1 = true;
bool l_on2 = true;
bool l_on3 = true;
bool l_on4 = true;
bool l_on5 = true;
bool l_on6 = true;
float rot = -12;
bool stop=1;
float door_angle=.5;
float l_height =0;
float spt_cutoff = 0;
unsigned int ID;
float fowd=0;
float lef=0;
bool left_turn=1;
int timer;
int a1=1,b1=0,c1=0;
vector<int>v;
float check1=-300;
float check2=-300;
float fire1=0;
bool fire2=0;
float a=-15,b=1,c=-155;
float ok=0;
int cnt_dwn=0;
bool mark11=0;
float add_lef=0;
float rop_inc=8;
float rop_inc1=8;
float rop_inc_bool=0;
float rop_inc_bool1=0;
bool bridge_j=0;
bool arr[10];
float l_val=.1;
int bridge_val=0;
bool is_start=1;
string str_name="Sourav";
GLint Steps = 4; //a fountain has several steps, each with its own height
GLint RaysPerStep =8;
GLint DropsPerRay = 40;
GLfloat DropsComplete = Steps * RaysPerStep * DropsPerRay;
GLfloat AngleOfDeepestStep = 120;
GLfloat AccFactor = 0.011;
#define PI 3.14152653597689786
#define RandomFactor 2.0
const int L=20;
const int dgre=3;
int ncpt=L+1;
int clikd=0;
const int nt = 40;				//number of slices along x-direction
const int ntheta = 20;


GLfloat ctrlpoints[L+1][3] =
{
    { 0.5, 1.5, 0.0},
    {1.0, 1.5, 0.0}, {1.4, 1.4, 0.0},
    {1.8, 0.4, 0.0},{2.2, 0.4, 0.0},
    {2.6, 1.5, 0.0}, {3.0, 1.4, 0.0},
    {3.4, 1.4, 0.0},{3.8, 1.4, 0.0},
    {4.2, 1.0, 0.0},{4.6, 1.0, 0.0},
    {5.0, 1.0, 0.0},{5.4, 1.0, 0.0},
    {5.8, 0.5, 0.0},{6.2, 0.5, 0.0},
    {6.6, 0.5, 0.0},{7.2, 0.2, 0.0},
    {6.8, 0.52, 0.0}
};

bool flag1=1;
int arrr[]= {7,11,47,67,35-3,85,105,74,227,55,95+7,555};
void reset()
{
    view3rd=0;
    timer=0;
    a1=1,b1=0,c1=0;
    memset(arr,0,sizeof(arr));
    bridge_val=0;
    eyeX = -214;
    eyeY = 5;
    eyeZ = -518;

    centerX = -288;
    centerY = 0;
    centerZ = 28;
    angle=0;
    stop=1;
    door_angle=.5;
    l_height =0;
    spt_cutoff = 0;

    fowd=0;
    lef=0;

    check1=-300;
    check2=-300;
    fire1=0;
    fire2=0;
    a=-15,b=1,c=-155;
    ok=0;
    cnt_dwn=0;
    mark11=0;
    add_lef=0;
    rop_inc=8;
    rop_inc1=8;
    rop_inc_bool=0;
    rop_inc_bool1=0;
    bridge_j=0;

    l_val=.1;
}
static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3,float val=1)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx*val,Ny*val,Nz*val);
}

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
    {3,1,5,7},  //front
    {6,4,0,2},  //back
    {2,3,7,6},  //top
    {1,0,4,5},  //bottom
    {7,5,4,6},  //right
    {2,0,1,3}   //left
};


void cube(float R=0.5, float G=0.5, float B=0.5, int type=0, float val=1,bool player=0)
{

    GLfloat m_no[] = {0, 0, 0, 1.0};
    GLfloat m_amb[] = {R,G,B,1};
    GLfloat m_diff[] = {R,G,B,1};
    GLfloat m_spec[] = {1,1,1,1};
    GLfloat m_sh[] = {30};

    GLfloat m_em[] = {R,G,B,1};

    glMaterialfv(GL_FRONT, GL_AMBIENT, m_amb);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, m_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, m_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, m_sh);
    if(type==1)
    {

        // if(l_on1)
        glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        //  else
        //     glMaterialfv(GL_FRONT, GL_EMISSION, m_no);

    }
    else if(type==2)
    {
        if(l_on3)
            glMaterialfv(GL_FRONT, GL_EMISSION, m_em);
        else
            glMaterialfv(GL_FRONT, GL_EMISSION, m_no);
    }
    else
        glMaterialfv(GL_FRONT, GL_EMISSION, m_no);

    if(!player)
    {
        glBegin(GL_QUADS);
        for (GLint i = 0; i <6; i++)
        {
            getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                        v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                        v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);
            glTexCoord2f(0,val);
            glVertex3fv(&v_cube[c_ind[i][0]][0]);
            glTexCoord2f(0,0);
            glVertex3fv(&v_cube[c_ind[i][1]][0]);
            glTexCoord2f(val,0);
            glVertex3fv(&v_cube[c_ind[i][2]][0]);
            glTexCoord2f(val,val);
            glVertex3fv(&v_cube[c_ind[i][3]][0]);
        }
        glEnd();
    }
}
class BmpLoader
{
public:
    unsigned char* textureData;
    int iWidth, iHeight;

    BmpLoader(const char*);
    ~BmpLoader();

private:
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
};

BmpLoader::BmpLoader(const char* filename)
{
    FILE *file=0;
    file=fopen(filename, "rb");
    if(!file)
        cout<<"File not found"<<endl;
    fread(&bfh, sizeof(BITMAPFILEHEADER),1,file);
    if(bfh.bfType != 0x4D42)
        cout<<"Not a valid bitmap"<<endl;
    fread(&bih, sizeof(BITMAPINFOHEADER),1,file);
    if(bih.biSizeImage==0)
        bih.biSizeImage=bih.biHeight*bih.biWidth*3;
    textureData = new unsigned char[bih.biSizeImage];
    fseek(file, bfh.bfOffBits, SEEK_SET);
    fread(textureData, 1, bih.biSizeImage, file);
    unsigned char temp;
    for(int i=0; i<bih.biSizeImage; i+=3)
    {
        temp = textureData[i];
        textureData[i] = textureData[i+2];
        textureData[i+2] = temp;

    }

    iWidth = bih.biWidth;
    iHeight = bih.biHeight;
    fclose(file);
}

BmpLoader::~BmpLoader()
{
    delete [] textureData;
}

void LoadTexture(const char*filename)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


static void res(int width, int height)
{
    glViewport(0, 0, width, height);
}


long long nCr(int n, int r)
{
    if(r > n / 2)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}

//polynomial interpretation for N points
void BezierCurve ( double t,  float xy[2])
{
    double y=0;
    double x=0;
    t=t>1.0?1.0:t;
    for(int i=0; i<=L; i++)
    {
        int ncr=nCr(L,i);
        double oneMinusTpow=pow(1-t,double(L-i));
        double tPow=pow(t,double(i));
        double coef=oneMinusTpow*tPow*ncr;
        x+=coef*ctrlpoints[i][0];
        y+=coef*ctrlpoints[i][1];

    }
    xy[0] = float(x);
    xy[1] = float(y);

    //return y;
}

void tunnnelbezier()
{

    int i, j;
    float x, y, z, r;				//current coordinates
    float x1, y1, z1, r1;			//next coordinates
    float theta;

    const float startx = 0, endx = ctrlpoints[L][0];
    //number of angular slices
    const float dx = (endx - startx) / nt;	//x step size
    const float dtheta = 2*PI / ntheta;		//angular step size

    float t=0;
    float dt=1.0/nt;
    float xy[2];
    BezierCurve( t,  xy);
    x = xy[0];
    r = xy[1];
    //rotate about z-axis
    float p1x,p1y,p1z,p2x,p2y,p2z;
    for ( i = 5; i < 15; ++i )  			//step through x
    {
        theta = 0;
        t+=dt;
        BezierCurve( t,  xy);
        x1 = xy[0];
        r1 = xy[1];

        //draw the surface composed of quadrilaterals by sweeping theta
        glBegin( GL_QUAD_STRIP );
        for ( j = 0; j <= 8; ++j )
        {
            theta += dtheta;
            double cosa = cos( theta );
            double sina = sin ( theta );
            y = r * cosa;
            y1 = r1 * cosa;	//current and next y
            z = r * sina;
            z1 = r1 * sina;	//current and next z

            //edge from point at x to point at next x
            glVertex3f (x, y, z);

            if(j>0)
            {
                getNormal3p(p1x,p1y,p1z,p2x,p2y,p2z,x, y, z,-1);
            }
            else
            {
                p1x=x;
                p1y=y;
                p1z=z;
                p2x=x1;
                p2y=y1;
                p2z=z1;

            }
            glVertex3f (x1, y1, z1);

            //forms quad with next pair of points with incremented theta value
        }
        glEnd();
        x = x1;
        r = r1;
    } //for i

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
    glEnable(GL_TEXTURE_2D);
    if(left_turn)
        glBindTexture(GL_TEXTURE_2D,v[3]);
    else
        glBindTexture(GL_TEXTURE_2D,v[10]);

    glPushMatrix();


    glTranslatef(0,-0.5,-80);
    glScalef(220,1,220);
    glTranslatef(-0.5,-1,-0.5);
    cube(1,1,1,0,30);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}


void wall1()
{
    glEnable(GL_TEXTURE_2D);
    if(left_turn)
        glBindTexture(GL_TEXTURE_2D,v[0]);
    else
        glBindTexture(GL_TEXTURE_2D,v[12]);

    glPushMatrix();

//    glTranslatef(0,-0.5,0);
    glScalef(1,160,160);
    glTranslatef(-30,0,-1);
    cube(1,1,1,0,20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


}
void wal12()
{
    glEnable(GL_TEXTURE_2D);
    if(left_turn)
        glBindTexture(GL_TEXTURE_2D,v[0]);
    else
        glBindTexture(GL_TEXTURE_2D,v[12]);
    glPushMatrix();
//    glTranslatef(0,-0.5,0);
    glScalef(1,160,160);
    glTranslatef(29,0,-1);
    cube(1,1,1,0,20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}




void headwall()
{
    glEnable(GL_TEXTURE_2D);
    if(left_turn)
        glBindTexture(GL_TEXTURE_2D,v[2]);
    else
        glBindTexture(GL_TEXTURE_2D,v[11]);
    glPushMatrix();

//    glTranslatef(0,-0.5,0);

    glTranslatef(0,-0.5,-80);
    glScalef(300,1,240);
    glTranslatef(-0.5,19,-.5);
    cube(0.690, 0.769, 0.871,0,10);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

}


void light1(float a,float b,float c) //l_on1
{
    glEnable(GL_LIGHT0);

    //light
    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {0.1*a12, 0.1*a12, 0.1*a12, 1.0};
    GLfloat l_dif[] = {.1*d12,.1*d12,.1*d12,1};
    GLfloat l_spec[] = {.1*s12,.1*s12,.1*s12,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on1)
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT0, GL_AMBIENT, l_no);
    if(l_on1)
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT0, GL_DIFFUSE, l_no);
    if(l_on1)
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT0, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT0, GL_POSITION, l_pos);


}

void light2(float a,float b,float c) //l_on2
{
    glEnable(GL_LIGHT5);
    //light
    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {0.1*a22, 0.1*a22, 0.1*a22, 1.0};
    GLfloat l_dif[] = {.1*d22,.1*d22,.1*d22,1};
    GLfloat l_spec[] = {.1*s22,.1*s22,.1*s22,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on2)
        glLightfv(GL_LIGHT5, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT5, GL_AMBIENT, l_no);
    if(l_on2)
        glLightfv(GL_LIGHT5, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT5, GL_DIFFUSE, l_no);
    if(l_on2)
        glLightfv(GL_LIGHT5, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT5, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT5, GL_POSITION, l_pos);
    // GLfloat l_spt[] = {0,-1,0,1};
//    GLfloat spt_ct[] = {66};
//    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
//    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);


}


float k=0;
void spin()
{
    angle +=k;
    k=8;
    if (angle >= 360)
        angle = 0;

}
double a4=2;
double b4=1;
double c4= 10;
void fan()
{
    //fan stand

    float length = 10;
    float width = 0.7;
    glPushMatrix();
    glTranslatef(.5,-3+.7,-.2);
    glPushMatrix();
    // glRotatef(l_height,0,1,0);
    glScalef(.1,.3,.1);
    glPushMatrix();
    glTranslatef(1,length/2,-4);
    glScalef(width,length,width);
    glTranslatef(-20+15,0,20-12);
    //cube(0.4,0.4,0.1);
    glPopMatrix();


    glPushMatrix();
    glScalef(1,.1,1);
    glTranslatef(-5,150,2);
    cube(1, 1, 1);
    glRotatef(90,1,0,0);
    //cout<<spt_cutoff<<endl;
    // Set color as glColor3f(R,G,B)
    glRotatef(angle, 0, 0, 1);
    glRecti(-a4, -a4, a4, a4);
    cube(1, 0, 0);
    glRecti(-b4, a4, b4, c4);
    glRecti(-c4, -b4, -a4, b4);
    glRecti(-b4, -c4, b4, -a4);
    glRecti(a4, -b4, c4, b4);
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //cout<<l_height<<" "<<spt_cutoff<<" "<<stop<<endl;
}



void walloff()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[0]);


    //cout<<spt_cutoff<<endl;

    glPushMatrix();
    glScalef(20,20,60);
    // glRotatef(,0,1,0);
    glTranslatef(11-13.45,0,-0.4+.6);
    cube(1,1,1,2);
    glPopMatrix();


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[4]);
    //door
    glPushMatrix();
    glScalef(20,20,10);
    glTranslatef(11-13.45+.1+3.7,0,-0.4+.6-.2-1.1);
    // glRotatef(,0,1,0);
    cube(1,1,1);
    glPopMatrix();


    //back wall
    glEnable(GL_TEXTURE_2D);
    if(left_turn)
        glBindTexture(GL_TEXTURE_2D,v[5]);
    else
        glBindTexture(GL_TEXTURE_2D,v[14]);

    glPushMatrix();
    glScalef(68,20,20);
    // glRotatef(,0,1,0);
    glTranslatef(3.11-3.599-.05,0,.9+.05-.9);
    cube(1,1,1-left_turn,0,1);
    if(fire1<=15&&!fire2)
        fire1+=.1;
    else
        fire1-=.1,fire2=1;
    if(fire1<=-15)
        fire2=0;

    glPopMatrix();

    glPushMatrix();
    glScalef(78,20,20);
    // glRotatef(,0,1,0);
    glTranslatef(3.11-3.599-.05,0,.9+.05-.9-9.08);
    cube(1,1,1-left_turn,0,1);
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);

    // cout<<spt_cutoff<<" "<<l_height<<endl;
}


void wall()
{
    flr();
    wall1();
    wal12();
    headwall();
    walloff();
}

//unsigned int i;

GLfloat xt=0.0,yt=0.0,zt=0.0;
GLfloat xangle=0.0,yangle=0.0,zangle=0.0;
GLfloat X[3];
GLfloat WaterHeight = .45;
struct edge
{
    GLfloat x,y,z;
};

///////////////////////////////fountain///////////////////////////////////
struct waterdrop
{

    GLfloat time;
    edge ConstantSpeed;
    GLfloat AccFactor;
    void SetConstantSpeed (edge NewSpeed);
    void SetAccFactor(GLfloat NewAccFactor);
    void SetTime(GLfloat NewTime);
    void GetNewPosition(edge * PositionVertex); //increments time, gets the new position
};

void waterdrop::SetConstantSpeed(edge NewSpeed)
{
    ConstantSpeed = NewSpeed;
}

void waterdrop::SetAccFactor (GLfloat NewAccFactor)
{
    AccFactor = NewAccFactor;
}

void waterdrop::SetTime(GLfloat NewTime)
{
    time = NewTime;
}

void waterdrop::GetNewPosition(edge * PositionVertex)
{
    edge Position;
    time += 0.15;
    Position.x = ConstantSpeed.x * time;
    Position.y = ConstantSpeed.y * time - AccFactor * time *time;
    Position.z = ConstantSpeed.z * time;
    PositionVertex->x = Position.x;
    PositionVertex->y = Position.y + WaterHeight;
    PositionVertex->z = Position.z;
    if (Position.y < 0.0)
    {
        time = time - int(time);
        if (time > 0.0)
            time -= 1.0;
    }

}

waterdrop * FountainDrops;
edge * FountainVertices;

// Creating reservoir boundary

GLfloat GetRandomFloat(GLfloat range)
{
    return (GLfloat)rand() / (GLfloat)RAND_MAX * range * RandomFactor;
}

void init(void)
{
    FountainDrops = new waterdrop [ (int)DropsComplete ];
    FountainVertices = new edge [ (int)DropsComplete ];
    edge NewSpeed;
    GLfloat DropAccFactor;
    GLfloat TimeNeeded;
    GLfloat StepAngle;
    GLfloat RayAngle;
    GLint i,j,k;
    for (k = 0; k <Steps; k++)
    {
        for (j = 0; j < RaysPerStep; j++)
        {
            for (i = 0; i < DropsPerRay; i++)
            {
                DropAccFactor = AccFactor + GetRandomFloat(0.0005);
                StepAngle = AngleOfDeepestStep + (90.0-AngleOfDeepestStep)
                            * GLfloat(k) / (Steps-1) + GetRandomFloat(0.2+0.8*(Steps-k-1)/(Steps-1));
                NewSpeed.x = cos ( StepAngle * PI / 180.0) * (0.2+0.04);
                NewSpeed.y = sin ( StepAngle * PI / 180.0) * (0.2+0.04);
                RayAngle = (GLfloat)j / (GLfloat)RaysPerStep * 360.0;
                NewSpeed.z = NewSpeed.x * sin ( RayAngle * PI /180.0);
                NewSpeed.x = NewSpeed.x * cos ( RayAngle * PI /180.0);
                TimeNeeded = NewSpeed.y/ DropAccFactor;
                FountainDrops[i+j*DropsPerRay+k*DropsPerRay*RaysPerStep].SetConstantSpeed ( NewSpeed );
                FountainDrops[i+j*DropsPerRay+k*DropsPerRay*RaysPerStep].SetAccFactor (DropAccFactor);
                FountainDrops[i+j*DropsPerRay+k*DropsPerRay*RaysPerStep].SetTime(TimeNeeded * i / DropsPerRay);
            }
        }
    }
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,FountainVertices);
}


void DrawFountain(int vall)
{

    if(vall==1)
        cube(0,0,1,0,1,1);
    if(vall==2)
        cube(1,0,1,0,1,1);
    if(vall==3)
        cube(1,0,0,0,1,1);
    if(vall==4)
        cube(0,1,0,0,1,1);

    for (int i = 0; i < DropsComplete; i++)
    {
        FountainDrops[i].GetNewPosition(&FountainVertices[i]);
    }
    glDrawArrays(GL_POINTS,0,DropsComplete);
}



int life=3;
bool over=0;

void game_over()
{
    life--;
    if(life==0)
    {
        over=1;
    }
    reset();
}
void spot_light4(float a,float b,float c) //l_on3
{
    //light
    glEnable(GL_LIGHT3);

    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {1*a32, 1*a32, 1*a32, 1.0};
    GLfloat l_dif[] = {1*d32,1*d32,1*d32,1};
    GLfloat l_spec[] = {1*s32,1*s32,1*s32,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on3)
        glLightfv(GL_LIGHT3, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT3, GL_AMBIENT, l_no);
    if(l_on3)
        glLightfv(GL_LIGHT3, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT3, GL_DIFFUSE, l_no);
    if(l_on3)
        glLightfv(GL_LIGHT3, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT3, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT3, GL_POSITION, l_pos);
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {30};
    // glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, l_spt);
    //  glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, spt_ct);

}


void spot_light3(float a,float b,float c) //l_on4
{
    //light
    glEnable(GL_LIGHT4);


    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {1*a32, 1*a32, 1*a32, 1.0};
    GLfloat l_dif[] = {1*d32,1*d32,1*d32,1};
    GLfloat l_spec[] = {1*s32,1*s32,1*s32,1};
    GLfloat l_pos[] = {a,b,c,1.0};
    if(l_on4)
        glLightfv(GL_LIGHT4, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT4, GL_AMBIENT, l_no);
    if(l_on4)
        glLightfv(GL_LIGHT4, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT4, GL_DIFFUSE, l_no);
    if(l_on4)
        glLightfv(GL_LIGHT4, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT4, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT4, GL_POSITION, l_pos);
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {30};
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT4, GL_SPOT_CUTOFF, spt_ct);

}

void swoard()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[15]);
    glPushMatrix();
    glTranslatef(0-1,.78-1.7,.74-.6);
    glScalef(.1,4,.1);
    cube(0,1,1,0,6);

    glPopMatrix();
    glPushMatrix();
    glTranslatef(0-1+1.9,.78-1.7,.74-.6);
    glScalef(.1,4,.1);
    cube(1,1,0,0,6);

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    // cout<<flw<<" "<<spt_cutoff<<" "<<stop<<" "<<l_height<<endl;
}
void player()
{
    /// maintopball();
    GLUquadric *quad;
    quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[17]);
    gluQuadricTexture(quad,1);
    glPushMatrix();
    cube(1,1,1,0,1,1);
    glTranslatef(0,2.2,0);
    glScalef(1.2,1.2,1.2);
    gluSphere(quad,.18,100,100);
    glPopMatrix() ;
    glDisable(GL_TEXTURE_2D);

    fan();
    swoard();

    ///eyeright();
    glPushMatrix();
    glTranslatef(.17,1.1,.75);
    glRotatef(-45,0,0,1);
    glScalef(.9,.7,.7);
    cube(1.0,0.0,0.0,0,1,1);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    /// eyeleft();
    glPushMatrix();
    glTranslatef(-.17,1.1,.75);
    glRotatef(45,0,0,1);
    glScalef(.9,.7,.7);
    cube(1.0,0.0,0.0,0,1,1);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();


    ///eyebrowleft();
    glPushMatrix();
    glTranslatef(-.3,1.5,.9);;
    glRotatef(90,0,1,0);
    glRotatef(20,1,0,0);
    cube(0.0,0.0,0.0,0,1,1);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();

    /// eyebrowright();
    glPushMatrix();
    glTranslatef(.3,1.5,.9);
    glRotatef(270,0,1,0);
    glRotatef(20,1,0,0);
    gluCylinder(gluNewQuadric(),.05,.01,.3,4,6);
    glPopMatrix();
    cube(0.0,1.0,0.0,0,1,1);

    /// neckring();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[18]);
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(.59,.59,.59);
    glRotatef(90.0,1,0,0);
    cube(1,1,1,0,1,1);
    glutSolidTorus(.1,1.0,20,20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    cube(35/255.0,20/255.0,180/255.0,0,1,1);

    ///legright();
    glPushMatrix();
    glTranslatef(-.3,-.77,0);
    glScalef(1,1.5,1);
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,35,6);
    glPopMatrix();


    /// legleft();
    glPushMatrix();
    glTranslatef(.3,-.77,0);
    glScalef(1,1.5,1);
    glRotatef(-90.0,1,0,0);
    glScalef(.8,.8,.8);
    gluCylinder(gluNewQuadric(),.5,.5,.5,35,6);
    glPopMatrix();

    cube(255/255.0,90/255.0,0,0,1,1);

    /// armleft();
    quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[1]);
    gluQuadricTexture(quad,1);
    glPushMatrix();
    glTranslatef(-.82,0,.1);
    glRotatef(90,0,1,0);
    glRotatef(-50,1,0,0);
    cube(1,1,1,0,1,1);
    gluCylinder(quad,.15,.15,.48,30,6);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    /// armright();
    quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[1]);
    gluQuadricTexture(quad,1);
    glPushMatrix();
    glTranslatef(.82,0,.1);
    glRotatef(90,0,1,0);
    glRotatef(-130,1,0,0);
    cube(1,1,1,0,1,1);
    gluCylinder(quad,.15,.15,.48,30,6);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    /// BellyCoat();
    quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[17]);
    gluQuadricTexture(quad,1);
    glPushMatrix();
    glTranslatef(0,.5,0);
    glScalef(1,.9,1);
    glRotatef(90.0,1,0,0);
    cube(1,1,1,0,1,1);
    gluCylinder(quad,.6,.8,1,100,100);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    cube(0,185/255.0,.3,0,1,1);
    ///  handright();
    glPushMatrix();
    glTranslatef(-.82,0,.1);
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();


    /// handleft();
    glPushMatrix();
    glTranslatef(.82,0,.1);
    glScalef(.4,.3,.3);
    gluSphere(gluNewQuadric(),.6,100,100);
    glPopMatrix();

///    mouth();
    glPushMatrix();
    glTranslatef(0,.8,.74);
    glScalef(.4,.4,.1);
    cube(.0,0.0,0.0,0,1,1);
    gluSphere(gluNewQuadric(),.5,100,100);
    glPopMatrix();


    ///head();
    quad = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[17]);
    glPushMatrix();
    glTranslatef(0,1.2,0);
    glScalef(.9,.9,.9 );
    cube(1,1,1,0,1,1);
    gluQuadricTexture(quad,1);
    gluSphere(quad,1,100,100);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    cube(0.0,0.0,0.0,0,1,1);

    ///footleft();
    glPushMatrix();
    glTranslatef(-.3,-.9,0);
    glScalef(1.5,.5,1.5);
    cube(0.0,0.0,0.0,0,1,1);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    /// footright();
    glPushMatrix();
    glTranslatef(.3,-.9,0);
    glScalef(1.5,.5,1.5);
    cube(0.0,0.0,0.0,0,1,1);
    gluSphere(gluNewQuadric(),.3,100,100);
    glPopMatrix();

    ///  topbutton();
    quad = gluNewQuadric();
    glPushMatrix();
    cube(0,0.0,1,0,1,1);
    glTranslatef(-.1,.4,.65);
    glScalef(1.9,1.9,1.9);
    gluSphere(quad,.07,100,100);
    glPopMatrix();
    cube(0.0,0.0,0.0,0,1,1);

    /// pupilleft();
    glPushMatrix();
    glTranslatef(-.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.13,100,100);
    glPopMatrix();

    ///pupilright();
    glPushMatrix();
    glTranslatef(.17,1.1,.88);
    glScalef(.9,.9,.9);
    gluSphere(gluNewQuadric(),.13,100,100);
    glPopMatrix();


    ///  nose
    quad = gluNewQuadric();
    glPushMatrix();
    cube(1,0,1,0,1,1);
    glTranslatef(0,.9,.75);
    glScalef(1.9,1.9,1.9);
    gluSphere(quad,.07,100,100);
    glPopMatrix();


}

void fire()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[6]);
    glPushMatrix();
    glTranslatef(-45+fire1,-1.5,-155+45);
    glScalef(85,1.5,6);
    cube(1,1,0,0,3);
//cout<<spt_cutoff<<" "<<l_height<<endl;
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-45+fire1,-1.5,-155+85);
    glScalef(85,1.5,6);
    cube(1,1,0,0,3);
//cout<<spt_cutoff<<" "<<l_height<<endl;
    glPopMatrix();


    if(c>=-109&&c<=-108.5&&b==1)
    {
        game_over();
    }

    if(c>=-69&&c<=-68.5&&b==1)
    {
        game_over();
    }
//cout<<a<<" "<<c<<endl;
    glDisable(GL_TEXTURE_2D);
}

void point()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[7]);
    glPushMatrix();
    glTranslatef(-15,3,-155+25);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
    if(c<=-129&&c>=-131&&add_lef<=-2)
    {
        if(!arr[0])
            score++,arr[0]=1;
        // cout<<"point"<<endl;
    }
    //cout<<add_lef<<" "<<c<<endl;
//cout<<spt_cutoff<<" "<<l_height<<endl;
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,3,-155+70);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-2,3,-155+64);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
    if(c<=-84&&c>=-87&&add_lef>=2)
    {
        if(!arr[1])
            score++,arr[1]=1;
        // cout<<"point1"<<endl;
    }
    if(c<=-78&&c>=-81&&add_lef>=2)
    {
        if(!arr[2])
            score++,arr[2]=1;
        // cout<<"point2"<<endl;
    }
    //cout<<add_lef<<" "<<c<<endl;
//cout<<spt_cutoff<<" "<<l_height<<endl;
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}
void point1()
{

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[7]);
    glPushMatrix();
    glTranslatef(-10,3,-155+25);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
    if(c<=-129&&c>=-131&&add_lef>=1)
    {
        //  cout<<"point"<<endl;
        if(!arr[3])
            score++,arr[3]=1;
    }

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10,3,-155+50);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
    if(c<=-104&&c>=-106&&add_lef<=-3)
    {
        if(!arr[4])
            score++,arr[4]=1;
        // cout<<"point23"<<endl;
    }

    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2,7,-155+74);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
//cout<<spt_cutoff<<" "<<l_height<<endl;
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1,7,-155+84);
    glRotatef(45,0,1,0);
    glScalef(2,2,1);
    cube(1,1,1);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // cout<<add_lef<<endl;

    if(c>=-81&&c<=-78&&add_lef>=0)
    {
        if(!arr[5])
            score++,arr[5]=1;
        //   cout<<"point2"<<endl;
    }
    if(c>=-71&&c<=-68&&add_lef>=0)
    {
        if(!arr[6])
            score++,arr[6]=1;
        //cout<<"point3"<<endl;
    }
    //cout
}
void design()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[9]);
    for(int i=0; i<=95; i+=15)
    {
        glPushMatrix();
        glTranslatef(27,4,-155+25+i);
        //glRotatef(-29.9,0,1,0);
        glScalef(1,8,4);
        cube(1,1,1);
        //cout<<add_lef<<" "<<c<<endl;
//cout<<spt_cutoff<<" "<<l_height<<endl;
        glPopMatrix();
    }
    glBindTexture(GL_TEXTURE_2D,v[8]);
    for(int i=0; i<=115; i+=25)
    {
        glPushMatrix();
        glTranslatef(-30,0,-155+25+i);
        //glRotatef(-25,0,1,0);
        glScalef(4,15,4);
        cube(1,1,1);
        //cout<<add_lef<<" "<<c<<endl;
//cout<<spt_cutoff<<" "<<l_height<<endl;
        glPopMatrix();
    }

    glBindTexture(GL_TEXTURE_2D,v[14]);
    for(int i=0; i<=115; i+=25)
    {
        glPushMatrix();
        glTranslatef(-30,0,-155+25+i-.1);
        //glRotatef(-25,0,1,0);
        glScalef(4,15,.1);
        cube(1,1,1);
        //cout<<add_lef<<" "<<c<<endl;
//cout<<spt_cutoff<<" "<<l_height<<endl;
        glPopMatrix();
    }
    glDisable(GL_TEXTURE_2D);
}

void rope()
{

    //laser1
    // glEnable(GL_TEXTURE_2D);
    //glBindTexture(GL_TEXTURE_2D,v[14]);
    cube(1,0,0,0,1,1);
    glLineWidth(12);
    glPushMatrix();
    glTranslatef(-25,-1.5,-155+45);
    glBegin(GL_LINES);
    glVertex2f(104-93,167-146);

    glVertex2f(1+rop_inc+13, 7-43);
    if(rop_inc_bool&&rop_inc<=29&&rop_inc>=12)
        rop_inc-=.1;
    else if(rop_inc<28)
    {
        rop_inc_bool=0;
        rop_inc+=.1;

    }
    else
        rop_inc_bool=1;

    glEnd();

    if(c>=-112 && c<=-108)
    {
        if(add_lef>-.8)
        {
            game_over();
        }
    }
    glPopMatrix();

//laser

    glPushMatrix();
    glTranslatef(-25-1-2,-1.5,-155+45-12);
    //
    glBegin(GL_LINES);
    glVertex2f(104-93,167-146);

    glVertex2f(1+rop_inc1+13, 7-43);
    if(rop_inc_bool1&&rop_inc1<=35&&rop_inc1>=16)
    {
        rop_inc1-=.1;

    }
    else if(rop_inc1<34)
    {
        rop_inc_bool1=0;
        rop_inc1+=.1;

    }
    else
        rop_inc_bool1=1;

//cout<<rop_inc+14<<" "<<7-43<<endl;
    glEnd();

//cout<<add_lef<<endl;
    if(c>=-123 && c<=-120)
    {
        if(add_lef<1)
        {
            game_over();
        }
    }
    glPopMatrix();
//   cout<<add_lef<<endl;
    // cout<<c<<endl;
    // cout<<l_height<<" "<<spt_cutoff<<endl;
    //  glDisable(GL_TEXTURE_2D);
}

void tunnel()
{
    glPushMatrix();
    glTranslatef(-32+20+9+1,-5+.5+1,-155+45+5+6-5-2+64-5-11);
    glScalef(7+2,10-2+1+3,15);
    glRotatef(-106+10+12,1,0,0);
    glRotatef(-80-7-3-25-7,0,0,1);
    glRotatef(211,0,0,1);
    cube(	0.282, 0.239, 0.545,0,1,1);
    tunnnelbezier();
    glPopMatrix();
    //  cout<<spt_cutoff<<endl;
}
void bridge()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[2]);
    glPushMatrix();
    glTranslatef(-32+20-2,2,-155+45+5+6);
    glScalef(24,2,45);
    cube(1,1,1,0,3);
    glPopMatrix();
    glBindTexture(GL_TEXTURE_2D,v[6]);
    glPushMatrix();
    glTranslatef(-32+-1,-1.5,-155+45+16);
    glScalef(80,2,45);
    cube(1,1,1,0,3);
    glPopMatrix();

    if(c>=-99 &&c<=-50)
    {
        if(mark11||bridge_j)
        {
            b=5.5;
            eyeY = 8;
            bridge_j=1;
            mark11=0;
        }
        else
        {
            game_over();
        }
        bridge_val=3;

        //cout<<"bridge"<<endl;
    }

    else if(c>-50)
    {
        bridge_j=0;
        eyeY = 5-view3rd*2;
        bridge_val=0;
    }
    //  cout<<l_height<<" "<<spt_cutoff<<endl;
    glDisable(GL_TEXTURE_2D);
}
void spot_light1(float a,float b,float c)//l_on5
{
    //light
    glEnable(GL_LIGHT1);

    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {1*a42, 1*a42, 1*a42, 1.0};
    GLfloat l_dif[] = {1*d42,1*d42,1*d42,1};
    GLfloat l_spec[] = {1*s42,1*s42,1*s42,1};
    GLfloat l_pos[] = {a,b,c,1.0};

    if(l_on5)
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT1, GL_AMBIENT, l_no);
    if(l_on5)
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT1, GL_DIFFUSE, l_no);
    if(l_on5)
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT1, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT1, GL_POSITION, l_pos);
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {30};
    glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT1, GL_SPOT_CUTOFF, spt_ct);

}
void spot_light2(float a,float b,float c) //l_on6
{
    //light
    glEnable(GL_LIGHT2);

    GLfloat l_no[] = {0, 0, 0, 1.0};
    GLfloat l_amb[] = {1*a52, 1*a52, 1*a52, 1.0};
    GLfloat l_dif[] = {1*d52,1*d52,1*d52,1};
    GLfloat l_spec[] = {1*s52,1*s52,1*s52,1};
    GLfloat l_pos[] = {a,b,c,1.0};
    if(l_on6)
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_amb);
    else
        glLightfv(GL_LIGHT2, GL_AMBIENT, l_no);
    if(l_on6)
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_dif);
    else
        glLightfv(GL_LIGHT2, GL_DIFFUSE, l_no);
    if(l_on6)
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_spec);
    else
        glLightfv(GL_LIGHT2, GL_SPECULAR, l_no);

    glLightfv(GL_LIGHT2, GL_POSITION, l_pos);
    GLfloat l_spt[] = {0,-1,0,1};
    GLfloat spt_ct[] = {30};
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, l_spt);
    glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, spt_ct);

}

void makecylinder(float height,float Base)
{
    GLUquadricObj *qobj;
    qobj = gluNewQuadric();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[20]);
    cube(.5, .5, .5,0,1,1);
    glPushMatrix();
    gluQuadricTexture(qobj,1);

    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    gluCylinder(qobj, Base, Base - (0.2 * Base), height, 20, 20);
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}

void maketree(float height,float Base,int val)
{


    //  cout<<spt_cutoff<<endl;
    glPushMatrix();
    //  cout<<height<<" "<<Base<< " "<<val<<endl;



    float angle;
    makecylinder(height, Base);
    glTranslatef(0.0f, height,0.0f);
    height -=height*0.2f;
    Base -=Base*0.3f;

    angle = 20+((arrr[(int)(val%10)]))%50;
    if(angle >48)
        angle = -(20+(arrr[(int)((val+17)%10)])%50);
    if (height > 1)
    {
        glPushMatrix();
        if (flag1)
            glRotatef(angle, 1.0f, 0.0f, 1.0f);
        else
            glRotatef(angle, 0.0f, 1.0f, 1.0f);
        flag1 = !flag1;
        maketree(height, Base,arrr[int(val+97)%10]); //recursive call
        glPopMatrix();

    }
    else
    {

        GLUquadric *quad;
        quad = gluNewQuadric();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,v[19]);
        glPushMatrix();
        //glTranslatef(0,1.2,0);
        // glScalef(.9,.9,.9 );
        glTranslatef(0.0f, -2.2f,0.0f);
        cube(1,1,1,0,1,1);
        gluQuadricTexture(quad,1);
        gluSphere(quad,2,4,4);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);

    }
    //Glut.glutSwapBuffers();
    glPopMatrix();
}

void tree()
{

//cout<<spt_cutoff<<endl;
    for(int i=-10; i<=20; i+=10)
    {
        glPushMatrix();
        glTranslatef(-17.9,.5,-155+30+i);
        //glRotatef(-25,0,1,0);
        //glScalef(2,2,.5);
        cube(1,1,1,0,1,1);
        flag1=1;
        for(int j=5; j<=10; j++)
        {
            glRotatef(-33,0,1,0);
            maketree(2.5f,.5f,arrr[j]);
            flag1=1;
        }

        glPopMatrix();
    }
}

void fountain()
{
    int vall=0;
    for(int i=0; i<=30; i+=10)
    {
        glPushMatrix();
        vall++;
        glTranslatef(-10,-4,i);
        glPushMatrix();
        glTranslatef(12.9,1,-155+20);
        init();
        glScalef(4,8,2);
        DrawFountain(vall);
        glPopMatrix();


        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,v[14]);
        glPushMatrix();
        glTranslatef(11.9,4,-156+20);
        glScalef(2.5,1,2.9 );
        cube(1,1,1);
        glPopMatrix();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
}
void moshal()
{
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,v[15]);
    for(int i=0; i<=95; i+=15)
    {
        glPushMatrix();
        glTranslatef(28.9,5,-155+30+i+5);

        //glRotatef(-25,0,1,0);
        glScalef(1,6,2);
        cube(1,1,1);
        glPopMatrix();
    }

    for(int i=0; i<=115; i+=25)
    {
        glPushMatrix();
        glTranslatef(-29.9,5,-155+30+i+5);
        //glRotatef(-25,0,1,0);
        glScalef(1,6,2);
        cube(1,1,1);
        glPopMatrix();
    }


    glBindTexture(GL_TEXTURE_2D,v[13]);
//rocks

    glPushMatrix();
    glTranslatef(6,-1.4,-155);
    //glRotatef(-45,0,1,0);
    glScalef(55,1.5,200);

    if(left_turn)
        cube(left_turn,left_turn,0,0,10);
    glPopMatrix();


    glDisable(GL_TEXTURE_2D);


}

void drawStrokeText1(string str,int x,int y,int z,float val=1,int col=0)
{
    //char *c;
    glPushMatrix();
    glLineWidth(1);
    glTranslatef(x, y,z);

    //  glRotatef(184,0,1,0);
    cube(1,col,0,0,1,1);
    glScalef(.004f*val,.004f*val,10);

    for (int c=0; c != str.size(); c++)
    {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str[c]);
    }
    glPopMatrix();
    //cout<<spt_cutoff<<" "<<l_height<<endl;
}

bool pop=0;
int vall=0;
int llll=0;


int arr10[8][6]= {{-214+c+155,5+b-1,-518,-288,0+a+15+add_lef,28},
    {-214+c+155, 5+b-1, -516, 130,0+a+15+add_lef,2878},
    {-220+c+155, 5+b-1, -511, 6932,16+a+15+add_lef, -428},
    {-220+c+155, 5+b-1, -509, 6134,16+a+15+add_lef,-3734},
    {-214+c+155, 5+b-1, -503, 2410,16+a+15+add_lef,-3734},
    {-210+c+155, 5+b-1, -506, -3290, 16+a+15 +add_lef,-3734},
    {-207+c+155, 5+b-1, -512, -9370, 16+a+15 +add_lef,7628},
    {-207+c+155, 5+b-1, -515, -2606, 16+a+15+add_lef,7628}
};
void light()
{
    //cout<<eyeX<<" "<<eyeY<< " "<<eyeZ<<" "<<centerX<<" "<<centerY<<" "<<centerZ<<endl;
//  left_turn=0;

//light 1
//fire1
//bridge();

//   tunnel();
    if(pop||vall)
    {
        if(!pop)
            vall=0;
        eyeX=arr10[vall][0];
        eyeY=arr10[vall][1];
        eyeZ=arr10[vall][2];
        centerX=arr10[vall][3];
        centerY=arr10[vall][4];
        centerZ=arr10[vall][5];
        if(llll%80==0)
        {
            vall++;
            vall%=8;
        }
        llll++;
        //pop=0;
    }

    if(c>-7)
        game_over();
    moshal();
    if(left_turn)
        design();
    if(over)
        is_start=1,b=1,bridge_val=0;
    if(!over)
    {
        if(!is_start)
        {

            if(mark11)
                cnt_dwn++,eyeY=8,bridge_val=3;
            if(cnt_dwn>=95||!mark11)
            {
                eyeY=5-view3rd*2;;
                mark11=0;
                b=1;
                cnt_dwn=0;
                bridge_val=0;
            }
            if(left_turn)
            {

                fire();
                point();

            }
            else
            {
                fountain();
                tree();
                rope();
                bridge();

                tunnel();
                point1();
            }
        }
        else
            b=1,bridge_val=0;
    }
    glPushMatrix();


    glTranslatef(a+add_lef,b,c);
    glPushMatrix();
    glRotatef(ok,0,1,0);
    if(ok>=360)
        ok=0;
    if(stop)
        ok++;
    drawStrokeText1(str_name,-1.9-.19+.2,3,.9);
    player();
//   cout<<spt_cutoff<<" "<<l_height<<" "<<stop<<" "<<flw<<endl;

    glPopMatrix();

    glPopMatrix();

    //spot light

    glPushMatrix();
    glTranslatef(a+add_lef,18,c+39+13);
    int a1=15,b1=30,c1=-15;
    glRotatef(-39,0,1,0);
    spot_light1(a1-157+31,b+1+263,c1-131); //l_on5
    glPopMatrix();

    glPushMatrix();
    glTranslatef(a+add_lef,18,c+39+13);
    a1=15,b1=30,c1=-15;
    glRotatef(-39+37,0,1,0);
    spot_light2(a1-165-157+31,b+1+263+1,c1-131); //l_on6
    glPopMatrix();

    glPushMatrix();
    glTranslatef(a+add_lef,18,c+39+13);
    a1=15,b1=30,c1=-15;
    glRotatef(2-39,0,1,0);
    spot_light3(a1-157+31-40,5+b+1+263,c1-131);  //l_on4
    //  spot_light4(a1+l_height-157+31-40,5+b+1+stop+263,c1+flw-131);  //l_on3
    glPopMatrix();
//cout<<spt_cutoff<<" "<<l_height<<" "<<stop<<" "<<flw<<endl;

    glPushMatrix();
    glPushMatrix();

    glRotatef(200, 0,1,0);
//cout<<add_lef<<" "<<c<<" ->"<<endl;
    if(!is_start)
        a+=lef,c+=fowd;

    light1(a1,b1,c1);//l_on1
    light2(a1,b1,c1+200);//l_on2
    //cout<<stop<<endl;
    glPopMatrix();
    glTranslatef(a,b+1,c);

    glScalef(2,2,2);
    glTranslatef(-0.5,-0.5,-0.5);
    //glRotatef(270,0,1,0);
    //cube(1,1,1,1);

    glPopMatrix();

    fowd=.08;
    lef=.015;

}
void drawStrokeText(string str,int x,int y,float z,float val=1.15,int col=0)
{
    //char *c;
    glPushMatrix();
    glLineWidth(2);

    glTranslatef(-300+4,0,-300);
    glTranslatef(-15+4-2-4+y, 2+13+bridge_val+z,-155);
    glRotatef(184,0,1,0);
    cube(1,col,0,0,1,1);
    glScalef(.004f*val,.004f*val,10);

    for (int c=0; c != str.size(); c++)
    {
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, str[c]);
    }
    glPopMatrix();
    //cout<<spt_cutoff<<" "<<l_height<<endl;
}
char arr11[100];
static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);
    gluPerspective(0,0,0,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, centerX,centerY,centerZ, 0,1,0);

    glRotatef(rot, 0,1,0);

    glPushMatrix();
    glTranslatef(check2,0,check1);
    wall();
    glPushMatrix();
    if(!is_start)
        check1-=.08,check2-=.015;

    glPopMatrix();
    light();

    glPopMatrix();
    glPopMatrix();
    glLineWidth(1);
    stringstream okk;
    okk<<score;
    string str,str1;
    okk>>str;
    okk.clear();
    string str3="";
    for(int i=0; i<life; i++)
    {
        str3+='@';
    }
    glEnable(GL_LINE_SMOOTH);
    str1="       Score:["+str+"]";
    string str2="Life:["+str3+"]";
    //  cout<<arr11<<endl;
    str1=str2+str1;

//over=1;
    //drawStrokeText("Score ",0,0,0);
    // drawStrokeText(arr12,0,0,4);
    if(!view3rd)
    {
        if(!pop)
        {
            if(!over)
            {
                if(!is_start)
                {
                    drawStrokeText(str1,0,0,0);
                    drawStrokeText("Press t,u,space & b for left,right,jump & escape door ",0,8,-.5,1.0,1);

                }
                if(is_start)
                {
                    drawStrokeText("*** Press v for start the game",0,6,-6);
                    //  drawStrokeText("Press 0 for change character name",0,6,-7);
                    drawStrokeText("*** Press Esc for exit game",0,6,-8);
                    drawStrokeText("Maze Runner 3D",0,6,-2,3.0,1);
                }
            }
            else
            {
                str="Score:"+str;
                drawStrokeText("Maze Runner 3D",0,6,-2,3.0,1);
                drawStrokeText("Game Over",0,-1,-5,2.0);
                drawStrokeText(str,0,-1,-7,2.0);
                drawStrokeText("*** Press Esc for exit game",0,6,-9);
            }
        }
    }
    // if(check3<=50)check3=50,check4-=.015;

    //cout<<check3<<endl;
    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y);

static void light14(unsigned char light1, int x, int y)
{

    switch (light1)
    {

    case 27:
        glutKeyboardFunc(key);
        break;
    case '1':
        a12=1-a12;
        break;
    case '2':
        d12=1-d12;
        break;
    case '3':
        s12=1-s12;
        break;
    }

}

static void light24(unsigned char light2, int x, int y)
{
    switch (light2)
    {

    case 27:
        glutKeyboardFunc(key);
        break;
    case '1':
        a22=1-a22;
        break;
    case '2':
        d22=1-d22;
        break;
    case '3':
        s22=1-s22;
        break;
    }
}

static void spot_light14(unsigned char spot_light, int x, int y)
{
    switch (spot_light)
    {

    case 27:
        glutKeyboardFunc(key);
        break;
    case '1':
        a32=1-a32;
        break;
    case '2':
        d32=1-d32;
        break;
    case '3':
        s32=1-s32;
        break;
    }
}

static void spot_light24(unsigned char spot_light, int x, int y)
{
    switch (spot_light)
    {

    case 27:
        glutKeyboardFunc(key);
        break;
    case '1':
        a42=1-a42;
        break;
    case '2':
        d42=1-d42;
        break;
    case '3':
        s42=1-s42;
        break;
    }
}

static void spot_light34(unsigned char spot_light, int x, int y)
{
    switch (spot_light)
    {

    case 27:
        glutKeyboardFunc(key);
        break;
    case '1':
        a52=1-a52;
        break;
    case '2':
        d52=1-d52;
        break;
    case '3':
        s52=1-s52;
        break;
    }
}



static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'q':
        pop=1-pop;
        break;
    case '0':
        view3rd=1-view3rd;
        if(view3rd)
        {
            eyeY=3;
            eyeZ+=4;
            centerX-=8;
            centerY+=10;
            centerZ-=3;
        }
        else
        {
            eyeY=5;
            eyeZ-=4;
            centerX+=8;
            centerY-=10;
            centerZ+=3;
        }
        break;

    case 27:
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
        break;
    case 'v':
        is_start=0;
        //eyeY++;
        break;
    case 'h':
        eyeY--;
        // eyeY--;
        break;

    case 'w':
        //centerX++;
        centerY++;
        //  centerZ++;
        break;
    case 'e':
        //  centerX--;
        centerY--;
        //  centerZ--;
        break;

    case 'o':
        centerX+=2;

        //centerY++;
        //  centerZ++;
        break;
    case 'p':
        centerX-=2;
        //centerY--;
        //  centerZ--;
        break;

    case 'k':
        centerZ++;
        //centerY++;
        //  centerZ++;
        break;
    case 'l':
        centerZ--;
        //centerY--;
        //  centerZ--;
        break;


    case ',':
        rot++;
        break;
    case '.':
        rot--;
        break;



    case '1':
        l_on1=1-l_on1;
        break;
    case '2':
        l_on2=1-l_on2;
        break;

    case '3':
        l_on3=1-l_on3;
        break;
    case '4':
        l_on4=1-l_on4;
        break;
    case '5':
        l_on5=1-l_on5;
        break;
    case '6':
        l_on6=1-l_on6;
        break;
    case '9':
        stop=1-stop;
        break;
    case '7':
        spt_cutoff+=1;
        break;
    case '8':
        spt_cutoff-=1;
        break;

    case ' ':
        if(cnt_dwn==0)
        {
            b=6;
            mark11=1;
        }
        break;
    case 't':
        add_lef+=.2;

        if(add_lef>2)
            add_lef=2;
        break;



    case 'u':
        add_lef-=.2;
        if(add_lef<-3)
            add_lef=-3;
        break;

    case 'b':
        if(c>=-16)
        {
            reset();
            left_turn=1-left_turn;
        }
        break;
    case 'm':
        glutKeyboardFunc(light14);
        break;
    case 'n':
        glutKeyboardFunc(light24);
        break;
    case 'c':
        glutKeyboardFunc(spot_light14);
        break;
    case 'x':
        glutKeyboardFunc(spot_light24);
        break;
    case 'z':
        glutKeyboardFunc(spot_light34);
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
void texture_image()
{
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\brick road1.bmp");//0
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\head.bmp");//1
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\top.bmp");//2
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\brick road.bmp");//3
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\door1.bmp");//4
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\spike.bmp");//5
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\fire.bmp");//6
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\gold.bmp");//7
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\momy.bmp");//8
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\mask.bmp");//9
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\grash.bmp");//10
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\wall2.bmp");//11
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\top2.bmp");//12
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\backwall.bmp");//13
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\laser.bmp");//14
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\flame.bmp");//15
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\rock.bmp");//16
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\face.bmp");//17
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\tatoo.bmp");//18
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\leaf.bmp");//19
    v.push_back(ID);
    LoadTexture("C:\\Users\\Sourav\\Desktop\\ui\\figures\\brunch.bmp");//20
    v.push_back(ID);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(width,height);
    glutInitWindowPosition(550,50);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Maze Runner 3D");
    glutReshapeFunc(res);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);
    glEnable(GL_BLEND);
    glEnable(GL_LINE_SMOOTH);

    glEnable(GL_DEPTH_TEST);
    glShadeModel( GL_SMOOTH );
    glEnable(GL_NORMALIZE);
    glEnable(GL_BLEND);

    glEnable(GL_LIGHTING);
    GLfloat globalAmbient[] = {0.0,0.0,0.0,1.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,globalAmbient);
    texture_image();
    int t=1;
    printf("Warning!!! please turn off caps lock and use shift key before * key and + key.\n");
    printf("%d. Press '1' for alter light1.\n",t++);
    printf("%d. Press '2' for  alter light2.\n",t++);
    printf("%d. Press '4' for  alter spot light1.\n",t++);
    printf("%d. Press '5' for  alter spot light2.\n",t++);
    printf("%d. Press '6' for  alter spot light3.\n",t++);

    printf("%d. Press 'w' for up.\n%d. press 'e' for down.\n%d. press 's' for right.\n%d. press 'a' for left.\n",t+1,t+2,t+3,t+4);
    t+=4;
    printf("%d. Press 'o' to move camera left.\n%d. Press 'p' to move camera right.\n",t+1,t+2);
    t+=2;
    printf("%d. Press '+' to zoom in.\n%d. Press '-' for zoom out.\n",t+1,t+2);
    t+=2;
    printf("%d. Press 'g' for up camera.\n%d. Press 'h' for down camera.\n",t+1,t+2);
    t+=2;
    printf("%d. Press ',' for left rotation.\n%d. Press '.' for right rotation.\n",t+1,t+2);
    t+=2;


    printf("%d. Press 'n' for activate function of light1 and do operations.\n",t++);
    printf("%d. Press 'm' for activate function of light2 and do operations.\n",t++);
    printf("%d. Press 'c' for activate function of spot light1 and do operations.\n",t++);
    printf("%d. Press 'x' for activate function of spot light2 and do operations.\n",t++);
    printf("%d. Press 'z' for activate function of spot light3 and do operations.\n",t++);
    printf("  ***Operations***\n");
    printf("  *** Press '1' for alter ambient light.\n");
    printf("  *** Press '2' for alter diffuse light.\n");
    printf("  *** Press '3' for alter specular light.\n");
    printf("  *** Press ESC for Main Menu.\n");

    printf("%d. Press 'q' for alter rotation around character.\n",t++);
    printf("%d. Press '0' for alter 1st person view.\n",t++);
    printf("%d. Press '9' for alter rotation of character.\n",t++);

    glutMainLoop();

    return EXIT_SUCCESS;
}
