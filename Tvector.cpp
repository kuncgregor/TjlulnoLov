#include "Tvector.h"


Vector2D::Vector2D() {
	x = 0.0f;
	y = 0.0f;
}

Vector2D::Vector2D(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2D& Vector2D::Sestej(const Vector2D& vec) {
	this->x += vec.x;
	this->y += vec.y;
	return *this;
}

Vector2D& Vector2D::Odstej(const Vector2D& vec) {
	this->x -= vec.x;
	this->y -= vec.y;
	return *this;
}
Vector2D& Vector2D::Mnozi(const Vector2D& vec) {
	this->x *= vec.x;
	this->y *= vec.y;
	return *this;
}
Vector2D& Vector2D::Deli(const Vector2D& vec) {
	this->x /= vec.x;
	this->y /= vec.y;
	return *this;
}

Vector2D operator+(Vector2D& v1, const Vector2D& v2) {
	return v1.Sestej(v2);
}
Vector2D operator-(Vector2D& v1, const Vector2D& v2) {
	return v1.Odstej(v2);
}
Vector2D operator*(Vector2D& v1, const Vector2D& v2) {
	return v1.Mnozi(v2);
}
Vector2D operator/(Vector2D& v1, const Vector2D& v2) {
	return v1.Deli(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {
	return this->Sestej(vec);
}
Vector2D& Vector2D::operator-=(const Vector2D& vec) {
	return this->Odstej(vec);
}
Vector2D& Vector2D::operator*=(const Vector2D& vec) {
	return this->Mnozi(vec);
}
Vector2D& Vector2D::operator/=(const Vector2D& vec) {
	return this->Deli(vec);
}



std::ostream& operator<<(std::ostream& stream, const Vector2D& vec) {
	stream << "(" << vec.x << "," << vec.y << ")";
	return stream;
}

