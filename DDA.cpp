#include <GL/gl.h>
#include <GL/glut.h>

float x1, y_start, x2, y2, m, dx, dy;

void display(void)
{
    
    glClear (GL_COLOR_BUFFER_BIT);
    glEnd();

    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);

    if(m <0)
    {
        while(x1 <= x2 && y_start <= y2)
        {
            x1 = x1 + 1;
            y_start = y_start + m;
            glVertex3f(x1/100, y_start/100, 0.0);
        }
    }
    else if(m >=0)
    {
        while(x1 <= x2 && y_start <= y2)
        {
            x1 = x1 + (1/m);
            y_start = y_start + 1;
            glVertex3f(x1/100, y_start/100, 0.0);
        }
    }
    

    glEnd();

   
    glFlush ();
}

void init (void)
{
   
    glClearColor (0.0, 0.0, 0.0, 0.0);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    x1 = 1 ; 
    x2 = 10 ;
    y_start = 2 ;
    y2 = 12 ;
    dx = x2 - x1;
    dy = y2 - y_start;
    m = dy/dx;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
glutDisplayFunc(display);
glutMainLoop();
return 0; 
}
