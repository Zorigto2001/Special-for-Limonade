// Лабораторная работа 1. Двумерные геометрические преобразования.
// Задача 6. Колесо обозрения

#include "graphics.h"
#include "figure.h"
#include <iostream>
#include "app.h"

bool App::running_ = false;
Figure line({
	{ 320, 200 },
	{ 420, 200 },
	}, {
		{ 0, 1 },
		{ 1, 0 },

	});
Figure point({
	{ 0, 60 },
	{ 0, 0 },
	{ 80, 0 },
	{ 80, 60 },
	{0, 60 },
	{ 40, 90 },
	{ 80, 60 },
	}, {
		{ 0, 1 },
		{ 1, 2 },
		{ 2, 3 },
		{ 3, 4 },
		{ 4, 5 },
		{ 5, 6 },
		{ 6, 0 },

	});

void App::Run()
{
	running_ = true;
}

void App::Draw()
{
	Graphics g;

	//g.DrawLine(0, 50, Graphics::width - 1, Graphics::height - 1, RGB(0, 255, 0));
	point.DrawPoint(g);
	line.DrawPoint(g);
}

void App::Update()
{
	static const int a = 30;

	static uint32_t i = a;
	//float 
	if (running_)
	{
		//point.SetPivot(1);
		line.Rotate(-90 / a);
		point.Translate(line.GetDistanseX(point), line.GetDistanseY(point));
		//point.Rotate(90.f / a);
		

		Draw();

		i++;

		if (i / a == 15)
		{
			
			running_ = false;
		}
	}
}

void App::Init()
{
	// 1
	
	point.Rotate(180);
	point.Translate(line.GetDistanseX(point), line.GetDistanseY(point));
	Draw();
}
