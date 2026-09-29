#include <GL/freeglut.h> 

const char* const DISPLAY_NAME = "Carl Adrian L. Ruiz";

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.1f, 0.0f, GLUT_BITMAP_HELVETICA_18, DISPLAY_NAME);

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q01 - Display Your Name");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMainLoop();
    return 0;
}
