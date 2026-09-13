#include <GL/glut.h>

float squareCenterX = 0.0f;
float squareCenterY = 0.0f;
const float HALF_SIZE = 0.1f;
const float MOVE_STEP = 0.05f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);
        glVertex2f(squareCenterX - HALF_SIZE, squareCenterY - HALF_SIZE);
        glVertex2f(squareCenterX + HALF_SIZE, squareCenterY - HALF_SIZE);
        glVertex2f(squareCenterX + HALF_SIZE, squareCenterY + HALF_SIZE);
        glVertex2f(squareCenterX - HALF_SIZE, squareCenterY + HALF_SIZE);
    glEnd();

    glFlush();
}

void clampPosition() {
    float limit = 1.0f - HALF_SIZE;
    if (squareCenterX > limit) squareCenterX = limit;
    if (squareCenterX < -limit) squareCenterX = -limit;
    if (squareCenterY > limit) squareCenterY = limit;
    if (squareCenterY < -limit) squareCenterY = -limit;
}

void handleSpecialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_LEFT) squareCenterX -= MOVE_STEP;
    if (key == GLUT_KEY_RIGHT) squareCenterX += MOVE_STEP;
    if (key == GLUT_KEY_UP) squareCenterY += MOVE_STEP;
    if (key == GLUT_KEY_DOWN) squareCenterY -= MOVE_STEP;

    clampPosition();
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q15 - Move a Square with Arrow Keys");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeys);
    glutMainLoop();
    return 0;
}
