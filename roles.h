#if !defined(ROLES_H)
#define ROLES_H

class roleBase
{
private:
	int permissionLevel;

protected:
	int option = 0;
	virtual void displayHeader() const;
	void displayfooter() const;
	virtual void trackParcel() = 0;
	virtual void manageAcc();
	int logOut();
	void exit();

public:
	roleBase();
	~roleBase();

	virtual void displayMenu() const = 0;
	virtual void excuteCommand(int option) = 0;

	int getPermissionLevel() {};

};

class guest :public roleBase
{
private:
	void displayHeader() const;

public:
	void trackParcel() override;
	void displayMenu () const override;
	void excuteCommand(int option) override;
};

class user :public guest
{
public:
	int history();
	void manageAcc();
	void displayMenu() const override;
	void excuteCommand(int option) override;

};

class employee :public roleBase
{
public:
	void displayMenu() const override;
	void excuteCommand(int option) override;
	void trackParcel() override;

};

class manager :public employee
{
public:
	void displayMenu() const override;
	void excuteCommand(int option) override;
	void manageAcc() override;
};


#endif //ROLES_H
