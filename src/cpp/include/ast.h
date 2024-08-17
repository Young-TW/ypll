#include <string>
#include <vector>

class AST {
public:
    virtual ~AST() = default;
    virtual void print() = 0;
    virtual void generate() = 0;

    virtual void add(AST* node) = 0;
    virtual void remove(AST* node) = 0;
    virtual AST* getChild(int index) = 0;

    virtual std::string getValue() = 0;
    virtual void setValue(std::string value) = 0;

private:
    AST* parent;
    std::vector<AST*> children;
    std::string value;
};