#ifndef TexturedHillsAndWavesApp_h__
#define TexturedHillsAndWavesApp_h__

#include "D3DApp.h"
#include "Waves.h"
#include "LightHelper.h"
#include "Vertex.h"
#include "D3DEffects.h"

class TexturedHillsAndWavesApp : public D3DApp
{
public:
	TexturedHillsAndWavesApp();
	~TexturedHillsAndWavesApp(); 

	bool Init(HINSTANCE hinst);
	void UpdateScene(float dt);
	void DrawScene();

private:
	float GetHillHeight(float x, float z)const;
	DirectX::XMFLOAT3 GetHillNormal(float x, float z)const;
	void BuildLandGeometryBuffers();
	void BuildWaveGeometryBuffers(); 

private:
	ID3D11Buffer* mLandVB=0;
	ID3D11Buffer* mLandIB=0;

	ID3D11Buffer* mWavesVB=0;
	ID3D11Buffer* mWavesIB=0;

	ID3D11ShaderResourceView* mGrassMapSRV=0;
	ID3D11ShaderResourceView* mWavesMapSRV=0; 

	BasicTextureEffect* mEffect = 0;
	ID3D11InputLayout* mInputLayout = 0;
	InputLayouts mInputLayouts;

	Waves mWaves;

	DirectionalLight mDirLights[3];
	Material mLandMat;
	Material mWavesMat;

	DirectX::XMFLOAT4X4 mGrassTexTransform;
	DirectX::XMFLOAT4X4 mWaterTexTransform;
	DirectX::XMFLOAT4X4 mLandWorld;
	DirectX::XMFLOAT4X4 mWavesWorld;

	UINT mLandIndexCount;
	DirectX::XMFLOAT2 mWaterTexOffset;
}; 
#endif // TexturedHillsAndWavesApp_h__
