#include "pch.h"
#include "DrawableObj.h"

using namespace DirectX;using namespace DirectX;

DrawableObj::DrawableObj() : PhysicalObj()
{
}

DrawableObj::DrawableObj(int idIn) : PhysicalObj(idIn)
{
}

DrawableObj::DrawableObj(int idIn, std::string nameIn, std::string descIn) : PhysicalObj(idIn, nameIn, descIn)
{
}

void DrawableObj::Render(ID3D12GraphicsCommandList* commandList, std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, std::unique_ptr<DirectX::SpriteBatch>& spriteBatchIn)
{
    screenPos.x = this->xPos;
    screenPos.y = this->yPos;
    spriteBatchIn->Draw(descriptorHeapIn->GetGpuHandle(Descriptors::Cat),
        GetTextureSize(texture.Get()),
        screenPos, nullptr, Colors::White, 0.f, origin);
}

void DrawableObj::CreateDeviceDependentResources(DirectX::ResourceUploadBatch& resourceUploadIn, std::unique_ptr<DX::DeviceResources>& deviceResourcesIn, std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, ID3D12Device* deviceIn, const wchar_t* fileNameIn)
{
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(deviceIn, resourceUploadIn, fileNameIn,
            texture.ReleaseAndGetAddressOf()));

    CreateShaderResourceView(deviceIn, texture.Get(),
        descriptorHeapIn->GetCpuHandle(getID()));

    XMUINT2 textureSize = GetTextureSize(texture.Get());

    origin.x = float(textureSize.x / 2);
    origin.y = float(textureSize.y / 2);
}

