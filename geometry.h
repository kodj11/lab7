extern const int Width;
extern const int Height;

class GraphObject {
protected:
	double x, y;

	int color;
public:
	GraphObject(double ax, double ay, int acolor)
		: x(ax), y(ay), color(acolor) {}
	virtual ~GraphObject() {}
	virtual void Save() = 0;
	virtual void Show() = 0;
	virtual void Hide() = 0;
	void Move(double nx, double ny);
	double X() const;
	double Y() const;

};

class Pixel : public GraphObject {
public:
	Pixel(double x = 0, double y = 0, int color = 0)
		: GraphObject(x, y, color) {}
	virtual ~Pixel() {}
	void Set(double nx = 0, double ny = 0, int ncolor = 0);
	void Save();
	void Show();
	void Hide();
};

class Circle : public GraphObject {
	double radius;
public:
	Circle(double x = 0, double y = 0, double r = 0, int color = 0)

		: GraphObject(x, y, color), radius(r) {}
	virtual ~Circle() {}
	void Set(double nx = 0, double ny = 0, double nr = 0, int ncolor = 0);
	void Save();
	void Show();
	void Hide();
};