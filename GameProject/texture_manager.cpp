#include "global.h"
#include "texture_manager.h"


TextureManager::TextureManager()
{
}
void TextureManager::LoadTexture(const TCHAR* name, int id)
{
	TextureElements* newElements = new TextureElements();
	newElements->id = id;

	D3DXCreateSprite(g_pd3dDevice, &newElements->sprite);
	D3DXCreateTextureFromFile(g_pd3dDevice, name, &newElements->texture);

	elements.push_back(newElements);
}
TextureElements* TextureManager::GetTexture(int id)
{
	for (int i = 0; i < elements.size(); i++) {
		if (id == elements[i]->id) {
			return elements[i];
		}
	}

	return nullptr;
}