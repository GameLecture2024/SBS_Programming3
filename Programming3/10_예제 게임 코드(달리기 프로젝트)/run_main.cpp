#include "ConsoleRenderer.h"
#include "run_GameObject.h"

int main()
{
	ConsoleRenderer console;

	run_GameObject* goArray[7];

	goArray[0] = new run_GameObject;
	goArray[1] = new run_GameObject(80, 6, "cpp run project", 5);
	goArray[2] = new run_GameObject(80, 6, "speedy", 1);
	goArray[3] = new jump_gameObject(80, 6, "jump", 1, 2);
	goArray[4] = new jump_gameObject(80, 10, "jump", 2, 3);
	goArray[5] = new jump_gameObject(50, 10, "aa", 3, 3);
	goArray[6] = new dash_gameObject(50, 10, "dash", 3, 3);

	while (true)
	{
		// 플레이어 입력 player->update

		// player->update();

		// gameobject->Update

		for (const auto& go : goArray)
		{
			go->update();
		}
		console.Clear();
		
		// Rendering
		// player->draw(console);

		for (const auto& go : goArray)
		{
			go->draw(console);
		}

		// Flip
		console.Flipping();

		// 고정 대기 시간 Frame Per Second
		Sleep(17);  //      60프레임.	 16
	}
	delete[] goArray;
}