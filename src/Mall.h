#include <exception>
using namespace std;

#ifndef __Mall_h__
#define __Mall_h__

#include "State.h"
#include "CommComponent.h"

class State;
// class CommComponent;
class Mall;

class Mall: public CommComponent
{
	private: State _state;
	private: double _income;
	private: int _employment;
	private: int _powerReq;
	private: int _waterReq;
	private: double _maintenanceCost;
	private: int _sewageCost;
	private: int _waste;
	private: CommComponent _children;
	public: CommComponent* _unnamed_CommComponent_;

	public: void requestState();

	public: int getIncome();

	public: int getEmployment();

	public: double getMaintenanceCost();

	public: int getWaterReq();

	public: int getPowerReq();

	public: int getSewageCost();

	public: int getWasteCost();

	public: void add(CommComponent aParam);

	public: void remove(CommComponent aParam);

	public: CommComponent getChild();

	public: virtual void add(EstateComponent aParam);

	public: virtual void remove(EstateComponent aParam);

	public: virtual void getChild(EstateComponent aParam);
};

#endif
