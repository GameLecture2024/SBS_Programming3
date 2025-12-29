#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>   // 스마트 포인터, 포인터를 객체화했다.

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/istreamwrapper.h"

using namespace std;
using namespace rapidjson;

// 1. Factory 클래스 ( 열거형을 읽어서 자신의 타입에 맞는 클래스를 생성해주는 클래스)
// 2. Spawner클래스는 Factory클래스를 사용해서 클래스를 생성한다.
// 특정 클래스를 사용하는 클래스를 만들어라.
// 포인터를 사용하는 클래스. 스마트 포인터
// gameObject

enum class moveType
{
	normal = 0, jump, dash,
};

class Run
{
public:
	int x;
	int y;
	string shape;
	int speed;
	Run(int x, int y, string shape, int speed) : x(x), y(y), shape(shape), speed(speed) {}
	Run() = default;
	virtual ~Run() = default;
	virtual void move() { cout << "run합니다."; }
};

class Dash : public Run
{
public:
	int dashpower;
	Dash(int x, int y, string shape, int speed, int dashpower) : Run(x, y, shape, speed), dashpower(dashpower) {}
	void move() override { cout << "Dash합니다."; }
};

class Jump : public Run
{
public:
	int jumppower;
	Jump(int x, int y, string shape, int speed, int jumppower) : Run(x, y, shape, speed), jumppower(jumppower) {}
	void move() override { cout << "jump합니다."; }
};

// 클래스의 이름을 반드시 정해서 전달해주자.
// Excel 데이터 이름의 대문자 소문자가 클래스 이름과 달라서 문제가 많이 발생했다.

class RunFactory {
public:
    // rapidjson::Value (배열 타입)를 인자로 받아 객체 리스트 생성
    static std::vector<std::unique_ptr<Run>> CreateFromValue(const Value& dataArray) {
        std::vector<std::unique_ptr<Run>> tempObjects;

        if (!dataArray.IsArray()) return tempObjects;

        for (auto& item : dataArray.GetArray()) {
            if (!item.HasMember("moveType")) continue;

            moveType mType = static_cast<moveType>(item["moveType"].GetInt());
            int x = item["X"].GetInt();
            int y = item["Y"].GetInt();
            std::string shape = item["Shape"].GetString();
            int speed = item["Speed"].GetInt();

            if (mType == moveType::normal) {
                tempObjects.push_back(std::make_unique<Run>(x, y, shape, speed));
            }
            else if (mType == moveType::jump) {
                tempObjects.push_back(std::make_unique<Jump>(x, y, shape, speed, item["jumppower"].GetInt()));
            }
            else if (mType == moveType::dash) {
                tempObjects.push_back(std::make_unique<Dash>(x, y, shape, speed, item["dashpower"].GetInt()));
            }
        }
        return tempObjects;
    }
};


// RunFactory클래스를 이용해서 run객체를 vector에 저장해서 사용하는 Spawner 클래스를 만들어라.

class Spawner {
private:
    std::vector<std::unique_ptr<Run>> spawnedObjects;

public:
    // 외부에서 생성된 객체 리스트를 받아 관리
    void SetObjects(std::vector<std::unique_ptr<Run>> newObjects) {
        spawnedObjects = std::move(newObjects);
    }

    void DisplayAll() const {
        for (auto& r : spawnedObjects)
        {
            r->move();
        }
    }
};


