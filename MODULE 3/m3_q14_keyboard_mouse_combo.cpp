#include <GL/freeglut.h> 
const float SHAPE_HALF_SIZE = 0.1f;
const float MOVE_STEP = 0.05f;
const float VERTICAL_LIMIT = 0.9f - SHAPE_HALF_SIZE;

float shapePositionX = 0.0f;
float shapePositionY = 0.0f;

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.9f, 0.4f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(shapePositionX - SHAPE_HALF_SIZE, shapePositionY - SHAPE_HALF_SIZE);
    glVertex2f(shapePositionX + SHAPE_HALF_SIZE, shapePositionY - SHAPE_HALF_SIZE);
    glVertex2f(shapePositionX + SHAPE_HALF_SIZE, shapePositionY + SHAPE_HALF_SIZE);
    glVertex2f(shapePositionX - SHAPE_HALF_SIZE, shapePositionY + SHAPE_HALF_SIZE);
    glEnd();
    glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (key == 'w') {
        shapePositionY += MOVE_STEP;
    }
    else if (key == 's') {
        shapePositionY -= MOVE_STEP;
    }
    else {
        return;
    }

    if (shapePositionY > VERTICAL_LIMIT) shapePositionY = VERTICAL_LIMIT;
    if (shapePositionY < -VERTICAL_LIMIT) shapePositionY = -VERTICAL_LIMIT;

    glutPostRedisplay();
}

void handleMouse(int button, int state, int mouseX, int mouseY)
{
    (void)button;
    (void)mouseX;
    (void)mouseY;

    if (state == GLUT_DOWN) {
        shapePositionX = 0.0f;
        shapePositionY = 0.0f;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Q14 - Keyboard + Mouse Combo (w / s, click resets)");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyboard);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
