/*
 *  boundBox.h
 *  emptyExample
 *
 */

#include "ofMain.h"

class boundBox
{
public:
	
	boundBox( int startX, int startY );
	
	bool	pointInside( int X, int Y );
	void	draw( int X, int Y );
	
	int		L, T, R, B;
	int		pixelCount;
	int		margin;
};

