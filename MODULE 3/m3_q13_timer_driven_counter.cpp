#include <GL/freeglut.h>
#include <cstdio>

const int ONE_SECOND_MS = 1000;

int secondsCounter = 0;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    char label[32];
    snprintf(label, sizeof(label), "Counter: %d", secondsCounter);
    drawText(-0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, label);
    glutSwapBuffers();
}

void updateCounter(int value)
{
    (void)value;
    ++secondsCounter;
    glutPostRedisplay();

    glutTimerFunc(ONE_SECOND_MS, updateCounter, 0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q13 - Timer-Driven Counter");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutTimerFunc(ONE_SECOND_MS, updateCounter, 0);
    glutMainLoop();
    return 0;
}
