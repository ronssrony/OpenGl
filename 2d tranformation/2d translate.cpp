#include <GL/glut.h>

void init(void)
{
    
    glClearColor(0.0, 0.0, 0.0, 0.0);

    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void display(void)
{
    
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0, 0.0, 0.0);

    glTranslatef(-.5,0,0) ;//changing the value of Tx and Ty value to translate the triangle;
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, 0.5);
    glEnd();

    
    glFlush();
}

int main(int argc, char** argv)
{
   
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle");

    
    init();

    
    glutDisplayFunc(display);

    
    glutMainLoop();

    return 0;
}
