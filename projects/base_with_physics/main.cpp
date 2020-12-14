#include "cmath"
#include "kf/kf_log.h"
#include "mainMenu.h"
#include "kf/kf_log.h"
#include "SceneManager.h"
#include "GameEditor.h"
#include "Game.h"

using namespace std;

int main()
{
	SceneManager sceneManager;
	mainMenu* MainMenu = new mainMenu();
	Game* game = new Game();
	GameEditor* gameEditor = new  GameEditor();
	sceneManager.AddScene(MainMenu);
	sceneManager.AddScene(game);
	sceneManager.AddScene(gameEditor);


	sceneManager.run();
	return 0;
}
