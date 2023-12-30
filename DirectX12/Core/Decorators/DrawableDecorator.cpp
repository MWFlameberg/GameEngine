#include "pch.h"
#include "DrawableDecorator.h"

using namespace DirectX;

void DrawableDecorator::setFileName(std::string fileNameIn)
{
    fileName = fileNameIn;
}

std::string DrawableDecorator::getFileName()
{
    return fileName;
}

void DrawableDecorator::setTextureID(int idIn)
{
    textureID = idIn;
}

int DrawableDecorator::getTextureID()
{
    return textureID;
}

void DrawableDecorator::setTextureValues(std::string fileNameIn, int idIn)
{
    setFileName(fileNameIn);
    setTextureID(idIn);
}

void DrawableDecorator::Render(std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, std::unique_ptr<DirectX::SpriteBatch>& spriteBatchIn)
{
    screenPos.x = obj->getXPos();
    screenPos.y = obj->getYPos();
    spriteBatchIn->Draw(descriptorHeapIn->GetGpuHandle(textureID),
        GetTextureSize(texture.Get()),
        screenPos, nullptr, Colors::White, 0.f, origin);
}

void DrawableDecorator::CreateDeviceDependentResources(DirectX::ResourceUploadBatch& resourceUploadIn, std::unique_ptr<DirectX::DescriptorHeap>& descriptorHeapIn, ID3D12Device* deviceIn)
{
    std::wstring tempFile = std::wstring(fileName.begin(), fileName.end());
    DX::ThrowIfFailed(
        CreateWICTextureFromFile(deviceIn, resourceUploadIn, tempFile.c_str(),
            texture.ReleaseAndGetAddressOf()));

    CreateShaderResourceView(deviceIn, texture.Get(),
        descriptorHeapIn->GetCpuHandle(textureID));

    XMUINT2 textureSize = GetTextureSize(texture.Get());

    origin.x = float(textureSize.x / 2);
    origin.y = float(textureSize.y / 2);
}