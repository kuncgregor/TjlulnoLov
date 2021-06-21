#pragma once
#include <iostream>
class Vector2D {
public:

	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	Vector2D& Sestej(const Vector2D& vec);
	Vector2D& Odstej(const Vector2D& vec);
	Vector2D& Mnozi(const Vector2D& vec);
	Vector2D& Deli(const Vector2D& vec);

	friend Vector2D operator+(Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator-(Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator*(Vector2D& v1, const Vector2D& v2);
	friend Vector2D operator/(Vector2D& v1, const Vector2D& v2);

	Vector2D& operator+=(const Vector2D& vec);
	Vector2D& operator-=(const Vector2D& vec);
	Vector2D& operator*=(const Vector2D& vec);
	Vector2D& operator/=(const Vector2D& vec);
	

	friend std::ostream& operator<<(std::ostream & stream, const Vector2D & vec);
};