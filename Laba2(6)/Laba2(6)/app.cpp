// Лабораторная работа 2. Построение проекции трёхмерной рёберной сцены.
// Задача 6. Брусок.

#include "graphics.h"
#include "camera.h"
#include "wireframe.h"

#include "app.h"

bool App::running_ = false;


Wireframe model({
	{ 0, 0, 0 },
	{ 30, 0, 0 },
	{ 30, 20, 0},
	{ 0, 20, 0},

	{ 0, 0, 10 },
	{ 30, 0, 10 },
	{ 30, 20, 10},
	{ 0, 20, 10},
	}, {
		
		{ 0, 1 },
		{ 1, 2 },
		{ 2, 3 },
		{ 3, 0 },
		{ 4, 5 },
		{ 5, 6 },
		{ 6, 7 },
		{ 7, 4 },
		{ 0, 4 },
		{ 1, 5 },
		{ 2, 6 },
		{ 3, 7 },
	});

void App::Run()
{
	running_ = true;
}

void App::Draw()
{
	Graphics g;

	// coordinate axes
	Camera::DrawLine(g, 0, 0, 0, 15, 0, 0, RGB(200, 0, 0));
	Camera::DrawLine(g, 0, 0, 0, 0, 15, 0, RGB(0, 200, 0));
	Camera::DrawLine(g, 0, 0, 0, 0, 0, 15, RGB(0, 0, 200));

	// model
	model.Draw(g);
}

void App::Update()
{
	if (running_) {
		model.Rotate(0, 0, -0.1);

		Draw();
	}
}

void App::Init()
{
	Camera::LookAt(2, 2, 1);
	Camera::Ortho(Graphics::width / 2, Graphics::height / 2, 10);

	Draw();
}
