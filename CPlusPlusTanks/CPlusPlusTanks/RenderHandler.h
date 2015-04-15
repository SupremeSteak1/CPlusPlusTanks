#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

class RenderHandler {
private:
	void drawCircle(float cx, float cy, float radius, int num_segments, float r, float g, float b, bool fill);
	void drawRect(float x, float y, float width, float height, float r, float g, float b, bool fill);
public:
	RenderHandler();
	~RenderHandler();
	void update();
	void draw();
};
#endif