#pragma once

class CRectangle
{
public:
	CRectangle(int left = 0, int top = 0, int width = 0, int height = 0);
	~CRectangle();

	void SetWidth(int width);
	unsigned GetWidth() const;

	void SetHeight(int height);
	unsigned GetHeight() const;

	unsigned GetSquare() const;
	unsigned GetPerimetr() const;

	void SetLeft(int xCoordinate);
	unsigned GetLeft() const;

	void SetRight(int right);
	unsigned GetRight() const;

	void SetBottom(int bottom);
	unsigned GetBottom() const;

	void SetTop(int yCoordinate);
	unsigned GetTop() const;

	void Move(int dx, int dy);
	void Scale(int sx, int sy);
	bool Intersect(CRectangle const& other);
private:
	int m_width;
	int m_height;
	int m_left;
	int m_top;
};

