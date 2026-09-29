#include <GL/freeglut.h>

const float SQUARE_HALF_SIZE = 0.1f;

float squarePositionX = 0.0f;
float squarePositionY = 0.0f;
bool isDragging = false;

void convertPixelToGl(int pixelX, int pixelY, float* outX, float* outY)
{
    const int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    const int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
    *outX = (2.0f * pixelX) / windowWidth - 1.0f;
    *outY = 1.0f - (2.0f * pixelY) / windowHeight;
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
    glVertex2f(squarePositionX - SQUARE_HALF_SIZE, squarePositionY - SQUARE_HALF_SIZE);
    glVertex2f(squarePositionX + SQUARE_HALF_SIZE, squarePositionY - SQUARE_HALF_SIZE);
    glVertex2f(squarePositionX + SQUARE_HALF_SIZE, squarePositionY + SQUARE_HALF_SIZE);
    glVertex2f(squarePositionX - SQUARE_HALF_SIZE, squarePositionY + SQUARE_HALF_SIZE);
    glEnd();
    glutSwapBuffers();
}

void handleMouse(int button, int state, int mouseX, int mouseY)
{
    if (button != GLUT_LEFT_BUTTON) {
        return;
    }

    isDragging = (state == GLUT_DOWN);

    if (isDragging) {
        convertPixelToGl(mouseX, mouseY, &squarePositionX, &squarePositionY);
        glutPostRedisplay();
    }
}

void handleMotion(int mouseX, int mouseY)
{
    if (!isDragging) {
        return;
    }
    convertPixelToGl(mouseX, mouseY, &squarePositionX, &squarePositionY);
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Q16 - Click-and-Drag Square");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMouseFunc(handleMouse);
    glutMotionFunc(handleMotion);
    glutMainLoop();
    return 0;
}
