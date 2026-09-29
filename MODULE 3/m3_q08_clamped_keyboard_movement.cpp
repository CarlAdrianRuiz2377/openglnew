#include <GL/freeglut.h>

const float SQUARE_HALF_WIDTH = 0.1f;
const float WINDOW_EDGE_LIMIT = 0.9f;
const float MOVE_STEP = 0.05f;

float squarePositionX = 0.0f;

void clampSquarePosition()
{

    const float maxCenter = WINDOW_EDGE_LIMIT - SQUARE_HALF_WIDTH;
    if (squarePositionX > maxCenter) {
        squarePositionX = maxCenter;
    }
    if (squarePositionX < -maxCenter) {
        squarePositionX = -maxCenter;
    }
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.2f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(squarePositionX - SQUARE_HALF_WIDTH, -SQUARE_HALF_WIDTH);
    glVertex2f(squarePositionX + SQUARE_HALF_WIDTH, -SQUARE_HALF_WIDTH);
    glVertex2f(squarePositionX + SQUARE_HALF_WIDTH, SQUARE_HALF_WIDTH);
    glVertex2f(squarePositionX - SQUARE_HALF_WIDTH, SQUARE_HALF_WIDTH);
    glEnd();
    glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (key == 'a') {
        squarePositionX -= MOVE_STEP;
    }
    else if (key == 'd') {
        squarePositionX += MOVE_STEP;
    }
    else {
        return;
    }
    clampSquarePosition();
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q08 - Clamped Keyboard Movement (a / d)");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyboard);
    glutMainLoop();
    return 0;
}
