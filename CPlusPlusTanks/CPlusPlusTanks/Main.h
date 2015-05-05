#ifndef MAIN_H
#define MAIN_H

class Main {
private:
	void openGLInit(int argc, char** argv);
	void init();
	void enable2D(int width, int height);
	void c_main( int position, int health, int shells, float angle);
public:
	Main(int argc, char** argv);
	~Main();
};
#endif