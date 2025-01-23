#pragma once
#include <EngineCore/Actor.h>

enum EDummyType
{
	DBat,
	DCrawler,
	DFrog,
	DJelly,
	DSnail,
	DSnake,
	DTurtle
};

class Dummy : public AActor
{
public:
	// constrcuter destructer
	Dummy();
	~Dummy();

	// delete Function
	Dummy(const Dummy& _Other) = delete;
	Dummy(Dummy&& _Other) noexcept = delete;
	Dummy& operator=(const Dummy& _Other) = delete;
	Dummy& operator=(Dummy&& _Other) noexcept = delete;

	EDummyType DummyTypeValue;

protected:

private:


};

