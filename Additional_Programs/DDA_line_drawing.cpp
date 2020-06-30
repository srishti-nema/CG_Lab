#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
double X1,Y1,X2,Y2;
float round_value(float v)
{
    return float(v+0.5);
}
void LineDDA(void)
{
    double dx = (X2-X1);
    double dy = (Y2-Y1);
    double steps;
    float xInc,yInc,x=X1,y=Y1;
    steps = (abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
    xInc = dx/(float)steps;
    yInc = dy/(float)steps;
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2d(x,y);
    int k;
    for(k=0;k<steps;k++)
    {
        x += xInc;
        y += yInc;
        glVertex2d(round_value(x),round_value(y));
    }
    glEnd();
    glFlush();
}
void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glColor3f(0.0,0.0,0.0);
    gluOrtho2D(0,640,0,480);
}
int main(int argc, char** argv)
{
    printf("Enter 2 end points of line to be drawn");
    printf("\n****************");
    printf("\nEnter Point1(x1,y1):\n");
    scanf("%lf%lf",&X1,&Y1);
    printf("\n****************");
    printf("\nEnter Point2(x2,y2): \n");
    scanf("%lf%lf",&X2,&Y2);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(LineDDA);
    glutMainLoop();
}