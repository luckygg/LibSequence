#pragma once
struct StRGB
{
	int nR;
	int nG;
	int nB;
};

struct StSimpleThd
{
	CString strType;	// Absolute, Relative, Min Residue, Max Entropy
	int nAbs;			// Absolute
	int nRel;			// Relative
};

struct StDoubleThd
{
	int	nPxlHigh;	// Pixel High Value
	int	nThdHigh;	// Threshold High Value
	int	nPxlMid;		// Pixel Between Value
	int	nThdLow;		// Threshold Low Value
	int	nPxlLow;		// Pixel Low Value
};

struct StAdaptiveThd
{
	CString strType;	// Mean, Median, Middle
	int nKernel;		// Kernels
	int nOffset;		// Offset
};

struct StConvolution
{
	CString strType;	// Kernel Type
	//std::map vKernel;		// User Define Kernel
};

struct StMorphology
{
	CString strType;	// Operation Type
	int nHalfKernel;	// Half of Kernel
};

struct StThreshold
{
	CString strType;			// Threshold Method
	StSimpleThd stSimple;		// Simple Threshold
	StDoubleThd stDouble;		// Double Threshold
	StAdaptiveThd stAdaptive;	// Adpative Threshold
};

struct StArithmetic
{
	CString strType;	// Operation Type
};

struct StScale
{
	CString strType;	// Mode Type
	float fSrcPvtX;		// Source Pivot X
	float fSrcPvtY;		// Source Pivot Y
	float fDstPvtX;		// Destination Pivot X
	float fDstPvtY;		// Destination Pivot Y
	float fScaleX;		// Scale X
	float fScaleY;		// Scale Y
	float fAngle;		// Angle
	int	nBits;			// Interpolation Bits
};

struct StGain
{
	float fGain;		// Gain
	float fOffset;		// Offset
};

struct StBcd
{
	bool bCheckSum;		// Enable Check Sum
	CString	strCode;	// Decoded Code
	CString	strCodeComment;
	CString	strSymbol;	// Decoded Symbol
	CString	strSymbolComment;
};

struct StMtx
{
	int	nTimeout;		// Timeout
	CString	strModel;	// Decoded Model
	CString	strCode;	// Decoded Code
	CString	strCodeComment;
	CString	strSize;	// Decoded Size
	CString	strSizeComment;
	CString	strFamily;	// Decoded Family
	CString	strFamilyComment;
};

struct StImg
{
	CString strType;				// Selected Algorithm
	StConvolution stConvolution;	// Convolution
	StMorphology stMorphology;		// Morphology
	StThreshold stThreshold;		// Threshold
	StArithmetic stArithmetic;		// Arithmetic & Logic
	StScale stScale;				// Scale & Rotate
	StGain stGain;					// Gain
};

struct StLibrary
{
	StImg stImg;		// EasyImage
	StMtx stMtx;		// EasyMatrix
};