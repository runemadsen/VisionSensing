#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup()
{	 	
	ofEnableSmoothing();
	
	with.loadImage("images/with.png");
	without.loadImage("images/without.png");
	output.clone(without);
	
	with.setImageType(OF_IMAGE_GRAYSCALE);
	without.setImageType(OF_IMAGE_GRAYSCALE);
	output.setImageType(OF_IMAGE_GRAYSCALE);
	
	withPixels = with.getPixels();
	withoutPixels = without.getPixels();
	outputPixels = output.getPixels();
	
	int threshold = 30;
	int w = with.width;
	int h = with.height;
	int diff;
	int index;
	
	int counter = 0;
	
	for (int i = 0; i < w; i++) 
	{
		for (int j = 0; j < h; j++) 
		{
			index = (j * w + i);
			
			diff = withPixels[index] - withoutPixels[index];
			
			if(abs(diff) > threshold)
			{
				counter++;
				outputPixels[index] = 255;
				
				bool foundBox = false;
				
				for(int n=0; n<boundBoxList.size(); n++)
				{
					if(boundBoxList[n].pointInside(i,j))
					{
						foundBox = true;
						break;
					}
				}
				
				if (foundBox == false)
				{
					boundBoxList.push_back(boundBox(i,j));
				}
			}
			else 
			{
				outputPixels[index] = 0;
			}

		}
	}
	
	output.update();
}


//--------------------------------------------------------------
void testApp::update()
{
	
}

//--------------------------------------------------------------
void testApp::draw()
{	
	ofSetColor(255,255,255);
	with.draw(0, 0);
	without.draw(300, 0);
	output.draw(600, 0);
	
	for( int n=0; n<boundBoxList.size(); n++ )
	{
		boundBoxList[n].draw(0,0);
		boundBoxList[n].draw(300,0);
		boundBoxList[n].draw(600,0);
	}
}

