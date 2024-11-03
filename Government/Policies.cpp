#include <exception>
using namespace std;

#include "Policies.h"
#include "Government.h"

// No need for execute() implementation here since it's already defined in the header
// The execute() function in the header calls executePolicy(), which is pure virtual