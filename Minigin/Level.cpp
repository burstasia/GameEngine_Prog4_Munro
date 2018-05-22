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

		if (index < 0) index = 0;

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

	TileType Level::GetTileType(float x1, float y1, float x2, float y2)
	{
		//This overloaded version of get tile type gets the different tiles in the range of x and
		//y values provided
		//if one of the two tile types is a wall it will return wall
		
		int index = (int)y1 / m_TileSize;
		index *= m_NumTilesHorizontal;

		index += (int)x1 / m_TileSize;

		if (index < 0) index = 0;

		int type1 = m_Grid.at(index);


		index = (int)y2 / m_TileSize;
		index *= m_NumTilesHorizontal;

		index += (int)x2 / m_TileSize;

		if (index < 0) index = 0;

		int type2 = m_Grid.at(index);

		//NEEDS WORK NICOLE FIX THIS AHHHHHHHHHHHHH
		if (type1 == 1 || type2 == 1) return TileType::wall;
		if (type1 == 2 && type2 == 2) return TileType::pill;
		if (type1 == 0 && type2 == 0) return TileType::empty;

		return TileType::empty;
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

				int index = i + j;
				int tileType = m_Grid.at(index);

				switch (tileType)
				{
				case 0:
					m_pComponents.push_back(new TextureComponent("../Data/empty.png", (float)xPos, (float)yPos));
					break;

				case 1:
					m_pComponents.push_back(new TextureComponent("../Data/wall.png", (float)xPos, (float)yPos));
					break;

				case 2:
					m_pComponents.push_back(new TextureComponent("../Data/pill.png", (float)xPos, (float)yPos));
					break;
				}
			}
		}
	}

	Level::~Level()
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			if (pComp != 0)
			{
				delete(pComp);
				pComp = 0;
			}
		}
	}
}

