#include <exception>
using namespace std;

#ifndef __SewageBuidler_h__
#define __SewageBuidler_h__

#include "Command.h"
#include "UtilityBuilder.h"
#include "SewageSystems.h"

class Command;
// class UtilityBuilder;
class SewageBuidler;

class SewageBuidler: public UtilityBuilder
{

	public: SewageSystems* getSewageSystem();

	public: SewageBuidler(int aCurload);

	public: void addCommand(Command aCom);

	public: void setMaxWaste(int aMax);

	public: virtual void addCommand(Command* aCom);
};

#endif
