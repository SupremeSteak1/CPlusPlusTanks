#ifndef __TGA_H__
#define __TGA_H__

#pragma comment(lib, "Opengl32.lib")					//Link to OpenGL32.lib so we can use OpenGL stuff

#include <windows.h>									// Standard windows header
#include <stdio.h>										// Standard I/O header 
#include <gl\gl.h>										// Header for OpenGL32 library
#include "textureObj.h"



struct TGAHeader
{
    GLubyte Header[12];         // File Header To Determine File Type
};
 
typedef struct
{
    GLubyte header[6];          // Holds The First 6 Useful Bytes Of The File
    GLuint bytesPerPixel;           // Number Of BYTES Per Pixel (3 Or 4)
    GLuint imageSize;           // Amount Of Memory Needed To Hold The Image
    GLuint type;                // The Type Of Image, GL_RGB Or GL_RGBA
    GLuint Height;              // Height Of Image                 
    GLuint Width;               // Width Of Image              
    GLuint Bpp;             // Number Of BITS Per Pixel (24 Or 32)
} TGA;

TGAHeader tgaheader;                // Used To Store Our File Header
TGA tga; 



GLubyte uTGAcompare[12] = {0,0,2, 0,0,0,0,0,0,0,0,0};	// Uncompressed TGA Header
GLubyte cTGAcompare[12] = {0,0,10,0,0,0,0,0,0,0,0,0};	// Compressed TGA Header
bool LoadUncompressedTGA(textureObj *, char *, FILE *);	// Load an Uncompressed file
bool LoadCompressedTGA(textureObj *, char *, FILE *);		// Load a Compressed file

#endif






