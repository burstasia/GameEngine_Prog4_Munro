#include "MiniginPCH.h"
#include "Level.h"
#include "./Components/TextureComponent.h"
#include "./Components/BaseComponent.h"

namespace dae
{
	void Level::Render() const
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->Render();
		}
		
	}

	void Level::Update(float elapsedSec)
	{
		UNREFERENCED_PARAMETER(elapsedSec);
		//update stuff I guess

	}

	TileType Level::GetTileType(float x, float y)
	{
		//div y by tile size
		// multiply y with amount of tiles (horizontal)
		//add x div tile size
		//we have our index!
		//return

		int index = (int)y / m_TileSize;
		index *= m_NumTilesHorizontal;

		index += (int)x / m_TileSize;

		int type = m_Grid.at(index);
        
		TileType tile = TileType::empty;

		switch (type)
		{
		case 0:
			tile = TileType::empty;
			break;
		case 1:
			tile = TileType::wall;
			break;
		case 2:
			tile = TileType::pill;
			break;
		};


		return tile;
	}


	Level::Level(const std::vector<int>& grid, int width, int height, int tileSize):
		m_Grid(grid),
		m_Width(width),
		m_Height(height),
		m_TileSize(tileSize)
	{
		m_NumTilesHorizontal = m_Width / m_TileSize;
		m_NumTilesVertical = m_Height / m_TileSize;

		int yPos{};
		int xPos{};

		//create tile texture components
		for (int i = 0; i < m_Grid.size(); i += m_NumTilesHorizontal)
		{
			for (int j = 0; j < m_NumTilesHorizontal; j++)
			{
				yPos = (i / m_NumTilesVertical) * m_TileSize;
				xPos = j * m_TileSize;

				m_pComponents.push_back(new TextureComponent("../Data/wall.png", (float)xPos, (float)yPos));
			}
		}
	}

	Level::~Level()
	{
	}
}

