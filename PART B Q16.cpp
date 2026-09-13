#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;
const float BALL_RADIUS = 0.08f;

float ballX = 0.0f;
float ballY = 0.0f;
float dx = 0.02f;
float dy = 0.015f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(ballX, ballY);
        for (int i = 0; i <= 30; i++) {
            float angle = 2.0f * PI * i / 30;
            glVertex2f(ballX + BALL_RADIUS * cosf(angle), ballY + BALL_RADIUS * sinf(angle));
        }
    glEnd();

    glFlush();
}

void idle() {
    ballX += dx;
    ballY += dy;

    if (ballX + BALL_RADIUS > 1.0f || ballX - BALL_RADIUS < -1.0f) dx = -dx;
    if (ballY + BALL_RADIUS > 1.0f || ballY - BALL_RADIUS < -1.0f) dy = -dy;

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q16 - Bouncing Ball");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}
