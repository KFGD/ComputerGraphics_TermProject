#pragma once
#include <cstdio>

struct Vector3 { float x, y, z; };

class IUpdate {
public:
	virtual void Update() = 0;
};

class IUserCode {
public:
	virtual void Awake();
	virtual void Start() = 0;
	virtual void Update() = 0;
};

//fileName의 이름에 맞는 파일을 열고 length에 파일 속 문자의 길이를 할당하고 buffer에 length만큼 메모리를 할당한 후, buffer에 fileName의 내용을 복사
static void ReadData(const char* fileName, void** buffer, int* length) {
	FILE* fp = fopen(fileName, "rb");
	fseek(fp, 0, SEEK_END);	//파일을 쓰기/읽기 위한 커서의 위치를 파일의 끝으로 이동
	*length = ftell(fp);	//현재 커서의 위치를 반환(파일의 문자 길이)
	fseek(fp, 0, SEEK_SET);	//파일을 쓰기/읽기 위한 커서의 위치를 파일의 맨앞으로 이동
	*buffer = new char[*length];
	fread(*buffer, *length, 1, fp);
	fclose(fp);
}