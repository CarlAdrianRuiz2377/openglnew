#include <GL/freeglut.h>
#include <cstdio>

float cursorGlX = 0.0f;
float cursorGlY = 0.0f;
bool hasDragged = false;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

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
    glColor3f(1.0f, 1.0f, 1.0f);

    if (hasDragged) {
        char label[64];
        snprintf(label, sizeof(label), "GL coords: (%.2f, %.2f)", cursorGlX, cursorGlY);
        drawText(-0.95f, 0.9f, GLUT_BITMAP_HELVETICA_18, label);
    }
    else {
        drawText(-0.95f, 0.9f, GLUT_BITMAP_HELVETICA_18, "Hold a mouse button and drag");
    }
    glutSwapBuffers();
}

void handleMotion(int mouseX, int mouseY)
{
    convertPixelToGl(mouseX, mouseY, &cursorGlX, &cursorGlY);
    hasDragged = true;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q09 - Active Motion Coordinates");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMotionFunc(handleMotion);
    glutMainLoop();
    return 0;
}
