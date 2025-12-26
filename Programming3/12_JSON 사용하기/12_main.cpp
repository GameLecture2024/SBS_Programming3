// cpp json사용하기
// 객체를 표현하는 약속이다.

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

class Run
{
public:
	int x;
	int y;
	string shape;
	int speed;

public:
	Run(int x, int y, string shape, int speed) : x(x), y(y), shape(shape), speed(speed) {}
};

int main()
{
	cout << "JSON 파일 읽기" << endl;

	// 1. 프로젝트 내부에 있는 파일을 읽어오세요.
	string filepath = "C:\\Users\\Administrator\\Desktop\\SBS_Programming3\\Programming3\\12_JSON 사용하기\\run_object.json";

	ifstream ifs(filepath);

	// 2. 파일 읽기
	IStreamWrapper isw(ifs);
	Document doc;
	doc.ParseStream(isw);
	
	std::vector<Run> runObjects;

	// 3. 타입 변환(Parse)
	if (doc.IsArray())
	{
		for (int i = 0; i < doc.Size(); i++)
		{
			const Value& obj = doc[i];	    

			if (obj.IsObject())         // json에서 "{  }" 묶여있나?
			{
				if (obj.HasMember("X") && obj["X"].IsInt() &&    // 조건 1.x 좌표
					obj.HasMember("Y") && obj["Y"].IsInt() &&    // 조건 2.y 좌표
					obj.HasMember("Shape") && obj["Shape"].IsString() &&
					obj.HasMember("Speed ") && obj["Speed "].IsInt()
					)
				{
					Run	r(obj["X"].GetInt(), obj["Y"].GetInt(), obj["Shape"].GetString(), obj["Speed "].GetInt());

					runObjects.push_back(r);
				}

			}
	    }
	}


	// 4. 예제 출력

	for (const auto& r : runObjects)
	{
		cout << "x:" << r.x << ",Y:" << r.y << ",shape:" << r.shape << ",speed:" << r.speed << endl;
	}


}