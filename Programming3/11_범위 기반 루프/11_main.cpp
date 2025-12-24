#include <iostream>
#include <vector>

using namespace std;
// for 반복문 또다른 사용법. cpp추가된 기능.
// 배열
// ranged loop - 
// 끝이 어딘지 알아야한다
int main()
{
	cout << "array로 범위 기반 루프 실행" << endl;
	int array2[10] = { 0,1,2,3,4,5 };

	for (int single : array2)
	{
		cout << single << " ";
	}

	cout << "\n\n vector로 범위 기반 루프 실행" << endl;

	std::vector<int> i_vec;		// 가변 배열
	i_vec.push_back(0);
	i_vec.push_back(1);
	i_vec.push_back(2);
	i_vec.push_back(3);

	cout << "i_vec 값 출력" << endl;

	for (int i : i_vec)
	{
		cout << i << " ";
	}

	cout << "\n\n auto키워드를 사용하기 " << endl;

	for (auto& i : i_vec)  // 참조자 : 별명.
	{
		i = i + 1;
	}
     
	cout << "i_vec 값 출력" << endl;

	for (const auto& i : i_vec)
	{
		cout << i << " ";
	}

}