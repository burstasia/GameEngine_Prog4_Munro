#include "MiniginPCH.h"
#include "Level.h"
namespace dae
{
	void Level::Render() const
	{
		//render tiles accordingly
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
		//we have out index!
		//return

		int index = (int)y / m_TileSize;
		index *= m_Width / m_TileSize;

		index += (int)x / m_TileSize;

		TileType tile = TileType::empty;
		
		int type = m_Grid.at(index);

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

	}

	Level::~Level()
	{
	}
}

