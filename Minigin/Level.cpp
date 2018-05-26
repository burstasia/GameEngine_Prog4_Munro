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

		int index = GetIndex(x, y);

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
		
		int index = GetIndex(x1, y1);

		int type1 = m_Grid.at(index);

		index = GetIndex(x2, y2);

		int type2 = m_Grid.at(index);

		//NEEDS WORK NICOLE FIX THIS AHHHHHHHHHHHHH
		if (type1 == 1 || type2 == 1) return TileType::wall;
		if (type1 == 2 && type2 == 2) return TileType::pill;
		if (type1 == 0 && type2 == 0) return TileType::empty;

		return TileType::empty;
	}

	void Level::ChangeTileType(float x, float y, TileType newTile)
	{
		int index = GetIndex(x, y);

		float2 pos = m_PositionsTiles.at(index);

		auto temp = dynamic_cast<TextureComponent*>(m_pComponents.at(index));
		switch (newTile)
		{
		case 0:
			m_Grid.at(index) = 0;

			temp->SetTexture("empty.png", pos.x, pos.y);
			//m_pComponents.at(index) = new TextureComponent("../Data/empty.png", pos.x, pos.y);
			break;

		case 1:
			m_Grid.at(index) = 1;
			temp->SetTexture("wall.png", pos.x, pos.y);
			//m_pComponents.at(index) = new TextureComponent("../Data/wall.png", pos.x, pos.y);
			break;

		case 2:
			m_Grid.at(index) = 2;
			temp->SetTexture("pill.png", pos.x, pos.y);
			//m_pComponents.at(index) = new TextureComponent("../Data/pill.png", pos.x, pos.y);
			break;
		}

	}

	int Level::GetWidth()
	{
		return m_Width;
	}

	int Level::GetHeight()
	{
		return m_Height;
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

				m_PositionsTiles.push_back(float2((float)xPos, (float)xPos));
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

	int Level::GetIndex(float x, float y)
	{
		if (x > m_Width)
		{
			x = (float)m_Width;
		}
		if (y > m_Height)
		{
			y = (float)m_Height;
		}

		int index = (int)y / m_TileSize;
		index *= m_NumTilesHorizontal;

		index += (int)x / m_TileSize;

		if (index < 0) index = 0;

		if (index > m_Grid.size())
		{
			index = (int)m_Grid.size();
		}

		return index;
	}
}

