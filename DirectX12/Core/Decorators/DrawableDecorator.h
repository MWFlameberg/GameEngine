#pragma once
#include <Core/PhysicalObj.h>
#include <pch.cpp>
#include <StepTimer.h>

class DrawableDecorator : PhysicalObj
{
public:
	DrawableDecorator(PhysicalObj* objIn) : obj{ objIn } {};
	// Accessors
	void setFileName(std::string fileNameIn);
	std::string getFileName();
	void setTextureID(int idIn);
	int getTextureID();

	void setTextureValues(std::string fileNameIn, int idIn);

	// Functionality
	void Update(DX::StepTimer const& timer);
	void Render(std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, std::unique_ptr<DirectX::SpriteBatch>& spriteBatchIn);

	void CreateDeviceDependentResources(DirectX::ResourceUploadBatch& resourceUploadIn, std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, ID3D12Device* deviceIn);
protected:
	PhysicalObj* obj;
	int textureID;
	std::string fileName;
	Microsoft::WRL::ComPtr<ID3D12Resource> texture;
	DirectX::SimpleMath::Vector2 screenPos;
	DirectX::SimpleMath::Vector2 origin;
};

