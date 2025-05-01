#if !defined(PERMISSION_H)
#define PERMISSION_H

#include <vector>
#include <string>

class permission
{
public:
	permission();
	~permission();
	int getPermissionType(std::string userID);
	void checkPermissionType(std::string userID);


private:
	enum class permissionType
	{
		guest = 0,
		user = 1,
		employee = 2,
		manager = 3
	};
	std::string userID;
	int level;
	permissionType permissionLevel;
};



#endif //PERMISSION_H
