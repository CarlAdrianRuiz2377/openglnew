#include <GL/freeglut.h>
#include <cmath>

const float ORBIT_RADIUS = 0.6f;
const float ORBIT_SPEED_RADIANS = 2.0f;
const float SHAPE_HALF_SIZE = 0.08f;

bool isInside = false;
float orbitAngle = 0.0f;
int previousTimeMs = 0;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    const float shapeX = ORBIT_RADIUS * std::cos(orbitAngle);
    const float shapeY = ORBIT_RADIUS * std::sin(orbitAngle);

    glColor3f(1.0f, 0.5f, 0.1f);
    glBegin(GL_QUADS);
    glVertex2f(shapeX - SHAPE_HALF_SIZE, shapeY - SHAPE_HALF_SIZE);
    glVertex2f(shapeX + SHAPE_HALF_SIZE, shapeY - SHAPE_HALF_SIZE);
    glVertex2f(shapeX + SHAPE_HALF_SIZE, shapeY + SHAPE_HALF_SIZE);
    glVertex2f(shapeX - SHAPE_HALF_SIZE, shapeY + SHAPE_HALF_SIZE);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.95f, 0.9f, GLUT_BITMAP_HELVETICA_18,
        isInside ? "Pointer inside: animating" : "Pointer outside: frozen");
    glutSwapBuffers();
}

void handleEntry(int state)
{
    isInside = (state == GLUT_ENTERED);
    glutPostRedisplay();
}

void updateAnimation()
{

    const int currentTimeMs = glutGet(GLUT_ELAPSED_TIME);
    const float deltaSeconds = (currentTimeMs - previousTimeMs) / 1000.0f;
    previousTimeMs = currentTimeMs;

    if (!isInside) {
        return;
    }
    orbitAngle += ORBIT_SPEED_RADIANS * deltaSeconds;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q18 - Entry + Idle Freeze Combo");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    previousTimeMs = glutGet(GLUT_ELAPSED_TIME);
    glutDisplayFunc(drawScene);
    glutEntryFunc(handleEntry);
    glutIdleFunc(updateAnimation);
    glutMainLoop();
    return 0;
}
