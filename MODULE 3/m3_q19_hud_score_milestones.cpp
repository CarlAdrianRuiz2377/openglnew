#include <GL/freeglut.h>
#include <cstdio>

const int POINTS_PER_STAGE = 5;
const int STAGE_COUNT = 5;

const float STAGE_COLORS[STAGE_COUNT][3] = {
    { 0.8f, 0.1f, 0.1f },
    { 0.1f, 0.5f, 0.8f },
    { 0.1f, 0.6f, 0.2f },
    { 0.6f, 0.2f, 0.7f },
    { 0.8f, 0.4f, 0.0f }
};

int score = 0;
int colorStage = 0;

void drawText(float positionX, float positionY, void* font, const char* text)
{
    glRasterPos2f(positionX, positionY);
    glutBitmapString(font, (const unsigned char*)text);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3fv(STAGE_COLORS[colorStage]);
    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.4f);
    glVertex2f(0.5f, -0.4f);
    glVertex2f(0.5f, 0.4f);
    glVertex2f(-0.5f, 0.4f);
    glEnd();

    char label[32];
    snprintf(label, sizeof(label), "Score: %d", score);
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(-0.15f, 0.0f, GLUT_BITMAP_TIMES_ROMAN_24, label);
    glutSwapBuffers();
}

void handleMouse(int button, int state, int mouseX, int mouseY)
{
    (void)mouseX;
    (void)mouseY;

    if (button != GLUT_LEFT_BUTTON || state != GLUT_DOWN) {
        return;
    }

    ++score;
    colorStage = (score / POINTS_PER_STAGE) % STAGE_COUNT;
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Q19 - HUD Score (left click)");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(drawScene);
    glutMouseFunc(handleMouse);
    glutMainLoop();
    return 0;
}
