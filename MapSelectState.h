#ifndef MAP_SELECT_STATE
#define MAP_SELECT_STATE

#include "FrameWork.h"
#include "GameState.h"

class MapSelectState : public GameState
{
private:
	unsigned int currentPage;
	std::vector<std::wstring> mapList;

	fw_Texture* background;

	fw_Texture* previewImage1;
	fw_Texture* previewImage2;

	char* mapLeftName;
	int mapLeftPackage;
	int mapLeftTime;

	char* mapRightName;
	int mapRightPackage;
	int mapRightTime;

	int checkUnlockLeft;
	int checkUnlockRight;

	void getMapList();
	void setMapPreviewInfo(int image1, int image2);

	int gamemode;

	bool copyFile(const char *SRC, const char* DEST) {
		std::ifstream src(SRC, std::ios::binary);
		std::ofstream dest(DEST, std::ios::binary);
		dest << src.rdbuf();
		return src && dest;
	}

	char* wstringToCharArray(std::wstring wideString)
	{
		char* buffer = new char[255];
		size_t charsConverted = 0;
		wcstombs_s(&charsConverted, buffer, (size_t)(wideString.length() + 1), wideString.c_str(), wideString.length());
		return buffer;
	}
public:
	bool onEnter();
	bool onExit();
	void update();
	void render();
	MapSelectState();
	~MapSelectState();

	fw_Callback buttonMapLeft();
	fw_Callback buttonMapRight();
	fw_Callback buttonPrevClick();
	fw_Callback buttonNextClick();
	fw_Callback buttonCancelClick();

	fw_Callback moveEvent();
	fw_Callback handleLeftMouseClick();
};

#endif