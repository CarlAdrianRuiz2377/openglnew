#include <GL/freeglut.h>

enum ButtonMessage { MESSAGE_NONE, MESSAGE_LEFT, MESSAGE_RIGHT };

ButtonMessage currentMessage = MESSAGE_NONE;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (currentMessage == MESSAGE_LEFT) {
        glColor3f(0.0f, 1.0f, 0.0f);
        drawText(-0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Left button text");
    }
    else if (currentMessage == MESSAGE_RIGHT) {
        glColor3f(1.0f, 0.0f, 0.0f);
        drawText(-0.3f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Right button text");
    }
    glutSwapBuffers();
}

void handleMouse(int button, int state, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (state != GLUT_DOWN) {
        return;
    }
    if (button == GLUT_LEFT_BUTTON) {
        currentMessage = MESSAGE_LEFT;
    }
    else if (button == GLUT_RIGHT_BUTTON) {
        currentMessage = MESSAGE_RIGHT;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 400);
    glutCreateWindow("Q05 - Mouse Button Text Color");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
