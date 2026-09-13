#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
int activeLight = 0;

void drawLightCircle(float centerY, float r, float g, float b, bool isActive) {
    float brightness = isActive ? 1.0f : 0.3f;
    glColor3f(r * brightness, g * brightness, b * brightness);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, centerY);
        for (int i = 0; i <= 30; i++) {
            float angle = 2.0f * PI * i / 30;
            glVertex2f(0.2f * cosf(angle), centerY + 0.2f * sinf(angle));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f, -0.9f);
        glVertex2f(0.35f, -0.9f);
        glVertex2f(0.35f, 0.9f);
        glVertex2f(-0.35f, 0.9f);
    glEnd();

    drawLightCircle(0.6f, 1.0f, 0.0f, 0.0f, activeLight == 0);
    drawLightCircle(0.0f, 1.0f, 1.0f, 0.0f, activeLight == 1);
    drawLightCircle(-0.6f, 0.0f, 1.0f, 0.0f, activeLight == 2);

    glFlush();
}

void handleKeyboard(unsigned char key, int x, int y) {
    if (key == 'n') {
        activeLight = (activeLight + 1) % 3;
        glutPostRedisplay();
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 700);
    glutCreateWindow("Q17 - Traffic Light Simulator");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutMainLoop();
    return 0;
}
