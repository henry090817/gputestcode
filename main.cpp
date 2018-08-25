#include <GL/glut.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);//set background color;
    glMatrixMode(GL_PROJECTION);//switch to the project matrix;
    glOrtho(-5, 5, -5, 5, 5, 15);//glOrtho(left, right, bottom, top, near, far)  coordinates position
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
    return;
}

void display1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0, 0);
    glutWireTeapot(3);
    glFlush();

    return;
}

void piont(void)
{
    glPointSize(5);//在绘制之前要设置要相关参数，这里设置点的大小为5像素
    glBegin(GL_POINTS);
    {
        glVertex2f(0.0f, 0.0f); //OpenGl内的点是齐次坐标的四元组，缺省的z坐标为0.0f，w为1.0f，所以该点为(1, 2, 0, 1)
        glVertex2f(0.0f, 0.5f); //绘制的第二个点
        glVertex2f(0.5f, 0.25f); //绘制的第三个点
    }
    glEnd();

    glFlush();//glFlush，保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）
}

void line(void)
{
    //在绘制之前要设置要相关参数，这里设置点的大小为5像素
    glPointSize(5);
    glBegin(GL_POINTS);
    {
        glVertex2f(0.5f, 0.5f); //OpenGl内的点是齐次坐标的四元组，缺省的z坐标为0.0f，w为1.0f，所以该点为(1, 2, 0, 1)
        glVertex2f(0.0f, 0.5f); //绘制的第二个点
        glVertex2f(0.5f, 0.25f); //绘制的第三个点
    }
    glEnd();

   //设定当前绘制的颜色模式为绿色

    //接下来在绿色模式下绘制正方形，采用线段连接方式
    glLineWidth(2);
    glColor3f(0,1,1);
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(-0.5,-0.5);
        glVertex2f(-0.5,0.5);
        glVertex2f(0.5,0.5);
        glVertex2f(0.5,-0.5);
    }
    glEnd();
    glLineWidth(2);
    //更换当前绘制颜色模式为红色
    glColor3f(1,0,0);
    //接下来在红色模式下绘制正方形
    glBegin(GL_LINE_LOOP);
    {
        glVertex2f(-0.2,-0.2);
        glVertex2f(-0.2,0.2);
        glVertex2f(0.2,0.2);
        glVertex2f(0.2,-0.2);
    }
    glEnd();
    /*同样用5个点，画出不同类型的线段组合*/
    //独立线段，5个点能画出2条线段

    glFlush();//保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);//init GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);//set display mode
    glutInitWindowPosition(0, 0);//set display position
    glutInitWindowSize(300, 300);//set window size
    glutCreateWindow("OpenGL 3D View");//window name
    init();
    glutDisplayFunc(display1);
    glutMainLoop();


    glPointSize(5);//在绘制之前要设置要相关参数，这里设置点的大小为5像素
    glBegin(GL_POINTS);
    {
        glVertex2f(0.0f, 0.0f); //OpenGl内的点是齐次坐标的四元组，缺省的z坐标为0.0f，w为1.0f，所以该点为(1, 2, 0, 1)
        glVertex2f(0.0f, 0.5f); //绘制的第二个点
        glVertex2f(0.5f, 0.25f); //绘制的第三个点
    }
    glEnd();

    glFlush();//glFlush，保证前面的OpenGL命令立即执行（而不是让它们在缓冲区中等待）

  /*  glutInit(&argc, argv);  //对GLUT进行初始化,必须一开始就初始化
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);  //设置显示方式，参数之后再解释
    glutInitWindowPosition(100, 100);  //设置程序窗口在屏幕中的位置
    glutInitWindowSize(400, 600);  //设置程序窗口的大小
    glutCreateWindow("第一个OpenGL程序");  //给程序窗口添加标题
    glutDisplayFunc(&line);  //*调用我们自己的绘图函数来绘制
    glutMainLoop();  //启动消息循环后程序运行起来*/

    return 0;
}