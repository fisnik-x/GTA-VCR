#include "../include/ViceCityRadio.h"

ViceCityRadio::ViceCityRadio(){
	glfwInit();
	glfwWindowHint(GLFW_CENTER_CURSOR, GL_TRUE);
	glfwWindowHint(GLFW_FOCUSED, GLFW_FALSE);
	glfwWindowHint(GLFW_AUTO_ICONIFY, GL_FALSE);
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	glfwWindowHint(GLFW_DECORATED, GL_FALSE);
}

ViceCityRadio::~ViceCityRadio(){
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void ViceCityRadio::Run(){
	m_video = glfwGetVideoMode(glfwGetPrimaryMonitor());
	glfwSwapInterval(1);
	m_window = glfwCreateWindow(
		m_video->width,
		m_video->height,
		"Video Game Radio", 
		glfwGetPrimaryMonitor(), nullptr);
	
	if (!m_window) {
		glfwTerminate();
	}

	glfwSetWindowUserPointer(m_window, this);
	glfwSetKeyCallback(m_window, 
	[](GLFWwindow* window, int key, int scancode, int action, int mods){
		if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
			
		}
	});
    glfwSetWindowAspectRatio(m_window, 16, 9);
    glfwMakeContextCurrent(m_window);

    GLfloat color[]{ rgb2f(0), rgb2f(170), rgb2f(170) };
	float pos[2][2] = { {0.0f, -1.0f},{0.0f, 1.0f} };
	float dim[2] = { 1.0f, 0.1f };

	GLfloat obj_color[]{ rgb2f(0), rgb2f(0), rgb2f(0) };
	float obj_pos[2][2] = { {0.0f, 1.0f}, {1.0f, 0.0f} };
	float obj_dim[2] = { 1.0f, 0.1f };

    while (!glfwWindowShouldClose(m_window)){
        glClearColor(rgb2f(105), rgb2f(96), rgb2f(219), 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_QUADS);
			glColor3fv(color);
			glVertex2f(pos[0][0] - dim[0], pos[0][1] - dim[1]);
			glVertex2f(pos[0][0] + dim[0], pos[0][1] - dim[1]);
			glVertex2f(pos[0][0] + dim[0], pos[0][1] + dim[1]);
			glVertex2f(pos[0][0] - dim[0], pos[0][1] + dim[1]);
		glEnd();
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glLoadIdentity();
		glBegin(GL_QUADS);
			glColor3fv(obj_color);
			glVertex2f(obj_pos[0][0] - obj_dim[0], obj_pos[0][1] - obj_dim[1]);
			glVertex2f(obj_pos[0][0] + obj_dim[0], obj_pos[0][1] - obj_dim[1]);
			glVertex2f(obj_pos[0][0] + obj_dim[0], obj_pos[0][1] + obj_dim[1]);
			glVertex2f(obj_pos[0][0] - obj_dim[0], obj_pos[0][1] + obj_dim[1]);
		glEnd();
		glPopMatrix();

		glfwSwapBuffers(m_window);
        glfwPollEvents();
    }
}