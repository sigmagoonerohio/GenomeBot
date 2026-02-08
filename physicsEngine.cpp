class PhysicsEngine {
public:
    void applyJump(Node* current, Node* next, LevelType type);
    void applyOrbEffects(Node* node, LevelType& type, float& jumpHeight, float& speed);
    void applyPortalEffects(Node* node, LevelType& type);
};
