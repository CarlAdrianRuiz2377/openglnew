#include <GL/freeglut.h>
#include <cstdio>

char mouseLabel[64] = "Move the mouse over the window";

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.9f, GLUT_BITMAP_HELVETICA_18, mouseLabel);
    glutSwapBuffers();
}

void handlePassiveMotion(int mouseX, int mouseY)
{

    snprintf(mouseLabel, sizeof(mouseLabel), "Mouse at (%d, %d)", mouseX, mouseY);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q10 - Passive Motion Pixel Readout");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutPassiveMotionFunc(handlePassiveMotion);
    glutMainLoop();
    return 0;
}
