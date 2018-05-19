#pragma once
namespace dae
{
	class LevelLoader final
	{
	public:
		LevelLoader();
		~LevelLoader();

		bool LoadLevel(const std::string& filepath);

	private:
		int m_TileSize;
		int m_Width;
		int m_Height;

		std::vector<int> m_Grid;
	};
}


