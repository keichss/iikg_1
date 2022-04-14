#include <GL/glew.h>
#include <iostream>
#include <GL/freeglut.h>

static void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT); //очистка буфера кадра
    glutSwapBuffers(); //меняет фоновый буфер и буфер кадра местами
}

static void InitializeGlutCallbacks()
{
    glutDisplayFunc(RenderSceneCB); //отрисовка 1 кадра
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); //инициализируем GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); //GLUT_DOUBLE включает двойную буферизацию и буфер цвета
    glutInitWindowSize(1024, 768); //настройка параметров окна
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chelyshkina Ekaterina Tutorial 01"); //создание окна и заголовка

    InitializeGlutCallbacks();

    glClearColor(1.0f, 0.0f, 0.0f, 0.0f); //устанавливает цвет, который будет использован во время очистки буфера кадра

    glutMainLoop(); //ждёт событий от оконной системы и передаёт их через функции обратного вызова

    return 0;
}