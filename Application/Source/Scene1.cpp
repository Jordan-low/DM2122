#include "Scene1.h"
#include "GL\glew.h"

#include "shader.hpp"


Scene1::Scene1()
{
}

Scene1::~Scene1()
{
}

void Scene1::Init()
{
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
		0.3f, 0.3f, 0.0f,
		-0.3f, 0.3f, 0.0f,

		-0.15f, -0.15f, 0.0f,
		0.1f, 0.1f, 0.0f,
		0.0f, 0.5f, 0.0f,

		0.1f, 0.1f, 0.0f,
		0.0f, 0.0f, 0.0f,
		0.15f, -0.15f, 0.0f,
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
		





		/* marie code
		0.0f, 0.0f, 0.0f,
		-0.1f, 0.6f, 0.0f,
		-0.5f, 0.75f, 0.0f
		-0.8f, 0.4f, 0.0f,
		0.0f, -0.9f, 0.0f,
		0.8f, 0.4f, 0.0f,
		0.5f, 0.75f, 0.0f,
		0.1f, 0.6f, 0.0f,
		0.0f, 0.0f, 0.0f
		*/
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
		"Shader//SimpleVertexShader.vertexshader",
		"Shader//SimpleFragmentShader.fragmentshader");
	// use our shader
	glUseProgram(m_programID);

}

void Scene1::Update(double dt)
{
}

void Scene1::Render()
{
	// Render VBO here6
	glClear(GL_COLOR_BUFFER_BIT);
	glEnableVertexAttribArray(0); // 1st attribute buffer : vertices
	glEnableVertexAttribArray(1); // 2nd attribute buffer : colors

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_1]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//glDrawArrays(GL_TRIANGLE_STRIP, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glBindBuffer(GL_ARRAY_BUFFER, m_colorBuffer[GEO_TRIANGLE_2]);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	//draw the triangle
	glDrawArrays(GL_TRIANGLES, 0, 24); // starting from vertex 0; 3 vertices = 1 triangle

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);

	//GL_LINE_STRIP
}

void Scene1::Exit()
{
	// Cleanup VBO here
	glDeleteBuffers(NUM_GEOMETRY, &m_vertexBuffer[0]);
	glDeleteBuffers(NUM_GEOMETRY, &m_colorBuffer[0]);
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}
