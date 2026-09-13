#include <GL/glut.h>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int COLOR_COUNT = 6;
float presetColors[COLOR_COUNT][3] = {
    {1.0f, 0.0f, 0.0f},
    {0.0f, 1.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {1.0f, 1.0f, 0.0f},
    {1.0f, 0.0f, 1.0f},
    {0.0f, 1.0f, 1.0f}
};
string colorNames[COLOR_COUNT] = {"Red", "Green", "Blue", "Yellow", "Magenta", "Cyan"};

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

void handleKeyboard(unsigned char key, int x, int y) {
    if (key >= '1' && key <= '6') {
        int index = key - '1';
        glClearColor(presetColors[index][0], presetColors[index][1], presetColors[index][2], 1.0f);
        cout << "Selected color: " << colorNames[index] << endl;
        glutPostRedisplay();
    } else if (key == 27) {
        exit(0);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Q19 - Keyboard Color Picker");
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeyboard);
    glutMainLoop();
    return 0;
}
