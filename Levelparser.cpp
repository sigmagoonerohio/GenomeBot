#include "LevelParser.hpp"
#include <Geode/Geode.hpp>

using namespace geode;

std::vector<Node*> LevelParser::parseLevel(Level* level) {
    std::vector<Node*> nodes;

    // Platforms
    for(auto plat : level->platforms) {
        Node* node = new Node();
        node->x = plat->position.x;
        node->y = plat->position.y;
        node->safe = !plat->spike; // true if no spike
        parsePlatform(node, plat);
        nodes.push_back(node);
    }

    // Orbs
    for(auto orb : level->orbs) {
        Node* closestNode = nullptr;
        float minDist = 99999.f;

        // Assign orb to closest node
        for(auto node : nodes) {
            float dx = node->x - orb->position.x;
            float dy = node->y - orb->position.y;
            float dist = dx*dx + dy*dy;
            if(dist < minDist) {
                minDist = dist;
                closestNode = node;
            }
        }

        if(closestNode) parseOrb(closestNode, orb);
    }

    // Portals
    for(auto portal : level->portals) {
        Node* closestNode = nullptr;
        float minDist = 99999.f;

        for(auto node : nodes) {
            float dx = node->x - portal->position.x;
            float dy = node->y - portal->position.y;
            float dist = dx*dx + dy*dy;
            if(dist < minDist) {
                minDist = dist;
                closestNode = node;
            }
        }

        if(closestNode) parsePortal(closestNode, portal);
    }

    return nodes;
}

void LevelParser::parsePlatform(Node* node, void* platform) {
    // Could add moving platform logic here later
}

void LevelParser::parseOrb(Node* node, void* orb) {
    std::string type = *(std::string*)((uintptr_t)orb + 0x10); // example offset
    if(type == "yellow") node->jumpOrb = true;
    else if(type == "pink") node->highJumpOrb = true;
    else if(type == "red") node->gravityOrb = true;
    else if(type == "green") node->dashOrb = true;
}

void LevelParser::parsePortal(Node* node, void* portal) {
    Portal* p = new Portal();
    p->x = *(float*)((uintptr_t)portal + 0x00); // example offsets
    p->y = *(float*)((uintptr_t)portal + 0x04);
    std::string typeStr = *(std::string*)((uintptr_t)portal + 0x08);

    if(typeStr == "Ship") p->type = LevelType::Ship;
    else if(typeStr == "Wave") p->type = LevelType::Wave;
    else if(typeStr == "UFO") p->type = LevelType::UFO;
    else if(typeStr == "Ball") p->type = LevelType::Ball;
    else if(typeStr == "Robot") p->type = LevelType::Robot;
    else if(typeStr == "Spider") p->type = LevelType::Spider;
    else p->type = LevelType::Unknown;

    node->portals.push_back(p);
}#include "LevelParser.hpp"
#include <Geode/Geode.hpp>

using namespace geode;

std::vector<Node*> LevelParser::parseLevel(Level* level) {
    std::vector<Node*> nodes;

    // Platforms
    for(auto plat : level->platforms) {
        Node* node = new Node();
        node->x = plat->position.x;
        node->y = plat->position.y;
        node->safe = !plat->spike; // true if no spike
        parsePlatform(node, plat);
        nodes.push_back(node);
    }

    // Orbs
    for(auto orb : level->orbs) {
        Node* closestNode = nullptr;
        float minDist = 99999.f;

        // Assign orb to closest node
        for(auto node : nodes) {
            float dx = node->x - orb->position.x;
            float dy = node->y - orb->position.y;
            float dist = dx*dx + dy*dy;
            if(dist < minDist) {
                minDist = dist;
                closestNode = node;
            }
        }

        if(closestNode) parseOrb(closestNode, orb);
    }

    // Portals
    for(auto portal : level->portals) {
        Node* closestNode = nullptr;
        float minDist = 99999.f;

        for(auto node : nodes) {
            float dx = node->x - portal->position.x;
            float dy = node->y - portal->position.y;
            float dist = dx*dx + dy*dy;
            if(dist < minDist) {
                minDist = dist;
                closestNode = node;
            }
        }

        if(closestNode) parsePortal(closestNode, portal);
    }

    return nodes;
}

void LevelParser::parsePlatform(Node* node, void* platform) {
    // Could add moving platform logic here later
}

void LevelParser::parseOrb(Node* node, void* orb) {
    std::string type = *(std::string*)((uintptr_t)orb + 0x10); // example offset
    if(type == "yellow") node->jumpOrb = true;
    else if(type == "pink") node->highJumpOrb = true;
    else if(type == "red") node->gravityOrb = true;
    else if(type == "green") node->dashOrb = true;
}

void LevelParser::parsePortal(Node* node, void* portal) {
    Portal* p = new Portal();
    p->x = *(float*)((uintptr_t)portal + 0x00); // example offsets
    p->y = *(float*)((uintptr_t)portal + 0x04);
    std::string typeStr = *(std::string*)((uintptr_t)portal + 0x08);

    if(typeStr == "Ship") p->type = LevelType::Ship;
    else if(typeStr == "Wave") p->type = LevelType::Wave;
    else if(typeStr == "UFO") p->type = LevelType::UFO;
    else if(typeStr == "Ball") p->type = LevelType::Ball;
    else if(typeStr == "Robot") p->type = LevelType::Robot;
    else if(typeStr == "Spider") p->type = LevelType::Spider;
    else p->type = LevelType::Unknown;

    node->portals.push_back(p);
}
