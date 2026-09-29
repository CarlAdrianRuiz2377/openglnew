#include <GL/freeglut.h>
#include <cmath>
#include <cstdio>

const float BASE_SIZE = 0.08f;
const float PULSE_AMPLITUDE = 0.03f;
const float PULSE_SPEED_RADIANS = 3.0f;

float markerX = 0.0f;
float markerY = 0.0f;
float pulseAngle = 0.0f;
int previousTimeMs = 0;
char hoverLabel[64] = "Hover: (0.00, 0.00)";

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void toGL(int pixelX, int pixelY, float* outX, float* outY)
{
    const int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    *outX = (2.0f * pixelX) / windowWidth - 1.0f;
    *outY = 1.0f - (2.0f * pixelY) / windowHeight;
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    const float size = BASE_SIZE + PULSE_AMPLITUDE * std::sin(pulseAngle);
    glColor3f(0.2f, 0.9f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(markerX - size, markerY - size);
    glVertex2f(markerX + size, markerY - size);
    glVertex2f(markerX + size, markerY + size);
    glVertex2f(markerX - size, markerY + size);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(markerX + BASE_SIZE + PULSE_AMPLITUDE + 0.02f, markerY - 0.02f,
        GLUT_BITMAP_HELVETICA_18, "Marker");

    drawText(-0.95f, 0.9f, GLUT_BITMAP_HELVETICA_18, hoverLabel);
    glutSwapBuffers();
}

void handleMouse(int button, int state, int mouseX, int mouseY)
{
    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) {
        return;
    }
    toGL(mouseX, mouseY, &markerX, &markerY);
    glutPostRedisplay();
}

void handlePassiveMotion(int mouseX, int mouseY)
{
    float glX = 0.0f;
    float glY = 0.0f;
    toGL(mouseX, mouseY, &glX, &glY);
    snprintf(hoverLabel, sizeof(hoverLabel), "Hover: (%.2f, %.2f)", glX, glY);
    glutPostRedisplay();
}

void updateAnimation()
{
    const int currentTimeMs = glutGet(GLUT_ELAPSED_TIME);
    const float deltaSeconds = (currentTimeMs - previousTimeMs) / 1000.0f;
    previousTimeMs = currentTimeMs;

    pulseAngle += PULSE_SPEED_RADIANS * deltaSeconds;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Q20 - Interactive Text Placer (click to move)");
    glClearColor(0.05f, 0.05f, 0.1f, 1.0f);
    previousTimeMs = glutGet(GLUT_ELAPSED_TIME);
    glutDisplayFunc(drawScene);
    glutMouseFunc(handleMouse);
    glutPassiveMotionFunc(handlePassiveMotion);
    glutIdleFunc(updateAnimation);
    glutMainLoop();
    return 0;
}
