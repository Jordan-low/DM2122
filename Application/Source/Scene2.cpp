#include "Scene2.h"
#include "GL\glew.h"
#include "Mtx44.h"
#include "shader.hpp"
#include "Application.h"

Scene2 c;
Scene2 c2;
Scene2::Scene2()
{
}

Scene2::~Scene2()
{
}

void Scene2::Init()
{
	srand(time(0));
	test = 10;
	test1 = 10;
	test2 = 10;
	rotateAngle = 0;
	translateX = 0;
	translateY = 0;
	translateY1 = 0;
	translateY2 = 0;
	scaleAll = 0;
	translateDir = -1;
	rotateDir = 1;
	scaleDir = 1;
	// Init VBO here
	//Set bg colour to dark blue
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//generate buffers
	glGenBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glGenBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);

	//an array of 3 vectors wich represents 3 vertices
	static const GLfloat vertex_buffer_data[] = {
		0.0f, 0.0f, 0.0f,
		0.2f, 0.32f, 0.0f,
		-0.20f, 0.32f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-0.2f, 0.32f, 0.0f,
		-0.35f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-0.35f, 0.0f, 0.0f,
		-0.35f, -0.35f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-0.35f, -0.35f, 0.0f,
		-0.2f, -0.65f, 0.0f,
		0.0f, 0.0f, 0.0f,
		-0.2f, -0.65f, 0.0f,
		0.2f, -0.65f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.2f, -0.65f, 0.0f,
		0.35f, -0.35f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.35f, -0.35f, 0.0f,
		0.35f, 0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.35f, 0.0f, 0.0f,
		0.2f, 0.32f, 0.0f,
	};
	static const GLfloat color_buffer_data[] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};


	static const GLfloat vertex_buffer_data2[] = {
		0.0f, 0.0f, 0.0f,
		3.0f, 3.0f, 0.0f,
		-3.0f, 3.0f, 0.0f,

		-1.5f, -1.5f, 0.0f,
		1.0f, 1.0f, 0.0f,
		0.0f, 5.0f, 0.0f,

		1.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f,
		1.5f, -1.5f, 0.0f,
		/*
		0.0f, 0.0f, 0.0f,
		0.15f, 0.3f, 0.0f,
		-0.15f, 0.3f, 0.0f,

		
		0.0f, 0.0f, 0.0f,
		-0.15f, 0.3f, 0.0f,
		-0.3f, 0.0f, 0.0f,
		
		0.0f, 0.0f, 0.0f,
		-0.3f, 0.0f, 0.0f,
		-0.3f, -0.3f, 0.0f,

		0.0f, 0.0f, 0.0f,
		-0.3f, -0.3f, 0.0f,
		-0.15f, -0.6f, 0.0f,

		0.0f, 0.0f, 0.0f,
		-0.15f, -0.6f, 0.0f,
		0.15f, -0.6f, 0.0f,

		0.0f, 0.0f, 0.0f,
		0.15f, -0.6f, 0.0f,
		0.3f, -0.3f, 0.0f,

		0.0f, 0.0f, 0.0f,
		0.3f, -0.3f, 0.0f,
		0.3f, 0.0f, 0.0f,

		0.0f, 0.0f, 0.0f,
		0.3f, 0.0f, 0.0f,
		0.15f, 0.3f, 0.0f

		/* shape
		0.0f, 0.1f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,

		0.0f, -0.1f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,

		-0.1f, 0.0f, 0.0f,
		-0.5f, 0.4f, 0.0f,
		-0.5f, -0.4f, 0.0f,

		0.1f, 0.0f, 0.0f,
		0.5f, 0.4f, 0.0f,
		0.5f, -0.4f, 0.0f
		*/
	};

	static const GLfloat color_buffer_data2[] = {
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,
		1.0f, 0.0f, 0.0f
	};

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data), color_buffer_data, GL_STATIC_DRAW);
	// set the current active buffer
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	// transfer vertices to OpenGL
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data), vertex_buffer_data, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(color_buffer_data2), color_buffer_data2, GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer_data2), vertex_buffer_data2, GL_STATIC_DRAW);

	//Load vertex and fragment shaders
	m_programID = LoadShaders(
		"Shader//TransformVertexShader.vertexshader",
		"Shader//SimpleFragmentShader.fragmentshader");
	// use our shader
	glUseProgram(m_programID);
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
}

