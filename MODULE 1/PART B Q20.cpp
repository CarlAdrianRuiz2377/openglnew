#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const int STRIPE_COUNT = 7;

void drawStripes() {
    float stripeHeight = 2.0f / STRIPE_COUNT;

    for (int i = 0; i < STRIPE_COUNT; i++) {
        float y0 = -1.0f + i * stripeHeight;
        float y1 = y0 + stripeHeight;

        if (i % 2 == 0) {
            glColor3f(0.8f, 0.0f, 0.0f);
        } else {
            glColor3f(1.0f, 1.0f, 1.0f);
        }

        glBegin(GL_POLYGON);
            glVertex2f(-1.0f, y0);
            glVertex2f(1.0f, y0);
            glVertex2f(1.0f, y1);
            glVertex2f(-1.0f, y1);
        glEnd();
    }
}

void drawFilledStar(float centerX, float centerY, float outerRadius, float innerRadius) {
    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_POLYGON);
        for (int i = 0; i < 10; i++) {
            float angle = PI / 2 + i * PI / 5;
            float radius = (i % 2 == 0) ? outerRadius : innerRadius;
            glVertex2f(centerX + radius * cosf(angle), centerY + radius * sinf(angle));
        }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    drawStripes();
    drawFilledStar(-0.65f, 0.65f, 0.25f, 0.1f);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Q20 - Procedural Striped Flag with Star");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
