#include <GL/freeglut.h>
#include <cstdio>

const int ONE_SECOND_MS = 1000;

int elapsedSeconds = 0;
bool isRunning = false;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 1.0f, 1.0f);

    char label[48];
    snprintf(label, sizeof(label), "Elapsed: %d s", elapsedSeconds);
    drawText(-0.25f, 0.1f, GLUT_BITMAP_TIMES_ROMAN_24, label);

    glColor3f(isRunning ? 0.3f : 1.0f, isRunning ? 1.0f : 0.6f, 0.3f);
    drawText(-0.25f, -0.2f, GLUT_BITMAP_HELVETICA_18,
        isRunning ? "Running (right click to pause)" : "Paused (left click to start)");
    glutSwapBuffers();
}

void updateStopwatch(int value)
{
    (void)value;
    if (isRunning) {
        ++elapsedSeconds;
        glutPostRedisplay();
    }
    glutTimerFunc(ONE_SECOND_MS, updateStopwatch, 0);
}

void handleMouse(int button, int state, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (state != GLUT_DOWN) {
        return;
    }
    if (button == GLUT_LEFT_BUTTON) {
        isRunning = true;
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        isRunning = false;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q17 - Mouse-Controlled Stopwatch");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMouseFunc(handleMouse);
    glutTimerFunc(ONE_SECOND_MS, updateStopwatch, 0);
    glutMainLoop();
    return 0;
}
