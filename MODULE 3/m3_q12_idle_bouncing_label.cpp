#include <GL/freeglut.h>

const char* const LABEL_TEXT = "Bounce!";
void* const LABEL_FONT = GLUT_BITMAP_HELVETICA_18;

float labelPositionX = -0.5f;
float labelSpeed = 0.8f;
int previousTimeMs = 0;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

float measureLabelWidth()
{

    const int textPixels = glutBitmapLength(LABEL_FONT, (const unsigned char*)LABEL_TEXT);
    return (2.0f * textPixels) / glutGet(GLUT_WINDOW_WIDTH);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.9f, 0.2f);
    drawText(labelPositionX, 0.0f, LABEL_FONT, LABEL_TEXT);
    glutSwapBuffers();
}

void updateAnimation()
{

    const int currentTimeMs = glutGet(GLUT_ELAPSED_TIME);
    const float deltaSeconds = (currentTimeMs - previousTimeMs) / 1000.0f;
    previousTimeMs = currentTimeMs;

    labelPositionX += labelSpeed * deltaSeconds;

    const float leftEdge = -1.0f;
    const float rightEdge = 1.0f - measureLabelWidth();
    if (labelPositionX >= rightEdge) {
        labelPositionX = rightEdge;
        labelSpeed = -labelSpeed;
    }
    else if (labelPositionX <= leftEdge) {
        labelPositionX = leftEdge;
        labelSpeed = -labelSpeed;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q12 - Idle-Driven Bouncing Label");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    previousTimeMs = glutGet(GLUT_ELAPSED_TIME);
    glutDisplayFunc(drawScene);
    glutIdleFunc(updateAnimation);
    glutMainLoop();
    return 0;
}
