struct Node {
    float x, y;
    bool safe;
    bool hasJumpOrb = false;
    bool hasHighJumpOrb = false;
    bool hasGravityOrb = false;
    bool hasDashOrb = false;
    std::vector<Node*> reachable;
    std::vector<Portal*> portals;
};

class LevelParser {
public:
    std::vector<Node*> parseLevel(Level* level);
};struct Node {
    float x, y;
    bool safe;
    bool hasJumpOrb = false;
    bool hasHighJumpOrb = false;
    bool hasGravityOrb = false;
    bool hasDashOrb = false;
    std::vector<Node*> reachable;
    std::vector<Portal*> portals;
};

class LevelParser {
public:
    std::vector<Node*> parseLevel(Level* level);
};
