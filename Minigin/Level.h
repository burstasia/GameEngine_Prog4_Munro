#pragma once
namespace dae
{
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

		Level(const std::vector<int>& grid, int width, int height, int tileSize);
		~Level();

	private:

		std::vector<int> m_Grid;

		int m_Width;
		int m_Height;
		int m_TileSize;
	};
}