void Scene2::Update(double dt)
{
	/*
	if (Application::IsKeyPressed(VK_SPACE))
	{
		rotateAngle += (float)(rotateDir * 10 * dt);
		translateX += (float)(translateDir * 10 * dt);
		translateY += (float)(translateDir * 10 * dt);
		scaleAll += (float)(scaleDir * 2 * dt);
	}
	*/
	rotateAngle += (float)(rotateDir * 100 * dt);
	//translateX += (float)(translateDir * 10 * dt);
	translateY += (float)(translateDir * test * dt);
	translateY1 += (float)(translateDir * test1 * dt);
	translateY2 += (float)(translateDir * test2 * dt);
	scaleAll += (float)(scaleDir * 2 * dt);
	
	/*
	if (translateX > 10)
		translateDir = -1;
	else if (translateX < -8)
		translateDir = 1;
			else if (translateX < -35)
		translateDir = -1;*/
	if (translateY < -12)
	{
		test = rand() % 20 + 5;
		translateY = 12;
	}
	if (translateY1 < -12)
	{
		test1 = rand() % 20 + 5;
		translateY1 = 12;
	}
	if (translateY2 < -12)
	{
		test2 = rand() % 20 + 5;
		translateY2 = 12;
	}

	if (rotateAngle > 360)
		rotateDir = -1;
	else if (rotateAngle < 0)
		rotateDir = 1;
	if (scaleAll > 10)
		scaleDir = -1;
	else if (scaleAll > 10)
		scaleDir = 1;
}

void Scene2::Render()
{
	Mtx44 translate, rotate, scale;
	Mtx44 model;
	Mtx44 view;
	Mtx44 projection;
	Mtx44 MVP;

	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);

	scale.SetToScale(1, 1, 1);
	rotate.SetToRotation(0, 0, 0, 1);
	translate.SetToTranslation(1, 1, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	// Render VBO here6
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0); // 1st attribute buffer : vertices
	glEnableVertexAttribArray(1); // 2nd attribute buffer : colors

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//first oct
	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);
	scale.SetToScale(2, 2, 2);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(1, translateY, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	//c.hi(rotateAngle, 3, translateY);
	glDrawArrays(GL_TRIANGLES, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle

	//second oct
	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);
	scale.SetToScale(2, 2, 2);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(-5, translateY1, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	glDrawArrays(GL_TRIANGLES, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle

	//third oct
	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);
	scale.SetToScale(2, 2, 2);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(5, translateY2, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	glDrawArrays(GL_TRIANGLES, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//first star
	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);
	scale.SetToScale(0.3, 0.3 , 0.3);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(-8, translateY, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	glDrawArrays(GL_TRIANGLES, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle
	
	//second star
	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);
	scale.SetToScale(0.4, 0.4, 0.4);
	rotate.SetToRotation(rotateAngle, 0, 0, 1);
	translate.SetToTranslation(8, translateY2, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	glDrawArrays(GL_TRIANGLES, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle


	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	//GL_LINE_STRIP
}

void Scene2::Exit()
{
	// Cleanup VBO here
	glDeleteBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glDeleteBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}

void Scene2::hi(int a, int b, int c)
{
	Mtx44 translate, rotate, scale;
	Mtx44 model;
	Mtx44 view;
	Mtx44 projection;
	Mtx44 MVP;

	translate.SetToIdentity();
	rotate.SetToIdentity();
	scale.SetToIdentity();
	model.SetToIdentity();
	view.SetToIdentity();

	projection.SetToOrtho(-10, 10, -10, 10, -10, 10);

	scale.SetToScale(1, 1, 1);
	rotate.SetToRotation(a, 0, 0, 1);
	translate.SetToTranslation(b, c, 1);
	model = translate * rotate * scale;
	MVP = projection * view * model;
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
}
