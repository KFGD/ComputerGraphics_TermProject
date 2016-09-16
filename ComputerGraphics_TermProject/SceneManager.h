#pragma once
class CSceneManager
{
public:
	static CSceneManager* CreateSceneManager();
	void GameLoop();
private:
	void UpdateSceneElements();
	void RenderScene();
private:
	CSceneManager();
public:
	~CSceneManager();
};

