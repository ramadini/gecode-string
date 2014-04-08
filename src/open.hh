/*
This File has been generated by the indexical compiler,
written by JN Monette @ Uppsala University.
Please avoid modifying this file directly...
*/
#include "gecode/driver.hh"
#include "gecode/int.hh"
#include "gecode/iter.hh" 

using namespace Gecode;

 
#ifndef OPEN_PROPS_HH
#define OPEN_PROPS_HH
namespace Gecode { namespace Open { namespace CharacterAt {
class CharacterAt : public Propagator {
protected:
	ViewArray<Int::IntView> X;
	Int::IntView Xn;
	Int::IntView C;
	Int::IntView Index;
public:
	CharacterAt(Home home, ViewArray<Int::IntView> _X, Int::IntView _Xn, Int::IntView _C, Int::IntView _Index);
	CharacterAt(Home home, bool share, CharacterAt& p);
	virtual size_t dispose(Space& home);
	static ExecStatus post(Space& home, ViewArray<Int::IntView> X, Int::IntView Xn, Int::IntView C, Int::IntView Index);
	virtual ExecStatus propagate(Space& home, const Gecode::ModEventDelta& med);

	virtual Propagator* copy(Space& home, bool share){
		return new (home) CharacterAt(home,share, *this);	
	}
	virtual PropCost cost(const Space& home, const ModEventDelta& med) const{
		return PropCost::linear(PropCost::LO,(X).size());
	}

};

enum Propag {OPEN_char_avvvv_gen};
}}}

/*
 functions used to post the constraint.
 generated.
*/
void characterat(Home home, IntVarArgs _X, IntVar _Xn, IntVar _C, IntVar _Index, IntConLevel icl);
void characterat(Home home, IntVarArgs _X, IntVar _Xn, IntVar _C, IntVar _Index, Open::CharacterAt::Propag _prop);

namespace Gecode { namespace Open { namespace Concat {
class Concat : public Propagator {
protected:
	ViewArray<Int::IntView> X;
	Int::IntView Xn;
	ViewArray<Int::IntView> Y;
	Int::IntView Yn;
	ViewArray<Int::IntView> Z;
	Int::IntView Zn;
public:
	Concat(Home home, ViewArray<Int::IntView> _X, Int::IntView _Xn, ViewArray<Int::IntView> _Y, Int::IntView _Yn, ViewArray<Int::IntView> _Z, Int::IntView _Zn);
	Concat(Home home, bool share, Concat& p);
	virtual size_t dispose(Space& home);
	static ExecStatus post(Space& home, ViewArray<Int::IntView> X, Int::IntView Xn, ViewArray<Int::IntView> Y, Int::IntView Yn, ViewArray<Int::IntView> Z, Int::IntView Zn);
	virtual ExecStatus propagate(Space& home, const Gecode::ModEventDelta& med);

	virtual Propagator* copy(Space& home, bool share){
		return new (home) Concat(home,share, *this);	
	}
	virtual PropCost cost(const Space& home, const ModEventDelta& med) const{
		return PropCost::linear(PropCost::LO,Yn.size()+(Y).size());
	}

};

enum Propag {OPEN_concat_avvavvavv_gen};
}}}//end of namespace OPEN_concat_avvavvavv

/*
 functions used to post the constraint.
 generated.
*/
void concat(Home home, IntVarArgs _X, IntVar _Xn, IntVarArgs _Y, IntVar _Yn, IntVarArgs _Z, IntVar _Zn, IntConLevel icl);
void concat(Home home, IntVarArgs _X, IntVar _Xn, IntVarArgs _Y, IntVar _Yn, IntVarArgs _Z, IntVar _Zn, Open::Concat::Propag _prop);

namespace Gecode { namespace Open { namespace Equal {
class Equal : public Propagator {
protected:
	ViewArray<Int::IntView> X;
	Int::IntView Xn;
	ViewArray<Int::IntView> Y;
	Int::IntView Yn;
public:
	Equal(Home home, ViewArray<Int::IntView> _X, Int::IntView _Xn, ViewArray<Int::IntView> _Y, Int::IntView _Yn);
	Equal(Home home, bool share, Equal& p);
	virtual size_t dispose(Space& home);
	static ExecStatus post(Space& home, ViewArray<Int::IntView> X, Int::IntView Xn, ViewArray<Int::IntView> Y, Int::IntView Yn);
	virtual ExecStatus propagate(Space& home, const Gecode::ModEventDelta& med);

	virtual Propagator* copy(Space& home, bool share){
		return new (home) Equal(home,share, *this);	
	}
	virtual PropCost cost(const Space& home, const ModEventDelta& med) const{
		return PropCost::linear(PropCost::LO,Yn.size()+(Y).size());
	}

};

enum Propag {OPEN_equal_avvavv_gen};
}}}//end of namespace OPEN_equal_avvavv

/*
 functions used to post the constraint.
 generated.
*/
void equal(Home home, IntVarArgs _X, IntVar _Xn, IntVarArgs _Y, IntVar _Yn, IntConLevel icl);
void equal(Home home, IntVarArgs _X, IntVar _Xn, IntVarArgs _Y, IntVar _Yn, Open::Equal::Propag _prop);

namespace Gecode { namespace Open { namespace Substring {
class Substring : public Propagator {
protected:
	ViewArray<Int::IntView> X;
	Int::IntView Xn;
	ViewArray<Int::IntView> Y;
	Int::IntView Yn;
	Int::IntView Index;
public:
	Substring(Home home, ViewArray<Int::IntView> _X, Int::IntView _Xn, ViewArray<Int::IntView> _Y, Int::IntView _Yn, Int::IntView _Index);
	Substring(Home home, bool share, Substring& p);
	virtual size_t dispose(Space& home);
	static ExecStatus post(Space& home, ViewArray<Int::IntView> X, Int::IntView Xn, ViewArray<Int::IntView> Y, Int::IntView Yn, Int::IntView Index);
	virtual ExecStatus propagate(Space& home, const Gecode::ModEventDelta& med);

	virtual Propagator* copy(Space& home, bool share){
		return new (home) Substring(home,share, *this);	
	}
	virtual PropCost cost(const Space& home, const ModEventDelta& med) const{
		return PropCost::linear(PropCost::LO,Yn.size()+(Y).size());
	}

};

enum Propag {OPEN_substr_avvavvv_gen};
}}}//end of namespace OPEN_substr_avvavvv

/*
 functions used to post the constraint.
 generated.
*/
void substring(Home home, IntVarArgs _X, IntVar _Xn, IntVarArgs _Y, IntVar _Yn, IntVar _Index, IntConLevel icl);
void substring(Home home, IntVarArgs _X, IntVar _Xn, IntVarArgs _Y, IntVar _Yn, IntVar _Index, Open::Substring::Propag _prop);
#endif