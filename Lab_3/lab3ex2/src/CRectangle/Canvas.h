#pragma once

class CCanvas
{
public:
	CCanvas(unsigned width = 60, unsigned height = 20);
	~CCanvas();
	unsigned GetWidth() const;
	unsigned GetHeight() const;
	char GetPixel(int x, int y) const;
	void Write(std::ostream &ostream) const;
	bool ValidCoords(int x, int y) const;
	void Clear(char code = s_nullSymbol);
	void SetPixel(int x, int y, char code);
private:
	typedef std::vector < std::vector<char> > canvas;
	canvas m_canvas;
	static char s_nullSymbol;
	unsigned m_width;
	unsigned m_height;
};


