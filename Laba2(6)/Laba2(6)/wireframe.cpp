#include <ranges>

#include "wireframe.h"

Wireframe::Wireframe(std::vector<std::array<float, 3>> vertices, std::vector<std::array<uint32_t, 2>> edges)
	: Model(vertices)
	, edges_(edges)
{

}

void Wireframe::Draw(Graphics &g)
{
	Matrix vertices = vertices_ * Camera::view() * Camera::projection();

	for (auto e : edges_)
	{
		g.DrawLine(vertices[e[0]][0], vertices[e[0]][1], vertices[e[1]][0], vertices[e[1]][1], RGB(0, 255, 255));
	}

	
}
