#ifndef __TABLE_H
#define __TABLE_H

#define __BEGIN_NAMESPACE_15_PAZZLE namespace pazzle15 {
#define __END_NAMESPACE_15_PAZZLE }
#define __USING_NAMESPACE_15_PAZZLE using namespace pazzle15;

__BEGIN_NAMESPACE_15_PAZZLE

class Table
{
public:
    explicit Table();
    virtual ~Table();
    void init();
    void randomize(int s);
    void printTable();
    void moveNumber(int i);
    int getState();
    int find(int t);
    
private:
    bool canMove(int i);
    void move(int i);
    inline int findZero() {
	return find(0);
    }
    int mTable[16];
};

__END_NAMESPACE_15_PAZZLE

#endif //__TABLE_H
