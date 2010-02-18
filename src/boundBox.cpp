/*
 *  boundBox.cpp
 *  emptyExample
 */

#include "boundBox.h"

boundBox::boundBox( int startX, int startY )
{
	margin = 10;
	pixelCount = 0;
	L = startX - margin;
	R = startX + margin;
	B = startY + margin;
	T = startY - margin;
}

bool	boundBox::pointInside( int X, int Y )
{
	if ( X >= L && X <= R && Y >= T && Y <= B )
	{
		pixelCount++;		// same as pixelCount = pixelCount+1
		
		if ( X-margin < L )
			L = X-margin;
		
		if ( X+margin > R )
			R = X+margin;
		
		if ( Y+margin > B )
			B = Y+margin;
		
		if ( Y-margin < T )
			T = Y-margin;
		
		return true;
	}
	else
		return false;
}


void	boundBox::draw( int X, int Y )
{
	ofSetColor( 0, 255, 0 );
	ofNoFill();
	ofRect( X+L, Y+B, (R-L), (T-B) );
	
	ofSetColor( 255, 255, 255 );
}




