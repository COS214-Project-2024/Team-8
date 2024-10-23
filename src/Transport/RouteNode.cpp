#include "RouteNode.h"

RouteNode::~RouteNode() {
    if(successor != nullptr) {
        delete successor;
    }
}