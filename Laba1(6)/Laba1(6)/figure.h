#pragma once

#include <array>
#include <vector>

#include "graphics.h"
#include "matrix.h"

class Figure
{
public:
	Figure(std::vector<std::array<int32_t, 2>> vertices, std::vector<std::array<uint32_t, 2>> edges);

	void SetPivot(uint32_t vertex);
	void Scaling(float s1,float s2);
	void Translate(float x, float y);
	void Rotate(float ang);

	void Draw(Graphics &g);
	void DrawPoint(Graphics& g);
	float GetDistanseX(Figure b) {
		return vertices_[1][0] - b.vertices_[5][0];
	}
	float GetDistanseY(Figure b) {
		return vertices_[1][1] - b.vertices_[5][1];
	}
private:
	Matrix vertices_;
	std::vector<std::array<uint32_t, 2>> edges_;

	uint32_t pivot_ = 0;
};
