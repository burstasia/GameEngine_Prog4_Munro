#pragma once
#include "./Components/BaseComponent.h"

namespace dae
{
	class BaseComponent;

	enum TileType
	{
		empty = 0,
		wall = 1,
		pill = 2
	};

	class Level
	{
	public:

		void Render() const;
		void Update(float elapsedSec);

		TileType GetTileType(float x, float y);
		TileType GetTileType(float x1, float y1, float x2, float y2);

		Level(const std::vector<int>& grid, int width, int height, int tileSize);
		~Level();

	private:

		std::vector<int> m_Grid;

		int m_Width;
		int m_Height;
		int m_TileSize;

		int m_NumTilesHorizontal;
		int m_NumTilesVertical;

		std::vector<BaseComponent*> m_pComponents;
	};
}


