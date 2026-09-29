#include <GL/freeglut.h>
#include <cstdio>

const int COUNTDOWN_START_SECONDS = 30;
const int ONE_SECOND_MS = 1000;

int secondsRemaining = COUNTDOWN_START_SECONDS;
bool isTimeUp = false;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (isTimeUp) {
        glColor3f(1.0f, 0.2f, 0.2f);
        drawText(-0.2f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, "Time's up!");
    }
    else {
        char label[32];
        snprintf(label, sizeof(label), "Time left: %d", secondsRemaining);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawText(-0.25f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, label);
    }
    glutSwapBuffers();
}

void updateCountdown(int value)
{
    (void)value;
    --secondsRemaining;

    if (secondsRemaining > 0) {

        glutTimerFunc(ONE_SECOND_MS, updateCountdown, 0);
    }
    else {
        secondsRemaining = 0;
        isTimeUp = true;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q15 - 30-Second Countdown Timer");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutTimerFunc(ONE_SECOND_MS, updateCountdown, 0);
    glutMainLoop();
    return 0;
}
