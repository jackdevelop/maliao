class Global
{
public:
	Global();
	~Global();
	int getCurrentLevel();
	int getTotalLevel();
	void setTotalLevel(int level);
	void setCurrentLevel(int level);

	static Global* getInstance();
	static Global* m_instance;


private:
	int totalLevel;//总关数
	int currentLevel;//当前关数

	

};
