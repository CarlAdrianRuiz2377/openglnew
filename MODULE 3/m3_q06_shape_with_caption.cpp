#include <GL/freeglut.h>

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawTriangle()
{
    glColor3f(1.0f, 0.6f, 0.1f);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.4f, -0.3f);
    glVertex2f(0.4f, -0.3f);
    glVertex2f(0.0f, 0.5f);
    glEnd();
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawTriangle();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.3f, -0.6f, GLUT_BITMAP_HELVETICA_18, "A filled triangle");
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q06 - Shape with Caption");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
