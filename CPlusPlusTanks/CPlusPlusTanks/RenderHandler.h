#ifndef RENDERHANDLER_H
#define RENDERHANDLER_H

#include<vector>
#include<string>
using namespace std;

class RenderHandler {
private:
	void drawCircle(float cx, float cy, float radius, int num_segments, float r, float g, float b, bool fill);
	void drawRect(float x, float y, float width, float height, float r, float g, float b, bool fill);
public:
	RenderHandler();
	~RenderHandler();
	void update();
	void draw();
	void shoot(std::vector<std::vector<double>> thing);
	void drawScoreboard();
	void drawTexturedObject(int x, int y, int width, int height, int r, int g, int b, int position);
	void drawText(float x, float y, std::string text, float r, float g, float b);
	std::string int2str(int x);
};
#endif