#ifndef _GLINT_FINDER_
#define _GLINT_FINDER_

#include "ofMain.h"
#include "ofxCvGrayscaleAdvanced.h"
#include "ofxOpenCv.h"
#include "ofxVectorMath.h"
#include "glintLineChecker.h"
#include "glintRefChecker.h"

class glintFinder {
	
public:
	
	void		setup(int eyeWidth,int eyeHeight, float _magRatio, float IMwidth, float IMheight);
	bool		update(ofxCvGrayscaleAdvanced & blackEyeImg, float threshold, float minBlobSize, float maxBlobSize, bool bUseBrightEyeCheck, int blobSmoothingSize, float blobSmoothingAmount, bool useBoundingBox);
	void		drawLine(float x, float y, float width, float height, float len);
	void		drawLineOnBrightGlint(float x, float y, float width, float height, float len);
	void		draw(float x, float y);
	bool		findGlintCandidates(ofxCvGrayscaleAdvanced & eyeImg, float _threshold, float minBlobSize, float maxBlobSize, bool isBrightEye);
	ofPoint		getGlintPosition(int glintID);
	
	void smoothBlobs(vector<ofxCvBlob>& blobs, int smoothingSize, float smoothingAmount);
	void smoothBlob(ofxCvBlob& blob, int smoothingSize, float smoothingAmount);
	void recomputeCentroid(ofxCvBlob& blob);
	void setCentroidsFromBoundingBox(vector<ofxCvBlob>& blobs);
	void setCentroidFromBoundingBox(ofxCvBlob& blob);
	
	glintLineChecker		gLineChecker;
	ofxCvContourFinder		contourFinder;
	ofxCvContourFinder		contourFinderBright;
	ofxCvGrayscaleImage		eyeImage;
	
	bool					bFourGlints;					//true: 4 glints, false: 2 glints
	bool					bFound;
	float					magRatio;	
	float					w, h;
	float					inputWidth, inputHeight;
	int						smallestID, biggestID;
	bool					bUseContrastStretch;
	
	ofRectangle				glintROI;
	ofPoint					pctGlintROIorigin, pctGlintROIend;
	ofPoint					glintPos[4];
	
	glintRefChecker			refChecker;
	bool					bRecordRef;
	bool					bFirstRecFrame;
	bool					bUseRecordRef;
	float					minDistancePct, maxDistancePct;

	//	bool				bIsVerticalLED;
	
	ofxCvGrayscaleAdvanced	checkBrightEye;				// TODO: FORCHEck!!
	
protected:
	
	void	drawCross(ofPoint & pos, float x, float y, float width, float height, float len);
	
};

#endif /*_GLINT_FINDER_*/



