#include "Command.h"

Command::~Command() {
	delete this->utility;
}
