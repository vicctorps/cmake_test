
#ifndef _myMetadata
#define _myMetadata

#include <TObject.h>

class Myclass : public TObject {
private:
    // Define here your metadata members
    Int_t fDummy;

public:
    // You can define methods to access your metadata
    // members here
    Int_t GetDummyValue() { return fDummy; }

    void SetDummyValue(Int_t value) { fDummy = value; }

    // Constructors
    Myclass();
    // Destructor
    ~Myclass();

    ClassDef(Myclass, 1);
};
#endif
