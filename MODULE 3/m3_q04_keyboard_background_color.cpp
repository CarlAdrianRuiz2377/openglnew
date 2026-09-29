#include <GL/freeglut.h>

float backgroundRed = 0.0f;
float backgroundGreen = 0.0f;
float backgroundBlue = 0.0f;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{

    glClearColor(backgroundRed, backgroundGreen, backgroundBlue, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.35f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Press r, g or b");
    glutSwapBuffers();
}

void handleKeyboard(unsigned char key, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (key == 'r') {
        backgroundRed = 1.0f; backgroundGreen = 0.0f; backgroundBlue = 0.0f;
    }
    else if (key == 'g') {
        backgroundRed = 0.0f; backgroundGreen = 1.0f; backgroundBlue = 0.0f;
    }
    else if (key == 'b') {
        backgroundRed = 0.0f; backgroundGreen = 0.0f; backgroundBlue = 1.0f;
    }
    else {
        return;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q04 - Keyboard Background Color");
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(handleKeyboard);
    glutMainLoop();
    return 0;
}
