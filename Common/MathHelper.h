
#ifndef MathHelper_h__
#define MathHelper_h__

#include <stdlib.h>
#include <DirectXMath.h>

class MathHelper
{

public:
	static float RandF()
	{
		return (float)(rand()) / (float)(RAND_MAX);
	}

	// Returns random float in [a, b).
	static float RandF(float a, float b)
	{
		return a + RandF()*(b - a); 
	}

	template<typename T>
	static T Min(const T&a, const T&b)
	{
		return a < b ? a : b;
	}

	template<typename T>
	static T Max(const T&a, const T&b)
	{
		return a > b ? a : b;
	}

	template<typename T>
	static T Lerp(const T&a, const T&b, float t)
	{
		return a + (b - a)*t;
	}

	template<typename T>
	static T Clamp(const T&x, const T&low, const T&high)
	{
		return x < low ? low : (x > high ? high : x);
	}

	// Returns the polar angle of the point (x,y) in [0, 2*PI).
	static float AngleFromXY(float x, float y);

	static DirectX::XMMATRIX InverseTranspose(DirectX::CXMMATRIX M)
	{
		// Inverse-transpose is just applied to normals.  So zero out
		// translation row so that it doesn't get into our inverse-transpose
		// calculation--we don't want the inverse-transpose of the translation.
		DirectX::XMMATRIX A = M;
		A.r[3] = DirectX::XMVectorSet(0.0f, 0.0f, 0.0f, 1.0f);

		DirectX::XMVECTOR det = XMMatrixDeterminant(A);
		return XMMatrixTranspose(XMMatrixInverse(&det, A));
	}
};

/*
class MathHelper
{
public: 



static XMVECTOR RandUnitVec3();
static XMVECTOR RandHemisphereUnitVec3(XMVECTOR n);

static const float Infinity;
static const float Pi;


};

#endif // MATHHELPER_H
*/



#endif // MathHelper_h__