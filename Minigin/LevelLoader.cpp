#include "MiniginPCH.h"
#include "LevelLoader.h"
#include "json.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include "Level.h"

using json = nlohmann::json;

dae::LevelLoader::LevelLoader()
{
}


dae::LevelLoader::~LevelLoader()
{
}

dae::Level* dae::LevelLoader::LoadLevel(const std::string & filepath)
{
	UNREFERENCED_PARAMETER(filepath);

	std::ifstream fileStream(filepath);

	if (fileStream.is_open())
	{
		std::string line;
		std::stringstream stringStream;
		while (!fileStream.eof())
		{
			std::getline(fileStream, line);
			stringStream << line << '\n';
		}
		std::string str = stringStream.str();

		
		fileStream.close();

		json j;
		j = j.parse(str);

		m_TileSize = j["tileSize"].get<int>();
		m_Width = j["widthLevel"].get<int>();
		m_Height = j["heightLevel"].get<int>();

		m_Grid = j["grid"].get<std::vector<int>>();
	}
	

	auto level = new Level(m_Grid, m_Width, m_Height, m_TileSize);


	return level;
}
