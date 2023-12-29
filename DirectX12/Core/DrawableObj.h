#pragma once
#include "PhysicalObj.h";
#include "DeviceResources.h"
#include <pch.cpp>
#include <StepTimer.h>


class DrawableObj : public PhysicalObj
{
public:
	// Constructors
	DrawableObj();
	DrawableObj(int idIn);
	DrawableObj(int idIn, std::string nameIn, std::string descIn);
	~DrawableObj() = default;

	// Accessors

	// Functionality
	void Update(DX::StepTimer const& timer);
	void Render(ID3D12GraphicsCommandList* commandList, std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, std::unique_ptr<DirectX::SpriteBatch>& spriteBatchIn);

	void CreateDeviceDependentResources(DirectX::ResourceUploadBatch& resourceUploadIn, std::unique_ptr<DX::DeviceResources>& deviceResourcesIn, std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, ID3D12Device* deviceIn, const wchar_t* fileNameIn);
private:
	Microsoft::WRL::ComPtr<ID3D12Resource> texture;
    DirectX::SimpleMath::Vector2 screenPos;
    DirectX::SimpleMath::Vector2 origin;
	RECT tileRect;
	enum Descriptors
	{
		Cat,
		Background,
		Count
	};
};

