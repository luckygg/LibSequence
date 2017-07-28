#pragma once

struct StSimpleThd
{
	CString strType;	// Absolute, Relative, Min Residue, Max Entropy
	int nAbs;			// Absolute
	int nRel;			// Relative
};

struct StDoubleThd
{
	int	nPxlHighVal;	// Pixel High Value
	int	nThdHighVal;	// Threshold High Value
	int	nPxlBtwVal;		// Pixel Between Value
	int	nThdLowVal;		// Threshold Low Value
	int	nPxlLowVal;		// Pixel Low Value
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
	float fSrcPvt;		// Source Pivot
	float fDstPvt;		// Destination Pivot
	float fSclX;		// Scale X
	float fSclY;		// Scale Y
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