#include <GL/freeglut.h>

const float LIGHT_GRAY = 0.8f;
const float DARK_GRAY = 0.2f;

float backgroundShade = DARK_GRAY;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClearColor(backgroundShade, backgroundShade, backgroundShade, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    const float textShade = (backgroundShade > 0.5f) ? 0.0f : 1.0f;
    glColor3f(textShade, textShade, textShade);
    drawText(-0.4f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Move the pointer in and out");
    glutSwapBuffers();
}

void handleEntry(int state)
{
    if (state == GLUT_ENTERED) {
        backgroundShade = LIGHT_GRAY;
    }
    else if (state == GLUT_LEFT) {
        backgroundShade = DARK_GRAY;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q11 - Entry-Driven Background");
    glutDisplayFunc(drawScene);
    glutEntryFunc(handleEntry);
    glutMainLoop();
    return 0;
}
