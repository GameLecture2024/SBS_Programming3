#include "ConsoleRenderer.h"
#include "run_GameObject.h"

int main()
{
	ConsoleRenderer console;

	run_GameObject* go1 = new run_GameObject;
	run_GameObject* go2 = new run_GameObject(80, 6, "cpp run project", 5);
	run_GameObject* go3 = new run_GameObject(80, 6, "speedy", 1);
	run_GameObject* go4 = new jump_gameObject(80, 6, "jump", 1, 2);
	while (true)
	{
		// 플레이어 입력 player->update

		// gameobject->Update

		go1->update();
		go2->update();
		go3->update();
		go4->update();
		// Rendering
		console.Clear();
		go1->draw(console);
		go2->draw(console);
		go3->draw(console);
		go4->draw(console);
		// Flip
		console.Flipping();

		// 고정 대기 시간 Frame Per Second
		Sleep(17);  //      60프레임.	 16
	}
	delete go1;
	delete go2;
	delete go3;
	delete go4;
}