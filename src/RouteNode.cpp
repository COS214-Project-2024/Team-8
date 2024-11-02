#include "RouteNode.h"

/**
 * @brief Destruct a Route Node object successor
 * 
 * This will destruct all the successor nodes
 */
RouteNode::~RouteNode() {
    if(successor != nullptr) {
        delete successor;
    }
    successor = nullptr;
}